
#include "../game.h"

void	init_game(t_game *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "Cub3D");
	g->render.img.canvas = mlx_new_image(g->mlx, WIN_W, WIN_H);
	g->render.img.address = mlx_get_data_addr(g->render.img.canvas,
			&g->render.img.bits_per_pixel, &g->render.img.line_length,
			&g->render.img.endian);
}
