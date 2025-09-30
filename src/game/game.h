/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:08:45 by nando             #+#    #+#             */
/*   Updated: 2025/09/30 17:36:34 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "minilibx-Linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define FALSE 0
# define TRUE 1

# define WIN_W 960
# define WIN_H 720

# define CEILING_COLOR 0x87CEEB
# define FLOOR_COLOR 0x8B4513
# define WALL_COLOR 0x808080

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_vec_x;
	double			dir_vec_y;
	double			plane_x;
	double			plane_y;
}					t_player;

typedef struct s_ray
{
	double			dir_x;
	double			dir_y;
}					t_ray;

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

typedef struct s_image_data
{
	void			*canvas;
	char			*data;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_image_data;

typedef struct s_game_data
{
	void			*mlx;
	void			*win;
	t_image_data	img;
	t_player		player;
	t_ray			ray;
	double			perp_wall_dist;
	int				line_height;
	int				draw_start;
	int				draw_end;
	char			**map;
}					t_game_data;

void				init_game(t_game_data *game);
void				calculate_ray(t_game_data *g, int x);
void				dda(t_game_data *g);
void				put_pixel_to_canvas(t_image_data *img, int x, int y,
						int color);
void				rendering_ceiling_and_floor(t_game_data *game);
void				calculate_the_wall_height(t_game_data *g);
void				rendering_wall_slice(t_game_data *g, int x);
void				rendering_walls(t_game_data *game);
int					handle_key_press(int keycode, t_game_data *game);
int					close_window(t_game_data *g);

#endif