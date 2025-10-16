
#include "../game.h"
#include <stdio.h>

void	put_pixel_to_canvas(t_image_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	rendering_ceiling_and_floor(t_game *g, t_world_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y++ < WIN_H / 2)
	{
		x = 0;
		while (x++ <= WIN_W)
			put_pixel_to_canvas(&g->render.img, x, y, data->ceiling_color);
	}
	while (y++ < WIN_H)
	{
		x = 0;
		while (x++ <= WIN_W)
			put_pixel_to_canvas(&g->render.img, x, y, data->floor_color);
	}
}

void	drawing_wall_design(t_game *g, int x)
{
	t_image_data	texture;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	double			tex_step;
	double			tex_pos;
	int				y;
	int				color;

	// Select texture based on wall side and ray direction
	if (g->render.side == 0 && g->render.ray.dir_x > 0)
		texture = g->render.textures.east;
	else if (g->render.side == 0 && g->render.ray.dir_x < 0)
		texture = g->render.textures.west;
	else if (g->render.side == 1 && g->render.ray.dir_y > 0)
		texture = g->render.textures.north;
	else
		texture = g->render.textures.south;
	// Calculate the exact position where the wall was hit
	if (g->render.side == 0)
		wall_x = g->player.pos_y + g->render.perp_wall_dist
			* g->render.ray.dir_y;
	else
		wall_x = g->player.pos_x + g->render.perp_wall_dist
			* g->render.ray.dir_x;
	wall_x -= floor(wall_x);
	// Calculate texture x coordinate
	tex_x = (int)(wall_x * (double)texture.width);
	// Calculate step and initial texture position
	tex_step = (double)texture.height / (double)g->render.line_height;
	tex_pos = (g->render.draw_start - WIN_H / 2 + g->render.line_height / 2)
		* tex_step;
	y = g->render.draw_start;
	// Draw the pixels of the stripe
	while (y < g->render.draw_end)
	{
		tex_y = (int)tex_pos;
		tex_pos += tex_step;
		color = *(int *)(texture.address + (tex_y * texture.line_length + tex_x
					* (texture.bits_per_pixel / 8)));
		put_pixel_to_canvas(&g->render.img, x, y, color);
		y++;
	}
}

void	rendering_walls(t_game *g)
{
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		calculate_ray(&g->render.ray, &g->player, x);
		dda(g);
		calculate_the_wall_height(&g->render, g);
		drawing_wall_design(g, x);
		x++;
	}
}
