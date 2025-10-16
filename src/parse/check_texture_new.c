/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:20:57 by shattori          #+#    #+#             */
/*   Updated: 2025/10/16 11:56:15 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3D.h"
#include "../../get_next_line/get_next_line.h"


char	*get_next_str(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str[0] == '\0' || str[0] == '\n')
		str = get_next_line(fd);
	return (str);
}

// TODO: テクスチャファイルの存在チェック
// NO, SO, WE, EA の4つのテクスチャが定義されているかチェック
int	get_map_info(int *fd, t_parse *cub)
{
	char	*str;
	int		cnt;

	cnt = 0;
	printf("get_map_info\n");
	while (cnt < 6)
	{
		str = get_next_str(*fd);
		if (!str)
			break ;
		printf("%s", str);
		separate_args(&cub->data, str);
		free(str);
		cnt++;
	}
	if (is_valid_texture(&cub->data))
		return (TRUE);
	return (FALSE);
}

// TODO: mapの定義をチェック
// FloodFill を2回施行してクリア可能かどうかを検証
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
	p_init_player(data);
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

void	p_init_player(t_data *data)
{
	data->player_x = -1;
	data->player_y = -1;
	data->player_dir = '\0';
}
