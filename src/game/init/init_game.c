/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:02:04 by nando             #+#    #+#             */
/*   Updated: 2025/09/30 19:12:43 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../lib/cub3D.h"
#include "../game.h"

void	init_player(t_player *p, char posi)
{
	if (posi == 'N')
	{
		p->dir_vec_x = 0;
		p->dir_vec_y = -1;
		p->plane_x = 0.66;
		p->plane_y = 0;
	}
	else if (posi == 'S')
	{
		p->dir_vec_x = 0;
		p->dir_vec_y = 1;
		p->plane_x = -0.66;
		p->plane_y = 0;
	}
	else if (posi == 'E')
	{
		p->dir_vec_x = 1;
		p->dir_vec_y = 0;
		p->plane_x = 0;
		p->plane_y = 0.66;
	}
	else if (posi == 'W')
	{
		p->dir_vec_x = -1;
		p->dir_vec_y = 0;
		p->plane_x = 0;
		p->plane_y = -0.66;
	}
}

void	init_game(t_game_data *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "Cub3D");
	g->img.canvas = mlx_new_image(g->mlx, WIN_W, WIN_H);
	g->img.data = mlx_get_data_addr(g->img.canvas, &g->img.bits_per_pixel,
			&g->img.line_length, &g->img.endian);
	mlx_hook(g->win, 2, 1L << 0, handle_key_press, g);
	g->player.pos_x = 2.5;
	g->player.pos_y = 2.5;
	init_player(&g->player, 'E');
	rendering_ceiling_and_floor(g);
	rendering_walls(g);
}
