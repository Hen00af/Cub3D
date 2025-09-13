/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:27:03 by shattori          #+#    #+#             */
/*   Updated: 2025/09/01 08:29:52 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	has_cub_extension(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (FALSE);
	return (ft_strcmp(filename + len - 4, ".cub") == 0);
}

int	is_valid_args(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./cub3D {map.cub}\n", 2);
		return (FALSE);
	}
	if (!has_cub_extension(av[1]))
	{
		ft_putstr_fd("ERROR: a map shoud be in format .cub\n", 2);
		return (FALSE);
	}
	if (!xopen(&fd, av[1], O_RDONLY))
	{
		return (FALSE);
	}
	close(fd);
	return (TRUE);
}
