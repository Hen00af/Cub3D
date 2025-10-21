/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:19:47 by nando             #+#    #+#             */
/*   Updated: 2025/10/21 15:40:02 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	put_pixel_to_canvas(t_image_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_image_data	*select_texture(t_game *g)
{
	if (g->render.side == 0 && g->render.ray.dir_x > 0)
		return (&g->render.textures.west);
	else if (g->render.side == 0 && g->render.ray.dir_x < 0)
		return (&g->render.textures.east);
	else if (g->render.side == 1 && g->render.ray.dir_y > 0)
		return (&g->render.textures.north);
	else
		return (&g->render.textures.south);
}
