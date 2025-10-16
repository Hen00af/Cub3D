/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:02:04 by nando             #+#    #+#             */
/*   Updated: 2025/10/16 16:38:05 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	init_game(t_game *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "Cub3D");
	g->render.img.canvas = mlx_new_image(g->mlx, WIN_W, WIN_H);
	g->render.img.address = mlx_get_data_addr(g->render.img.canvas,
			&g->render.img.bits_per_pixel, &g->render.img.line_length,
			&g->render.img.endian);
}
