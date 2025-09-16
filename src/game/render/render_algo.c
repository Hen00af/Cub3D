/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:13:48 by nando             #+#    #+#             */
/*   Updated: 2025/09/16 11:47:22 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	calculate_ray_direction(t_game_data *g, int x)
{
	double	camera_x;

	//カメラ空間のX座標を正規化したやつ
	camera_x = 2.0 * x / (double)WIN_W - 1.0;
	//光線のベクトルを算出
	g->dda.ray.dir_x = g->player.dir_x + g->player.plane_x * camera_x;
	g->dda.ray.dir_y = g->player.dir_y + g->player.plane_y * camera_x;
}

void	dda(t_game_data *g)
{
	// init_dda
	g->dda.map_x = (int)g->player.pos_x;
	g->dda.map_y = (int)g->player.pos_y;
	if (g->dda.ray.dir_x == 0.0)
		g->dda.delta_dist_x = INFINITY;
	else
		g->dda.delta_dist_x = fabs(1 / g->dda.ray.dir_x);
	if (g->dda.ray.dir_y == 0.0)
		g->dda.delta_dist_y = INFINITY;
	else
		g->dda.delta_dist_y = fabs(1 / g->dda.ray.dir_y);
	// step and side_dist
	if (g->dda.ray.dir_x < 0)
	{
		g->dda.step_x = -1;
		g->dda.side_dist_x = (g->player.pos_x - g->dda.map_x);
	}
	else
	{
		g->dda.step_x = 1;
		g->dda.side_dist_x = (g->dda.map_x + 1.0 - g->player.pos_x);
	}
	if (g->dda.ray.dir_y < 0)
	{
		g->dda.step_x = -1;
		g->dda.side_dist_y = (g->player.pos_y - g->dda.map_y);
	}
	else
	{
		g->dda.step_x = 1;
		g->dda.side_dist_y = (g->dda.map_y + 1.0 - g->player.pos_y);
	}
}
