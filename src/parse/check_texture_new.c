/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:20:57 by shattori          #+#    #+#             */
/*   Updated: 2025/09/14 12:57:44 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// TODO: テクスチャファイルの存在チェック
// NO, SO, WE, EA の4つのテクスチャが定義されているかチェック
int	get_map_info(int *fd, t_data *data)
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
		separate_args(data, str);
		free(str);
		cnt++;
	}
	if (is_valid_texture(data))
		return (TRUE);
	return (FALSE);
}

// TODO: mapの定義をチェック
// FloodFill を2回施行してクリア可能かどうかを検証　<ー　いらない
int	get_map(int *fd, t_data *data)
{
	char	*line;
	int		count;
	char	**tmp;
	int		i;

	data->map = NULL;
	count = 0;
	while ((line = get_next_line(*fd)))
	{
		if (line[0] == '\n')
		{
			free(line);
			continue ;
		}
		tmp = malloc(sizeof(char *) * (count + 2));
		if (!tmp)
			return (FALSE);
		i = 0;
		while (i < count)
		{
			tmp[i] = data->map[i];
			i++;
		}
		tmp[count] = line;
		tmp[count + 1] = NULL;
		if (data->map)
			free(data->map);
		data->map = tmp;
		printf("%s\n", data->map[count]);
		count++;
	}
	return (TRUE);
}

void	separate_args(t_data *data, char *str)
{
	if (!ft_strncmp(str, "NO ", 3))
		data->no_path = ft_strtrim(str + 3, " \t\n");
	else if (!ft_strncmp(str, "SO ", 3))
		data->so_path = ft_strtrim(str + 3, " \t\n");
	else if (!ft_strncmp(str, "WE ", 3))
		data->we_path = ft_strtrim(str + 3, " \t\n");
	else if (!ft_strncmp(str, "EA ", 3))
		data->ea_path = ft_strtrim(str + 3, " \t\n");
	else if (!ft_strncmp(str, "F ", 2))
		data->floor_color = parse_color(str + 2);
	else if (!ft_strncmp(str, "C ", 2))
		data->ceiling_color = parse_color(str + 2);
}

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

int	is_valid_texture(t_data *data)
{
	if (!data->no_path || !data->so_path || !data->we_path || !data->ea_path)
		return (FALSE);
	if (data->floor_color == -1 || data->ceiling_color == -1)
		return (FALSE);
	if (!is_valid_texture_file(data->no_path)
		|| !is_valid_texture_file(data->so_path)
		|| !is_valid_texture_file(data->we_path)
		|| !is_valid_texture_file(data->ea_path))
		return (FALSE);
	return (TRUE);
}

int	is_valid_texture_file(char *path)
{
	int	fd;
	int	len;

	if (!path)
		return (FALSE);
	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
		return (TRUE);
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
