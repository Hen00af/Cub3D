/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:12:29 by nando             #+#    #+#             */
/*   Updated: 2025/10/17 15:12:32 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

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
	if (keycode == KEY_RIGHT)
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
	else if (keycode == KEY_LEFT)
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

int	handle_key_press(int keycode, t_game *g, t_world_data *data)
{
	(void)data;
	if (keycode == ESC_KEY)
		return (close_window(g));
	else if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A
		|| keycode == KEY_D)
		move(g, keycode);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		rotate(&g->player, keycode);
	return (0);
}
