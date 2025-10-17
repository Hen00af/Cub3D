/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:54:00 by nando             #+#    #+#             */
/*   Updated: 2025/10/17 16:20:30 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"
#include <stdio.h>

void	rendering_ceiling_and_floor(t_game *g, t_world_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y++ < WIN_H / 2)
	{
		x = 0;
		while (x++ <= WIN_W)
			put_pixel_to_canvas(&g->render.img, x, y, data->ceiling_color);
	}
	while (y++ < WIN_H)
	{
		x = 0;
		while (x++ <= WIN_W)
			put_pixel_to_canvas(&g->render.img, x, y, data->floor_color);
	}
}

static void	rendering_texture_column(t_game *g, t_image_data *texture,
		t_wall_design *design, int x)
{
	int	y;

	y = g->render.draw_start;
	while (y < g->render.draw_end)
	{
		design->tex_y = (int)design->tex_pos;
		design->tex_pos += design->tex_step;
		design->color = *(int *)(texture->address + (design->tex_y
					* texture->line_length + design->tex_x
					* (texture->bits_per_pixel / 8)));
		put_pixel_to_canvas(&g->render.img, x, y, design->color);
		y++;
	}
}

static void	rendering_texture(t_game *g, int x)
{
	t_image_data	*texture;
	t_wall_design	design;

	texture = select_texture(g);
	if (g->render.side == 0)
		design.wall_x = g->player.pos_y + g->render.perp_wall_dist
			* g->render.ray.dir_y;
	else
		design.wall_x = g->player.pos_x + g->render.perp_wall_dist
			* g->render.ray.dir_x;
	design.wall_x -= floor(design.wall_x);
	design.tex_x = (int)(design.wall_x * (double)texture->width);
	design.tex_step = (double)texture->height / (double)g->render.line_height;
	design.tex_pos = (g->render.draw_start - WIN_H / 2 + g->render.line_height
			/ 2) * design.tex_step;
	rendering_texture_column(g, texture, &design, x);
}

void	rendering_walls(t_game *g)
{
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		calculate_ray(&g->render.ray, &g->player, x);
		dda(g);
		calculate_the_wall_height(&g->render, g);
		rendering_texture(g, x);
		x++;
	}
}
