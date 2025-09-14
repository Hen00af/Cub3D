/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:57:20 by shattori          #+#    #+#             */
/*   Updated: 2025/09/13 21:17:56 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_valid_maps(char **av, int *fd, t_data *data)
{
	if (!xopen(fd, av[1], O_RDONLY))
		return (FALSE);
	if (!get_map_info(fd, data))
		return (FALSE);
	if (!get_map(fd, data))
		return (failed_map(fd, data));
	return (TRUE);
}
