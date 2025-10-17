/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 08:06:33 by shattori          #+#    #+#             */
/*   Updated: 2025/10/17 17:38:56 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "game.h"
#include "parse.h"

// 🔹 文字列を安全に複製（malloc + strcpy）
static char	*safe_strdup(const char *src)
{
	char	*dst;
	size_t	len;
	size_t	i;

	if (!src)
		return (NULL);
	len = 0;
	while (src[len])
		len++;
	dst = (char *)malloc(len + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static void	free_partial(char **map, int last)
{
	while (last-- > 0)
		free(map[last]);
	free(map);
}

static char	**duplicate_map(char **map)
{
	char	**new_map;
	int		count;
	int		i;

	if (!map)
		return (NULL);
	count = 0;
	while (map[count])
		count++;
	new_map = malloc(sizeof(char *) * (count + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new_map[i] = safe_strdup(map[i]);
		if (!new_map[i])
			return (free_partial(new_map, i), NULL);
		i++;
	}
	new_map[count] = NULL;
	return (new_map);
}

t_data	*duplicate_data(t_data *src)
{
	t_data	*dst;

	dst = (t_data *)malloc(sizeof(t_data));
	if (!dst)
		return (NULL);
	dst->no_path = safe_strdup(src->no_path);
	dst->so_path = safe_strdup(src->so_path);
	dst->we_path = safe_strdup(src->we_path);
	dst->ea_path = safe_strdup(src->ea_path);
	dst->floor_color = src->floor_color;
	dst->ceiling_color = src->ceiling_color;
	dst->map = duplicate_map(src->map);
	dst->player_x = src->player_x;
	dst->player_y = src->player_y;
	dst->player_dir = src->player_dir;
	return (dst);
}

// 🔹 ゲーム全体の初期化
void	load_game(t_parse *parse, t_game *game)
{
	game->world.map = duplicate_map(parse->data.map);
	game->world.no_path = safe_strdup(parse->data.no_path);
	game->world.so_path = safe_strdup(parse->data.so_path);
	game->world.we_path = safe_strdup(parse->data.we_path);
	game->world.ea_path = safe_strdup(parse->data.ea_path);
	game->world.floor_color = parse->data.floor_color;
	game->world.ceiling_color = parse->data.ceiling_color;
	init_player_from_data(&game->player, &parse->data);
	free_map(&parse->data);
}
