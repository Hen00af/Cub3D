/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:30:00 by shattori          #+#    #+#             */
/*   Updated: 2025/10/01 17:30:00 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3D.h"
#include "game.h"

int	run_game(t_data *data)
{
	t_game_data	game;

	game.map = data->map;
	init_game(&game, data);
	mlx_put_image_to_window(game.mlx, game.win, game.img.canvas, 0, 0);
	mlx_loop(game.mlx);
	return (0);
}
