/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:54:37 by nando             #+#    #+#             */
/*   Updated: 2025/10/17 16:24:39 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	dda_loop(t_game *g, t_dda *dda)
{
	while (dda->hit == 0)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			g->render.side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			g->render.side = 1;
		}
		if (g->world.map[dda->map_y][dda->map_x] == '1')
			dda->hit = 1;
	}
}

void	dda(t_game *g)
{
	t_dda	dda;

	init_dda(g, &dda);
	dda_loop(g, &dda);
	calcurate_perp_wall_dist(g, &dda);
	return ;
}
