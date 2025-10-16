
#include "game.h"

void	calculate_ray(t_ray *ray, t_player *p, int x)
{
	double	normalize_screen;

	//カメラ空間のX座標を-1 ~ 1正規化したやつ
	normalize_screen = 2.0 * x / (double)WIN_W - 1.0;
	//光線のベクトルを算出
	ray->dir_x = p->dir_vec_x + p->plane_x * normalize_screen;
	ray->dir_y = p->dir_vec_y + p->plane_y * normalize_screen;
}

// Init player position
void	init_player_posi(t_game *g, t_dda *dda)
{
	dda->map_x = (int)g->player.pos_x;
	dda->map_y = (int)g->player.pos_y;
}

// Calculating the distance when moving one square in each direction
void	init_deltadist(t_game *g, t_dda *dda)
{
	if (g->render.ray.dir_x == 0)
		dda->delta_dist_x = 1e30;
	else
		dda->delta_dist_x = fabs(1 / g->render.ray.dir_x);
	if (g->render.ray.dir_y == 0)
		dda->delta_dist_y = 1e30;
	else
		dda->delta_dist_y = fabs(1 / g->render.ray.dir_y);
}

// Calculating the istance to the first vertical line and ray direction
void	init_sidedist_and_step(t_game *g, t_dda *dda)
{
	if (g->render.ray.dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (g->player.pos_x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - g->player.pos_x)
			* dda->delta_dist_x;
	}
	if (g->render.ray.dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (g->player.pos_y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - g->player.pos_y)
			* dda->delta_dist_y;
	}
}

void	init_dda(t_game *g, t_dda *dda)
{
	dda->hit = 0;
	init_player_posi(g, dda);
	init_deltadist(g, dda);
	init_sidedist_and_step(g, dda);
}

void	dda_loop(t_game *g, t_dda *dda)
{
	while (dda->hit == 0)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			g->render.side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			g->render.side = 1;
		}
		if (g->world.map[dda->map_y][dda->map_x] == '1')
			dda->hit = 1;
	}
}

void	calcurate_perp_wall_dist(t_game *g, t_dda *dda)
{
	if (g->render.side == 0)
		g->render.perp_wall_dist = (dda->side_dist_x - dda->delta_dist_x);
	else
		g->render.perp_wall_dist = (dda->side_dist_y - dda->delta_dist_y);
}

void	calculate_the_wall_height(t_render *r, t_game *g)
{
	if (r->perp_wall_dist <= 0.00001)
		r->perp_wall_dist = 0.00001;
	r->line_height = (int)(WIN_H / g->render.perp_wall_dist);
	r->draw_start = -g->render.line_height / 2 + WIN_H / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = g->render.line_height / 2 + WIN_H / 2;
	if (r->draw_end >= WIN_H)
		r->draw_end = WIN_H - 1;
}

// culculate dda in this fanction temporally...
void	dda(t_game *g)
{
	t_dda	dda;

	init_dda(g, &dda);
	dda_loop(g, &dda);
	calcurate_perp_wall_dist(g, &dda);
	return ;
}
