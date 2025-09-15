# raycast.py
# Minimal ray casting 3D demo in Python + pygame
# by ChatGPT — single file, no textures (flat shading)

import math
import sys
import pygame

# ----------------------------
# 基本設定
# ----------------------------
WIDTH, HEIGHT = 900, 600           # 画面サイズ
FOV = math.radians(50)              # 視野角（自然な広さ）
HALF_FOV = FOV / 2
NUM_RAYS = WIDTH // 2               # レイ本数を半分に（軽量化）
MAX_DEPTH = 20.0                    # レイの最大到達距離（タイル数）
WALL_HEIGHT = 1.0                   # 壁の仮想高さ
MOVE_SPEED = 4.0                    # タイル/秒（FOVに合わせて調整）
ROT_SPEED = math.radians(120)       # deg/sec → rad/sec

CEIL_COLOR = (30, 30, 40)
FLOOR_COLOR = (40, 40, 50)
WALL_BASE_COLOR = (220, 220, 220)

MINIMAP_SCALE = 12                  # ミニマップ描画スケール

# ----------------------------
# マップ（"#"=壁, "."=空間）
# ----------------------------
MAP_STR = [
    "############",
    "#..........#",
    "#..##......#",
    "#..#.......#",
    "#..#..###..#",
    "#..#.......#",
    "#..####....#",
    "#..........#",
    "#......##..#",
    "#..........#",
    "############",
]
MAP_H = len(MAP_STR)
MAP_W = len(MAP_STR[0])

def is_wall(x, y):
    """ワールド座標（浮動小数）→タイル座標に変換して壁か判定"""
    if x < 0 or y < 0:
        return True
    tx, ty = int(x), int(y)
    if ty < 0 or ty >= MAP_H or tx < 0 or tx >= MAP_W:
        return True
    return MAP_STR[ty][tx] == "#"

# ----------------------------
# プレイヤー初期位置
# ----------------------------
player_x, player_y = 2.5, 2.5    # タイル座標系
player_a = math.radians(20)      # 視線角
player_z = 0.5                   # 高さ（0.5 = 床から半分の高さ）
player_z_vel = 0.0               # 垂直速度
JUMP_SPEED = 3                  # ジャンプ力（自然な高さ）
GRAVITY = 9.8                    # 重力（ぷちジャンプ）
GROUND_LEVEL = -10               # 地面の高さ

# ----------------------------
# レイキャスト（DDA）
# ----------------------------
def cast_ray(px, py, angle):
    """
    DDA（Digital Differential Analyzer）で壁までの距離を返す。
    返り値: 距離, ヒット面の向き(0:x面/1:y面), ヒット座標
    """
    # レイ方向ベクトル
    dx = math.cos(angle)
    dy = math.sin(angle)

    # 現在位置を含むタイル
    map_x = int(px)
    map_y = int(py)

    # 1タイル進むときのtの増分
    delta_dist_x = abs(1.0 / dx) if dx != 0 else 1e30
    delta_dist_y = abs(1.0 / dy) if dy != 0 else 1e30

    # ステップ方向と最初の境界までの距離
    if dx < 0:
        step_x = -1
        side_dist_x = (px - map_x) * delta_dist_x
    else:
        step_x = 1
        side_dist_x = (map_x + 1.0 - px) * delta_dist_x

    if dy < 0:
        step_y = -1
        side_dist_y = (py - map_y) * delta_dist_y
    else:
        step_y = 1
        side_dist_y = (map_y + 1.0 - py) * delta_dist_y

    hit = False
    side = 0

    # DDA ループ
    depth = 0.0
    while not hit and depth < MAX_DEPTH:
        if side_dist_x < side_dist_y:
            side_dist_x += delta_dist_x
            map_x += step_x
            side = 0  # x面に当たった（左右の壁）
        else:
            side_dist_y += delta_dist_y
            map_y += step_y
            side = 1  # y面に当たった（上下の壁）

        if map_y < 0 or map_y >= MAP_H or map_x < 0 or map_x >= MAP_W:
            break

        if MAP_STR[map_y][map_x] == "#":
            hit = True

    # 壁までの距離（射影歪み補正なしのraw）
    if side == 0:
        # 最後にx面へ進んだ → x方向の距離を算出
        # 進んだ回数分の差分から逆算
        perp_dist = (side_dist_x - delta_dist_x)
    else:
        perp_dist = (side_dist_y - delta_dist_y)

    # 壁に当たらない場合はMAX扱い
    if not hit or perp_dist <= 0:
        perp_dist = MAX_DEPTH

    # レイの衝突座標（近似、視覚には不要）
    hit_x = px + math.cos(angle) * perp_dist
    hit_y = py + math.sin(angle) * perp_dist

    return perp_dist, side, (hit_x, hit_y)

# ----------------------------
# 描画
# ----------------------------
def shade(color, factor):
    """簡易シェーディング"""
    r, g, b = color
    k = max(0.0, min(1.0, factor))
    return (int(r * k), int(g * k), int(b * k))

def draw_minimap(surf, px, py):
    # 地図
    for my in range(MAP_H):
        for mx in range(MAP_W):
            c = (80, 80, 90) if MAP_STR[my][mx] == "#" else (25, 25, 30)
            pygame.draw.rect(
                surf,
                c,
                pygame.Rect(mx * MINIMAP_SCALE, my * MINIMAP_SCALE, MINIMAP_SCALE, MINIMAP_SCALE),
            )
    # プレイヤー
    pygame.draw.circle(
        surf,
        (255, 80, 80),
        (int(px * MINIMAP_SCALE), int(py * MINIMAP_SCALE)),
        4,
    )

def main():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("consolas", 16)

    global player_x, player_y, player_a, player_z, player_z_vel

    running = True
    while running:
        dt = clock.tick(60) / 1000.0  # 秒
        for e in pygame.event.get():
            if e.type == pygame.QUIT:
                running = False
            if e.type == pygame.KEYDOWN and e.key == pygame.K_ESCAPE:
                running = False

        # 入力
        keys = pygame.key.get_pressed()
        # 回転
        if keys[pygame.K_LEFT]:
            player_a -= ROT_SPEED * dt
        if keys[pygame.K_RIGHT]:
            player_a += ROT_SPEED * dt
        
        # ジャンプ（スペースキー）
        if keys[pygame.K_SPACE] and player_z <= GROUND_LEVEL:
            player_z_vel = JUMP_SPEED

        # 平行移動（A/D）& 前後（W/S）
        sin_a = math.sin(player_a)
        cos_a = math.cos(player_a)
        nx, ny = player_x, player_y

        if keys[pygame.K_w]:
            nx += cos_a * MOVE_SPEED * dt
            ny += sin_a * MOVE_SPEED * dt
        if keys[pygame.K_s]:
            nx -= cos_a * MOVE_SPEED * dt
            ny -= sin_a * MOVE_SPEED * dt
        if keys[pygame.K_a]:  # 左ストレイフ
            nx -= -sin_a * MOVE_SPEED * dt
            ny -=  cos_a * MOVE_SPEED * dt
        if keys[pygame.K_d]:  # 右ストレイフ
            nx -=  sin_a * MOVE_SPEED * dt
            ny -= -cos_a * MOVE_SPEED * dt

        # 簡易衝突（壁なら位置を戻す）
        if not is_wall(nx, player_y):
            player_x = nx
        if not is_wall(player_x, ny):
            player_y = ny
        
        # 重力とジャンプの物理演算
        player_z_vel -= GRAVITY * dt  # 重力で下向きに加速
        player_z += player_z_vel * dt  # 速度で位置更新
        
        # 地面に着地
        if player_z <= GROUND_LEVEL:
            player_z = GROUND_LEVEL
            player_z_vel = 0.0

        # 背景（天井/床）
        screen.fill(CEIL_COLOR)
        pygame.draw.rect(screen, FLOOR_COLOR, pygame.Rect(0, HEIGHT // 2, WIDTH, HEIGHT // 2))

        # レイキャスト＆壁描画
        # カメラ平面補正：列ごとに視線からのオフセット角を与える
        inv_tan = 1.0 / math.tan(HALF_FOV)  # 投影計算用定数
        
        for col in range(NUM_RAYS):
            # 正規化されたスクリーン座標 [-1, +1]
            x = (2 * col / NUM_RAYS) - 1.0
            ray_angle = player_a + x * HALF_FOV * 2  # 単純線形でOK（FOV幅に合わせる）

            dist, side, _ = cast_ray(player_x, player_y, ray_angle)

            # 魚眼補正：視線中心からの角度差で割る
            dist *= math.cos(ray_angle - player_a)
            dist = max(0.0001, dist)

            # 投影：距離に反比例した壁の高さ（プレイヤーの高さも考慮）
            proj_h = int((WALL_HEIGHT / dist) * (HEIGHT / (2 * math.tan(HALF_FOV))))
            
            # プレイヤーの高さによる視点の変化（距離で減衰）
            height_offset = int(((player_z - GROUND_LEVEL) / dist) * (HEIGHT * 0.5 * inv_tan))
            # 過剰なシフトを抑制
            height_offset = max(-HEIGHT//3, min(HEIGHT//3, height_offset))

            # シェーディング（距離と面で減衰）
            shade_k = 1.0 / (1.0 + dist * 0.25)
            if side == 1:
                shade_k *= 0.8
            color = shade(WALL_BASE_COLOR, shade_k)

            # 垂直スライスを描画（2px幅で軽量化）
            x_screen = col * 2
            y1 = HEIGHT // 2 - proj_h // 2 + height_offset
            y2 = y1 + proj_h
            pygame.draw.line(screen, color, (x_screen, y1), (x_screen, y2), 2)

        # ミニマップ
        minimap = pygame.Surface((MAP_W * MINIMAP_SCALE, MAP_H * MINIMAP_SCALE))
        draw_minimap(minimap, player_x, player_y)
        screen.blit(minimap, (10, 10))

        # HUD
        info = f"pos=({player_x:.2f},{player_y:.2f},{player_z:.2f})  ang={math.degrees(player_a)%360:5.1f}  FPS={clock.get_fps():.1f}"
        screen.blit(font.render(info, True, (220, 220, 220)), (10, 10 + MAP_H * MINIMAP_SCALE + 8))
        
        # ジャンプ状態表示
        jump_info = f"Jump: {'ON AIR' if player_z > GROUND_LEVEL else 'GROUND'}  Height: {player_z:.2f}"
        screen.blit(font.render(jump_info, True, (220, 220, 100)), (10, 10 + MAP_H * MINIMAP_SCALE + 28))

        pygame.display.flip()

    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()
