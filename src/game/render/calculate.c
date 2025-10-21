/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:21:39 by nando             #+#    #+#             */
/*   Updated: 2025/10/21 15:18:47 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	calculate_ray(t_ray *ray, t_player *p, int x)
{
	double	normalize_screen;

	normalize_screen = 2.0 * x / (double)WIN_W - 1.0;
	ray->dir_x = p->dir_vec_x + p->plane_x * normalize_screen;
	ray->dir_y = p->dir_vec_y + p->plane_y * normalize_screen;
}

void	calcurate_perp_wall_dist(t_game *g, t_dda *dda)
{
	if (g->render.side == 0)
		g->render.perp_wall_dist = (dda->side_dist_x - dda->delta_dist_x);
	else
		g->render.perp_wall_dist = (dda->side_dist_y - dda->delta_dist_y);
}

void	calculate_the_wall_height(t_render *r, t_game *g)
{
	if (r->perp_wall_dist <= 0.00001)
		r->perp_wall_dist = 0.00001;
	r->line_height = (int)(WIN_H / g->render.perp_wall_dist);
	r->draw_start = -g->render.line_height / 2 + WIN_H / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = g->render.line_height / 2 + WIN_H / 2;
	if (r->draw_end >= WIN_H)
		r->draw_end = WIN_H;
}
