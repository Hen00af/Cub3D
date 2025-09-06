/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:57:20 by shattori          #+#    #+#             */
/*   Updated: 2025/09/06 17:42:21 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_valid_maps(char **av, int *fd, t_data *map)
{
	if (!xopen(fd, av[1], O_RDONLY))
		return (FALSE);
	if (!get_map_info(*fd, map))
		return (FALSE);
	if (!get_map(fd, map)) // 残りをマップとして読む
		return (failed_map(fd, map));
	if (!can_read(map))
		return (failed_map(fd, map));
	return (TRUE);
}
