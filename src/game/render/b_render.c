/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:55:31 by nando             #+#    #+#             */
/*   Updated: 2025/10/17 16:57:47 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <sys/time.h>

#define TILE_SIZE 8
#define COLOR_WHITE 0xFFFFFF
#define COLOR_BLACK 0x000000
#define COLOR_RED 0xFF0000
#define COLOR_YELLOW 0xFFFF00

/* ---------------------------------------------------------
** 1マス分（TILE_SIZE x TILE_SIZE）を塗る関数
** --------------------------------------------------------- */
static void	draw_minimap_pixel_block(t_game *g, t_bonus *b, int color)
{
	b->py = 0;
	while (b->py < TILE_SIZE)
	{
		b->px = 0;
		while (b->px < TILE_SIZE)
		{
			b->screen_x = b->map_x * TILE_SIZE + b->px;
			b->screen_y = b->map_y * TILE_SIZE + b->py;
			if (b->screen_x >= 0 && b->screen_x < WIN_W && b->screen_y >= 0
				&& b->screen_y < WIN_H)
				put_pixel_to_canvas(&g->render.img, b->screen_x, b->screen_y,
					color);
			b->px++;
		}
		b->py++;
	}
}

/* ---------------------------------------------------------
** マップ全体を描画
** --------------------------------------------------------- */
static void	draw_minimap_tiles(t_game *g, t_bonus *b)
{
	b->map_y = 0;
	while (g->world.map[b->map_y])
	{
		b->map_x = 0;
		while (g->world.map[b->map_y][b->map_x])
		{
			b->tile = g->world.map[b->map_y][b->map_x];
			if (b->tile == '1')
				b->color = COLOR_WHITE;
			else
				b->color = COLOR_BLACK;
			draw_minimap_pixel_block(g, b, b->color);
			b->map_x++;
		}
		b->map_y++;
	}
}

/* ---------------------------------------------------------
** プレイヤー位置を赤点で描画
** --------------------------------------------------------- */
static void	draw_minimap_player(t_game *g, t_bonus *b)
{
	int	x;
	int	y;

	b->player_map_x = (int)(g->player.pos_x * TILE_SIZE);
	b->player_map_y = (int)(g->player.pos_y * TILE_SIZE);
	b->py2 = -2;
	while (b->py2 <= 2)
	{
		b->px2 = -2;
		while (b->px2 <= 2)
		{
			x = b->player_map_x + b->px2;
			y = b->player_map_y + b->py2;
			if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
				put_pixel_to_canvas(&g->render.img, x, y, COLOR_RED);
			b->px2++;
		}
		b->py2++;
	}
}

/* ---------------------------------------------------------
** プレイヤーの向きを黄色線で描画
** --------------------------------------------------------- */
static void	draw_minimap_direction(t_game *g, t_bonus *b)
{
	int	x;
	int	y;

	b->dir_len = 10;
	b->i = 0;
	while (b->i < b->dir_len)
	{
		b->dx = (int)(g->player.dir_vec_x * b->i);
		b->dy = (int)(g->player.dir_vec_y * b->i);
		x = b->player_map_x + b->dx;
		y = b->player_map_y + b->dy;
		if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
			put_pixel_to_canvas(&g->render.img, x, y, COLOR_YELLOW);
		b->i++;
	}
}

/* ---------------------------------------------------------
** ミニマップ全体の描画（呼び出し側）
** --------------------------------------------------------- */
void	b_render_minimap(t_game *g)
{
	t_bonus	b;

	draw_minimap_tiles(g, &b);
	draw_minimap_player(g, &b);
	draw_minimap_direction(g, &b);
}
