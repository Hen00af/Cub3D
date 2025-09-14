/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:40:41 by nando             #+#    #+#             */
/*   Updated: 2025/09/14 19:24:04 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"
#include "../minilibx-Linux/mlx.h"

#define ESC_KEY 65307
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define MOVE_SPEED 0.07
#define ROTATE_SPEED 0.05

void	move(t_player *player, int keycode)
{
	if (keycode == KEY_W)
	{
		player->pos_x += player->dir_vec_x * MOVE_SPEED;
		player->pos_y += player->dir_vec_y * MOVE_SPEED;
	}
	else if (keycode == KEY_S)
	{
		player->pos_x -= player->dir_vec_x * MOVE_SPEED;
		player->pos_y -= player->dir_vec_y * MOVE_SPEED;
	}
	else if (keycode == KEY_A)
	{
		player->pos_x += player->plane_x * MOVE_SPEED;
		player->pos_y += player->plane_y * MOVE_SPEED;
	}
	else if (keycode == KEY_D)
	{
		player->pos_x -= player->plane_x * MOVE_SPEED;
		player->pos_y -= player->plane_y * MOVE_SPEED;
	}
}

void	rotate(t_player *p, int keycode)
{
	double	old_vec_x;
	double	old_vec_y;
	double	old_plane_x;
	double	old_plane_y;

	old_vec_x = p->dir_vec_x;
	old_vec_y = p->dir_vec_y;
	old_plane_x = p->plane_x;
	old_plane_y = p->plane_y;
	if (keycode == KEY_LEFT)
	{
		p->dir_vec_x = old_vec_x * cos(ROTATE_SPEED) - old_vec_y
			* sin(ROTATE_SPEED);
		p->dir_vec_y = old_vec_x * sin(ROTATE_SPEED) + old_vec_y
			* cos(ROTATE_SPEED);
		p->plane_x = old_plane_x * cos(ROTATE_SPEED) - old_plane_y
			* sin(ROTATE_SPEED);
		p->plane_y = old_plane_x * sin(ROTATE_SPEED) + old_plane_y
			* cos(ROTATE_SPEED);
	}
	else if (keycode == KEY_RIGHT)
	{
		p->dir_vec_x = old_vec_x * cos(-ROTATE_SPEED) - old_vec_y
			* sin(-ROTATE_SPEED);
		p->dir_vec_y = old_vec_x * sin(-ROTATE_SPEED) + old_vec_y
			* cos(-ROTATE_SPEED);
		p->plane_x = old_plane_x * cos(-ROTATE_SPEED) - old_plane_y
			* sin(-ROTATE_SPEED);
		p->plane_y = old_plane_x * sin(-ROTATE_SPEED) + old_plane_y
			* cos(-ROTATE_SPEED);
	}
}

int	handle_key_press(int keycode, t_game_data *game)
{
	if (keycode == ESC_KEY)
		return (close_window());
	else if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A
		|| keycode == KEY_D)
		move(&game->player, keycode);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		rotate(&game->player, keycode);
	rendering_ceiling_and_floor(game);
	rendering_walls(game);
	return (0);
}
