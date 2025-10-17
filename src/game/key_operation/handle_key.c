/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:12:29 by nando             #+#    #+#             */
/*   Updated: 2025/10/17 15:53:21 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

static void	rotate_right(t_player *p)
{
	p->dir_vec_x = p->old_vec_x * cos(ROTATE_SPEED) - p->old_vec_y
		* sin(ROTATE_SPEED);
	p->dir_vec_y = p->old_vec_x * sin(ROTATE_SPEED) + p->old_vec_y
		* cos(ROTATE_SPEED);
	p->plane_x = p->old_plane_x * cos(ROTATE_SPEED) - p->old_plane_y
		* sin(ROTATE_SPEED);
	p->plane_y = p->old_plane_x * sin(ROTATE_SPEED) + p->old_plane_y
		* cos(ROTATE_SPEED);
}

static void	rotate_left(t_player *p)
{
	p->dir_vec_x = p->old_vec_x * cos(-ROTATE_SPEED) - p->old_vec_y
		* sin(-ROTATE_SPEED);
	p->dir_vec_y = p->old_vec_x * sin(-ROTATE_SPEED) + p->old_vec_y
		* cos(-ROTATE_SPEED);
	p->plane_x = p->old_plane_x * cos(-ROTATE_SPEED) - p->old_plane_y
		* sin(-ROTATE_SPEED);
	p->plane_y = p->old_plane_x * sin(-ROTATE_SPEED) + p->old_plane_y
		* cos(-ROTATE_SPEED);
}

void	rotate(t_player *p, int keycode)
{
	p->old_vec_x = p->dir_vec_x;
	p->old_vec_y = p->dir_vec_y;
	p->old_plane_x = p->plane_x;
	p->old_plane_y = p->plane_y;
	if (keycode == KEY_RIGHT)
		rotate_right(p);
	else if (keycode == KEY_LEFT)
		rotate_left(p);
}

int	handle_key_press(int keycode, t_game *g)
{
	if (keycode == ESC_KEY)
		return (close_window(g));
	else if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A
		|| keycode == KEY_D)
		move(g, keycode);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		rotate(&g->player, keycode);
	return (0);
}
