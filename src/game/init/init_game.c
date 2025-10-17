/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:49:15 by nando             #+#    #+#             */
/*   Updated: 2025/10/17 15:49:17 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"
#include <stdio.h>

void	load_texture(t_game *game, const char *file_path, t_image_data *texture)
{
	texture->canvas = mlx_xpm_file_to_image(game->mlx, (char *)file_path,
			&texture->width, &texture->height);
	if (!texture->canvas)
	{
		printf("Error: failed to load texture: %s\n", file_path);
		exit(1);
	}
	texture->address = mlx_get_data_addr(texture->canvas,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
}

void	load_all_textures(t_game *game)
{
	load_texture(game, game->world.no_path, &game->render.textures.north);
	load_texture(game, game->world.so_path, &game->render.textures.south);
	load_texture(game, game->world.ea_path, &game->render.textures.east);
	load_texture(game, game->world.we_path, &game->render.textures.west);
}

void	init_game(t_game *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "Cub3D");
	g->render.img.canvas = mlx_new_image(g->mlx, WIN_W, WIN_H);
	g->render.img.address = mlx_get_data_addr(g->render.img.canvas,
			&g->render.img.bits_per_pixel, &g->render.img.line_length,
			&g->render.img.endian);
	load_all_textures(g);
}
