#ifndef GAME_H
# define GAME_H

# include "../../lib/cub3D.h"
# include "../../minilibx-linux/mlx.h"
# include "../../src/parse/parse.h"
# include <math.h>

// ウィンドウとキーの定数
# define WIN_W 960
# define WIN_H 720

# define CEILING_COLOR 0x87CEEB
# define FLOOR_COLOR 0x8B4513
# define WALL_COLOR 0x808080

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
	double			pos_x;
	double			pos_y;
	double			dir_vec_x;
	double			dir_vec_y;
	double			plane_x;
	double			plane_y;
}					t_player;

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

// ゲームデータ構造体
typedef struct s_game_data
{
	void			*mlx;
	void			*win;
	char			**map;
	t_player		player;
	t_ray			ray;
	t_image_data	img;
	double			perp_wall_dist;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_game_data;

// 関数プロトタイプ
void				init_game(t_game_data *game, t_data *data);
void				calculate_ray(t_game_data *g, int x);
void				dda(t_game_data *g);
void				put_pixel_to_canvas(t_image_data *img, int x, int y,
						int color);
void				rendering_ceiling_and_floor(t_game_data *g, t_data *data);
void				calculate_the_wall_height(t_game_data *g);
void				rendering_wall_slice(t_game_data *g, int x);
void				rendering_walls(t_game_data *game);
void				move_right(t_game_data *g);
void				move_left(t_game_data *g);
void				move_back(t_game_data *g);
void				move_forward(t_game_data *g);
void				move(t_game_data *g, int keycode);
int					handle_key_press(int keycode, t_game_data *game,
						t_data *data);
int					close_window(t_game_data *g);
void				init_player_posi(t_game_data *g, t_dda *dda);
void				init_deltadist(t_game_data *g, t_dda *dda);
void				init_sidedist_and_step(t_game_data *g, t_dda *dda);
void				init_dda(t_game_data *g, t_dda *dda);
void				dda_loop(t_game_data *g, t_dda *dda);
void				calcurate_perp_wall_dist(t_game_data *g, t_dda *dda);
int					run_game(t_data *data, t_game_data *game);

#endif