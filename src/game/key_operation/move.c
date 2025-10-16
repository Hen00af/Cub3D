/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:11:32 by nando             #+#    #+#             */
/*   Updated: 2025/10/15 23:52:51 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	move_forward(t_game_data *g)
{
	double	new_x;
	double	new_y;

	new_x = 0.0;
	new_y = 0.0;
	new_x = g->player.pos_x + g->player.dir_vec_x * MOVE_SPEED;
	new_y = g->player.pos_y + g->player.dir_vec_y * MOVE_SPEED;
	if (g->map[(int)g->player.pos_y][(int)new_x] != '1')
		g->player.pos_x = new_x;
	if (g->map[(int)new_y][(int)g->player.pos_x] != '1')
		g->player.pos_y = new_y;
}

void	move_back(t_game_data *g)
{
	double	new_x;
	double	new_y;

	new_x = 0.0;
	new_y = 0.0;
	new_x = g->player.pos_x - g->player.dir_vec_x * MOVE_SPEED;
	new_y = g->player.pos_y - g->player.dir_vec_y * MOVE_SPEED;
	if (g->map[(int)g->player.pos_y][(int)new_x] != '1')
		g->player.pos_x = new_x;
	if (g->map[(int)new_y][(int)g->player.pos_x] != '1')
		g->player.pos_y = new_y;
}

void	move_left(t_game_data *g)
{
	double	new_x;
	double	new_y;

	new_x = 0.0;
	new_y = 0.0;
	new_x = g->player.pos_x - g->player.plane_x * MOVE_SPEED;
	new_y = g->player.pos_y - g->player.plane_y * MOVE_SPEED;
	if (g->map[(int)g->player.pos_y][(int)new_x] != '1')
		g->player.pos_x = new_x;
	if (g->map[(int)new_y][(int)g->player.pos_x] != '1')
		g->player.pos_y = new_y;
}

void	move_right(t_game_data *g)
{
	double	new_x;
	double	new_y;

	new_x = 0.0;
	new_y = 0.0;
	new_x = g->player.pos_x + g->player.plane_x * MOVE_SPEED;
	new_y = g->player.pos_y + g->player.plane_y * MOVE_SPEED;
	if (g->map[(int)g->player.pos_y][(int)new_x] != '1')
		g->player.pos_x = new_x;
	if (g->map[(int)new_y][(int)g->player.pos_x] != '1')
		g->player.pos_y = new_y;
}

void	move(t_game_data *g, int keycode)
{
	if (keycode == KEY_W)
		move_forward(g);
	else if (keycode == KEY_S)
		move_back(g);
	else if (keycode == KEY_D)
		move_right(g);
	else if (keycode == KEY_A)
		move_left(g);
}
