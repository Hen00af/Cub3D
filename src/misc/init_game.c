/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 08:06:33 by shattori          #+#    #+#             */
/*   Updated: 2025/10/16 16:35:54 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// 🔹 2次元配列（マップ）をディープコピー
static char	**duplicate_map(char **map)
{
	int		i;
	int		count;
	char	**new_map;

	if (!map)
		return (NULL);
	count = 0;
	while (map[count])
		count++;
	new_map = (char **)malloc(sizeof(char *) * (count + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new_map[i] = safe_strdup(map[i]);
		if (!new_map[i])
		{
			while (i-- > 0)
				free(new_map[i]);
			free(new_map);
			return (NULL);
		}
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

// 🔹 プレイヤー初期化（方角文字に応じて方向ベクトルとカメラ面を設定）
void	init_player_from_data(t_player *p, t_data *data)
{
	p->pos_x = data->player_x + 0.5;
	p->pos_y = data->player_y + 0.5;
	if (data->player_dir == 'N')
	{
		p->dir_vec_x = 0;
		p->dir_vec_y = DIR_BACKWARD;
		p->plane_x = VIEWING_ANGLE;
		p->plane_y = 0;
	}
	else if (data->player_dir == 'S')
	{
		p->dir_vec_x = 0;
		p->dir_vec_y = DIR_FORWARD;
		p->plane_x = -VIEWING_ANGLE;
		p->plane_y = 0;
	}
	else if (data->player_dir == 'E')
	{
		p->dir_vec_x = DIR_RIGHT;
		p->dir_vec_y = 0;
		p->plane_x = 0;
		p->plane_y = VIEWING_ANGLE;
	}
	else if (data->player_dir == 'W')
	{
		p->dir_vec_x = DIR_LEFT;
		p->dir_vec_y = 0;
		p->plane_x = 0;
		p->plane_y = -VIEWING_ANGLE;
	}
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
