/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:02:04 by nando             #+#    #+#             */
/*   Updated: 2025/10/17 15:44:03 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static char	**free_split(char **str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static void	free_map(t_world_data *world)
{
	if (world->no_path)
		free(world->no_path);
	if (world->so_path)
		free(world->so_path);
	if (world->ea_path)
		free(world->ea_path);
	if (world->we_path)
		free(world->we_path);
	free_split(world->map);
}

static void	free_images(t_game *g)
{
	if (!g || !g->mlx)
		return ;
	if (g->render.textures.north.canvas)
		mlx_destroy_image(g->mlx, g->render.textures.north.canvas);
	if (g->render.textures.south.canvas)
		mlx_destroy_image(g->mlx, g->render.textures.south.canvas);
	if (g->render.textures.east.canvas)
		mlx_destroy_image(g->mlx, g->render.textures.east.canvas);
	if (g->render.textures.west.canvas)
		mlx_destroy_image(g->mlx, g->render.textures.west.canvas);
	if (g->render.img.canvas)
		mlx_destroy_image(g->mlx, g->render.img.canvas);
}

static void	free_win_mlx(t_game *g)
{
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
}

int	close_window(t_game *g)
{
	free_map(&g->world);
	free_images(g);
	free_win_mlx(g);
	exit(0);
	return (0);
}
