
#include "../game.h"
#include <stdio.h>

void	load_texture(t_game *game, const char *file_path, t_image_data *texture)
{
	texture->canvas = mlx_xpm_file_to_image(game->mlx, (char *)file_path,
			&texture->width, &texture->height);
	if (!texture->canvas)
	{
		fprintf(stderr, "Error: failed to load texture: %s\n", file_path);
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
	g->is_bonus = FALSE;
	#ifdef BONUS
		g->is_bonus = TRUE;
	#endif
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "Cub3D");
	g->render.img.canvas = mlx_new_image(g->mlx, WIN_W, WIN_H);
	g->render.img.address = mlx_get_data_addr(g->render.img.canvas,
			&g->render.img.bits_per_pixel, &g->render.img.line_length,
			&g->render.img.endian);
	load_all_textures(g);
}
