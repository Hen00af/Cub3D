
#include "game.h"

static void	run_game(t_game *g)
{
	mlx_hook(g->win, 2, 1L << 0, handle_key_press, g);
	rendering_ceiling_and_floor(g, &g->world);
	rendering_walls(g);
	if (g->is_bonus)
		b_render(g);
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
