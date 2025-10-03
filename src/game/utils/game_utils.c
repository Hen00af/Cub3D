/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:02:04 by nando             #+#    #+#             */
/*   Updated: 2025/10/01 17:29:38 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../lib/cub3D.h"
// 	game->mlx = mlx_init();
// 	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "Cub3D");
// 	game->img.img = mlx_new_image(game->mlx, WIN_W, WIN_H);
// 	game->img.address = mlx_get_data_addr();
// 	mlx_loop(game->mlx);
// }

#include "../game.h"

int close_window(t_game_data *g)
{
    if (g->win)
        mlx_destroy_window(g->mlx, g->win);
    exit(0);
    return (0);
}
