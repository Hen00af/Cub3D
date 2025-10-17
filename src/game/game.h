/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:12:53 by nando             #+#    #+#             */
/*   Updated: 2025/10/17 16:58:03 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>

# define WIN_W 960
# define WIN_H 720

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
# define FALSE 0
# define TRUE 1

# ifdef BONUS
#  define IS_BONUS_MODE 1
# else
#  define IS_BONUS_MODE 0
# endif

typedef struct s_image_data
{
	void			*canvas;
	char			*address;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				height;
	int				width;
}					t_image_data;

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
	double			old_vec_x;
	double			old_vec_y;
	double			old_plane_x;
	double			old_plane_y;
}					t_player;

// world data used game_dir
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

// raycasting
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

typedef struct s_textures
{
	t_image_data	north;
	t_image_data	south;
	t_image_data	east;
	t_image_data	west;
}					t_textures;

typedef struct s_wall_design
{
	double			wall_x;
	int				tex_x;
	int				tex_y;
	double			tex_step;
	double			tex_pos;
	int				y;
	int				color;
}					t_wall_design;

typedef struct s_render
{
	t_image_data	img;
	t_textures		textures;
	t_ray			ray;
	double			perp_wall_dist;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				side;
}					t_render;

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
	int				is_bonus;
	t_world_data	world;
	t_player		player;
	t_render		render;
}					t_game;

typedef struct s_bonus
{
	int				map_x;
	int				map_y;
	int				screen_x;
	int				screen_y;
	int				color;
	char			tile;
	int				player_map_x;
	int				player_map_y;
	int				dir_len;
	int				dx;
	int				dy;
	int				px;
	int				py;
	int				i;
	int				px2;
	int				py2;
}					t_bonus;

t_image_data		*select_texture(t_game *g);
void				init_game(t_game *g);
void				move_right(t_game *g);
void				move_left(t_game *g);
void				move_back(t_game *g);
void				move_forward(t_game *g);
void				move(t_game *g, int keycode);
int					handle_key_press(int keycode, t_game *game);
int					close_window(t_game *g);
void				calculate_ray(t_ray *r, t_player *p, int x);
void				calculate_the_wall_height(t_render *r, t_game *g);
void				calcurate_perp_wall_dist(t_game *g, t_dda *dda);
void				load_texture(t_game *game, const char *file_path,
						t_image_data *texture);
void				load_all_textures(t_game *game);
void				put_pixel_to_canvas(t_image_data *img, int x, int y,
						int color);
void				rendering_ceiling_and_floor(t_game *g, t_world_data *data);
void				rendering_walls(t_game *game);
void				init_dda(t_game *g, t_dda *dda);
void				dda_loop(t_game *g, t_dda *dda);
void				dda(t_game *g);
int					execute_game(t_game *game);

// bonus
void				b_render_minimap(t_game *g);

#endif