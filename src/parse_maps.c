/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:57:20 by shattori          #+#    #+#             */
/*   Updated: 2025/09/01 09:29:19 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_valid_maps(char **av, int *fd, t_data *map)
{
	if (!xopen(fd, av[1], O_RDONLY))
		return (FALSE);
	if (!get_texture(fd, map))
		return (failed_texture(fd, map));
	if (!get_color(fd, map))
		return (failed_color(fd, map));
	if (!get_map(fd, map))
		return (failed_map(fd, map));
	return (TRUE);
}
