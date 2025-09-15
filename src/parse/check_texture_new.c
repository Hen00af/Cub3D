/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:20:57 by shattori          #+#    #+#             */
/*   Updated: 2025/09/15 18:43:35 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// TODO: テクスチャファイルの存在チェック
// NO, SO, WE, EA の4つのテクスチャが定義されているかチェック
int	get_map_info(int *fd, t_cub *cub)
{
	char	*str;
	int		cnt;

	cnt = 0;
	while (cnt < 6)
	{
		str = get_next_line(*fd);
		if (!str)
			break ;
		if (str[0] == '\n' || str[0] == '\0')
		{
			free(str);
			continue ;
		}
		if (str[0] == '1' || str[0] == '0' || str[0] == ' ')
		{
			free(str);
			break ;
		}
		separate_args(&cub->data, str);
		free(str);
		cnt++;
	}
	if (is_valid_texture(&cub->data))
		return (TRUE);
	return (FALSE);
}

// TODO: mapの定義をチェック
// FloodFill を2回施行してクリア可能かどうかを検証　<ー　いらない


int	parse_color(char *str)
{
	char	**rgb_parts;
	int		color;
	char	comma[2];
	int		rgb[3];

	comma[0] = ',';
	comma[1] = '\0';
	while (*str == ' ' || *str == '\t')
		str++;
	rgb_parts = ft_split(str, comma);
	if (!rgb_parts || !rgb_parts[0] || !rgb_parts[1] || !rgb_parts[2])
		return (free_split(rgb_parts), -1);
	rgb[0] = ft_atoi(rgb_parts[0]);
	rgb[1] = ft_atoi(rgb_parts[1]);
	rgb[2] = ft_atoi(rgb_parts[2]);
	free_split(rgb_parts);
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0 || rgb[1] > 255 || rgb[2] < 0
		|| rgb[2] > 255)
		return (-1);
	color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	return (color);
}

int	is_valid_texture_file(char *path)
{
	int	fd;
	int	len;

	if (!path)
		return (FALSE);
	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
		return (FALSE);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (TRUE);
	close(fd);
	return (TRUE);
}

void	init_maps(t_data *data)
{
	data->no_path = NULL;
	data->so_path = NULL;
	data->we_path = NULL;
	data->ea_path = NULL;
	data->floor_color = -1;
	data->ceiling_color = -1;
	data->map = NULL;
	init_player(data);
}

void	cleanup_data(t_data *data)
{
	int	i;

	if (data->no_path)
		free(data->no_path);
	if (data->so_path)
		free(data->so_path);
	if (data->we_path)
		free(data->we_path);
	if (data->ea_path)
		free(data->ea_path);
	if (data->map)
	{
		i = 0;
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
}

void	init_player(t_data *data)
{
	data->player_x = -1;
	data->player_y = -1;
	data->player_dir = '\0';
}

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	find_player(t_data *data)
{
	int	y;
	int	x;
	int	player_count;

	if (!data->map)
		return (FALSE);
	player_count = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (is_player_char(data->map[y][x]))
			{
				data->player_x = x;
				data->player_y = y;
				data->player_dir = data->map[y][x];
				player_count++;
			}
			x++;
		}
		y++;
	}
	if (player_count != 1)
		return (FALSE);
	return (TRUE);
}
