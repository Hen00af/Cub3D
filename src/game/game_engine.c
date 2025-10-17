/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:12:36 by nando             #+#    #+#             */
/*   Updated: 2025/10/17 15:17:22 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	render_frame(t_game *g)
{
	rendering_ceiling_and_floor(g, &g->world);
	rendering_walls(g);
	b_render(g);
	mlx_put_image_to_window(g->mlx, g->win, g->render.img.canvas, 0, 0);
	return (0);
}

static void	run_game(t_game *g)
{
	mlx_hook(g->win, 2, 1L << 0, handle_key_press, g);
	mlx_loop_hook(g->mlx, render_frame, g);
}

int	execute_game(t_game *g)
{
	init_game(g);
	run_game(g);
	mlx_loop(g->mlx);
	return (0);
}
