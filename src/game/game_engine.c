/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:30:00 by shattori          #+#    #+#             */
/*   Updated: 2025/10/16 16:38:49 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	run_game(t_game *g)
{
	mlx_hook(g->win, 2, 1L << 0, handle_key_press, g);
	rendering_ceiling_and_floor(g, &g->world);
	rendering_walls(g);
}

int	execute_game(t_game *game)
{
	init_game(game);
	run_game(game);
	mlx_put_image_to_window(game->mlx, game->win, game->render.img.canvas, 0,
		0);
	mlx_loop(game->mlx);
	return (0);
}
