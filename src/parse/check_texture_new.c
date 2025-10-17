/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:20:57 by shattori          #+#    #+#             */
/*   Updated: 2025/10/17 18:37:57 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*get_next_str(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str[0] == '\0' || str[0] == '\n')
	{
		free(str);
		str = get_next_line(fd);
	}
	return (str);
}

int	get_map_info(int *fd, t_parse *cub)
{
	char	*str;
	int		cnt;

	cnt = 0;
	while (cnt < 6)
	{
		str = get_next_str(*fd);
		if (!str)
			break ;
		separate_args(&cub->data, str);
		free(str);
		cnt++;
	}
	if (is_valid_texture(&cub->data))
		return (TRUE);
	return (FALSE);
}

static int	comma_count(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

int	parse_color(char *str)
{
	char	**rgb_parts;
	int		color;
	char	comma[2];
	int		rgb[3];

	comma[0] = ',';
	comma[1] = '\0';
	if (comma_count(str, ',') != 2 || !ft_isdigit(str[ft_strlen(str) - 2]))
		return (-1);
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
