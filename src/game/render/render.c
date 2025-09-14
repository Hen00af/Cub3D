/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:07:49 by nando             #+#    #+#             */
/*   Updated: 2025/09/14 19:16:14 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	put_pixel_to_canvas(t_image_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	rendering_ceiling_and_floor(t_game_data *g)
{
	int	x;
	int	y;

	y = 0;
	while (y++ < WIN_H / 2)
	{
		x = 0;
		while (x++ <= WIN_W)
			put_pixel_to_canvas(&g->img, x, y, CEILING_COLOR);
	}
	while (y++ < WIN_H)
	{
		x = 0;
		while (x++ <= WIN_W)
			put_pixel_to_canvas(&g->img, x, y, FLOOR_COLOR);
	}
}

void	rendering_wall_slice(t_game_data *g)
{
}

void	rendering_walls(t_game_data *g)
{
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		calculate_ray(g, x);
		dda(g);
		rendering_wall_slice(g);
		x++;
	}
}
