/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:13:42 by shattori          #+#    #+#             */
/*   Updated: 2025/10/17 00:20:24 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	xopen(int *fd, char *filename, int flag)
{
	*fd = open(filename, flag);
	if (*fd == -1)
	{
		ft_putstr_fd("Error: can't open file\n", 2);
		return (FALSE);
	}
	return (TRUE);
}

char	*to_not_empty_string(int *fd)
{
	char	*tmp;

	tmp = get_next_line(*fd);
	while (!tmp)
		tmp = get_next_line(*fd);
	return (tmp);
}

char	**map_copy(char **map)
{
	int		height;
	char	**copy;
	int		i;

	height = 0;
	while (map[height])
		height++;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}
