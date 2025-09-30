/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:37:44 by nando             #+#    #+#             */
/*   Updated: 2025/09/30 20:16:59 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	main(void)
{
	t_game_data	game;
	char		*map[] = {"1111111111", "1000000001", "10E0000001",
				"1000000001", "1111111111", NULL};

	game.map = map;
	init_game(&game);
	mlx_put_image_to_window(game.mlx, game.win, game.img.canvas, 0, 0);
	mlx_loop(game.mlx);
	return (0);
}
