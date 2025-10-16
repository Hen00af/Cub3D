#ifndef GAME_H
# define GAME_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>

// ウィンドウとキーの定数
# define WIN_W 960
# define WIN_H 720

# define CEILING_COLOR 0x87CEEB
# define FLOOR_COLOR 0x8B4513
# define WALL_COLOR 0x808080

# define VIEWING_ANGLE 0.66
# define DIR_FORWARD 1
# define DIR_BACKWARD -1
# define DIR_LEFT -1
# define DIR_RIGHT 1

# define ESC_KEY 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define MOVE_SPEED 0.1
# define ROTATE_SPEED 0.05
// 画像データ構造体
typedef struct s_image_data
{
	void			*canvas;
	char			*address;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_image_data;

// プレイヤー構造体
typedef struct s_player
{
	double			player_dir;
	double			player_x;
	double			player_y;
	double			pos_x;
	double			pos_y;
	double			dir_vec_x;
	double			dir_vec_y;
	double			plane_x;
	double			plane_y;
}					t_player;

// gameディレクトリで使用するマップデータファイル
typedef struct s_world
{
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	int				floor_color;
	int				ceiling_color;
	char			**map;
}					t_world_data;

// レイキャスティング用構造体
typedef struct s_ray
{
	double			camera_x;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_ray;

typedef struct s_render
{
	t_image_data	img;
	t_ray			ray;
	double			perp_wall_dist;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_render;

// DDA用構造体
typedef struct s_dda
{
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
}					t_dda;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_world_data world; // parse層から受け取る
	t_player player;    // game層で更新
	t_render render;    // render層で使用
}					t_game;

// 関数プロトタイプ
void				calculate_ray(t_ray *r, t_player *p, int x);
void				init_game(t_game *g);
void				dda(t_game *g);
void				put_pixel_to_canvas(t_image_data *img, int x, int y,
						int color);
void				calculate_the_wall_height(t_render *r, t_game *g);
void				rendering_ceiling_and_floor(t_game *g, t_world_data *data);
void				rendering_wall_slice(t_game *g, int x);
void				rendering_walls(t_game *game);
void				move_right(t_game *g);
void				move_left(t_game *g);
void				move_back(t_game *g);
void				move_forward(t_game *g);
void				move(t_game *g, int keycode);
int					handle_key_press(int keycode, t_game *game,
						t_world_data *data);
int					close_window(t_game *g);
void				init_player_posi(t_game *g, t_dda *dda);
void				init_deltadist(t_game *g, t_dda *dda);
void				init_sidedist_and_step(t_game *g, t_dda *dda);
void				init_dda(t_game *g, t_dda *dda);
void				dda_loop(t_game *g, t_dda *dda);
void				calcurate_perp_wall_dist(t_game *g, t_dda *dda);
void				init_player(t_player *p);
int					execute_game(t_game *game);

#endif