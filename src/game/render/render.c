/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:07:49 by nando             #+#    #+#             */
/*   Updated: 2025/10/16 16:55:03 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	put_pixel_to_canvas(t_image_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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

void	rendering_wall_slice(t_game *g, int x)
{
	int	y;

	y = g->render.draw_start;
	while (y++ < g->render.draw_end)
		put_pixel_to_canvas(&g->render.img, x, y, WALL_COLOR);
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
		rendering_wall_slice(g, x);
		x++;
	}
}
