/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:24:51 by nando             #+#    #+#             */
/*   Updated: 2025/10/17 16:25:45 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	init_player_posi(t_game *g, t_dda *dda)
{
	dda->map_x = (int)g->player.pos_x;
	dda->map_y = (int)g->player.pos_y;
}

static void	init_deltadist(t_game *g, t_dda *dda)
{
	if (g->render.ray.dir_x == 0)
		dda->delta_dist_x = 1e30;
	else
		dda->delta_dist_x = fabs(1 / g->render.ray.dir_x);
	if (g->render.ray.dir_y == 0)
		dda->delta_dist_y = 1e30;
	else
		dda->delta_dist_y = fabs(1 / g->render.ray.dir_y);
}

static void	init_sidedist_and_step(t_game *g, t_dda *dda)
{
	if (g->render.ray.dir_x < 0)
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
	if (g->render.ray.dir_y < 0)
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

void	init_dda(t_game *g, t_dda *dda)
{
	dda->hit = 0;
	init_player_posi(g, dda);
	init_deltadist(g, dda);
	init_sidedist_and_step(g, dda);
}
