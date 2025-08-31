/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:57:20 by shattori          #+#    #+#             */
/*   Updated: 2025/08/31 22:58:54 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_valid_maps(char **av)
{
	int	fd;

	if (!xopen(&fd, av[1], O_RDONLY))
		return (FALSE);
	if (!check_texture(fd))
	{
		close(fd);
		return (failed_texture());
	}
	if (!check_color(fd))
	{
		close(fd);
		return (failed_color());
	}
	if (!check_map(fd))
	{
		close(fd);
		return (faild_map());
	}
	close(fd);
	return (TRUE);
}
