/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:37:44 by nando             #+#    #+#             */
/*   Updated: 2025/09/30 17:12:46 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	main(void)
{
	t_game_data	game;
	char		*map[] = {"111111", "100001", "10N001", "111111", NULL};

	game.map = map;
	init_game(&game);
	mlx_put_image_to_window(game.mlx, game.win, game.img.canvas, 0, 0);
	mlx_loop(game.mlx);
	return (0);
}
