
#include "game.h"

static int	render_frame(t_game *g)
{
	rendering_ceiling_and_floor(g, &g->world);
	rendering_walls(g);
	b_render(g);
	mlx_put_image_to_window(g->mlx, g->win, g->render.img.canvas, 0, 0);
	return (0);
}

static void	run_game(t_game *g)
{
	mlx_hook(g->win, 2, 1L << 0, handle_key_press, g); // キー入力時
	mlx_loop_hook(g->mlx, render_frame, g);            // 毎フレーム呼ばれる
	render_frame(g);                                   // 初期描画
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
