/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:37:44 by nando             #+#    #+#             */
/*   Updated: 2025/10/01 16:39:48 by nando            ###   ########.fr       */
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

// gameのみのテスト用

// int	main(void)
// {
// 	t_game_data	game;
// 	char		*map[] = {"1111111111", "1000000001", "10E0000001",
// 				"1000000001", "1111111111", NULL};

// 	game.map = map;
// 	init_game(&game);
// 	mlx_put_image_to_window(game.mlx, game.win, game.img.canvas, 0, 0);
// 	mlx_loop(game.mlx);
// 	return (0);
// }
