/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:13:48 by nando             #+#    #+#             */
/*   Updated: 2025/09/30 18:22:23 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	calculate_ray(t_game_data *g, int x)
{
	double	camera_x;

	//カメラ空間のX座標を正規化したやつ
	camera_x = 2.0 * x / (double)WIN_W - 1.0;
	//光線のベクトルを算出
	g->ray.dir_x = g->player.dir_vec_x + g->player.plane_x * camera_x;
	g->ray.dir_y = g->player.dir_vec_y + g->player.plane_y * camera_x;
}

// Init player position
void	init_player_posi(t_game_data *g, t_dda *dda)
{
	dda->map_x = (int)g->player.pos_x;
	dda->map_y = (int)g->player.pos_y;
}

// Calculating the distance when moving one square in each direction
void	init_deltadist(t_game_data *g, t_dda *dda)
{
	if (g->ray.dir_x == 0)
		dda->delta_dist_x = 1e30;
	else
		dda->delta_dist_x = fabs(1 / g->ray.dir_x);
	if (g->ray.dir_y == 0)
		dda->delta_dist_y = 1e30;
	else
		dda->delta_dist_y = fabs(1 / g->ray.dir_y);
}

// Calculating the istance to the first vertical line and ray direction
void	init_sidedist_and_step(t_game_data *g, t_dda *dda)
{
	if (g->ray.dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (g->player.pos_x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - g->player.pos_x)
			* dda->delta_dist_x;
	}
	if (g->ray.dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (g->player.pos_y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - g->player.pos_y)
			* dda->delta_dist_y;
	}
}

void	init_dda(t_game_data *g, t_dda *dda)
{
	dda->hit = 0;
	init_player_posi(g, dda);
	init_deltadist(g, dda);
	init_sidedist_and_step(g, dda);
}

void	dda_loop(t_game_data *g, t_dda *dda)
{
	while (dda->hit == 0)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (g->map[dda->map_y][dda->map_x] == '1')
			dda->hit = 1;
	}
	printf("ray=(%f,%f) map=(%d,%d) side=%d\n", g->ray.dir_x, g->ray.dir_y,
		dda->map_x, dda->map_y, dda->side);
}

void	calcurate_perp_wall_dist(t_game_data *g, t_dda *dda)
{
	printf("dda->side = %d\n", dda->side);
	printf("dda->side_dist_x = %f\n", dda->side_dist_x);
	printf("dda->delta-dist_x = %f\n", dda->delta_dist_x);
	if (dda->side == 0)
	{
		printf("dda->side_dist_x = %f\n", dda->side_dist_x);
		printf("dda->delta-dist_x = %f\n", dda->delta_dist_x);
		g->perp_wall_dist = (dda->side_dist_x - dda->delta_dist_x);
	}
	else
	{
		printf("dda->side_dist_y = %f\n", dda->side_dist_y);
		printf("dda->delta-dist_y = %f\n", dda->delta_dist_y);
		g->perp_wall_dist = (dda->side_dist_y - dda->delta_dist_y);
	}
}

void	calculate_the_wall_height(t_game_data *g)
{
	printf("perp_wall = %f\n", g->perp_wall_dist);
	if (g->perp_wall_dist <= 0.00001) // 安全ガード
		g->perp_wall_dist = 0.00001;
	g->line_height = (int)(WIN_H / g->perp_wall_dist);
	printf("line_height = %d\n", g->line_height);
	g->draw_start = -g->line_height / 2 + WIN_H / 2;
	if (g->draw_start < 0)
		g->draw_start = 0;
	g->draw_end = g->line_height / 2 + WIN_H / 2;
	if (g->draw_end >= WIN_H)
		g->draw_end = WIN_H - 1;
}

void	dda(t_game_data *g)
{
	t_dda	dda;

	init_dda(g, &dda);
	dda_loop(g, &dda);
	calcurate_perp_wall_dist(g, &dda);
	return ;
}
