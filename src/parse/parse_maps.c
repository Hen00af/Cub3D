/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:57:20 by shattori          #+#    #+#             */
/*   Updated: 2025/09/16 17:10:22 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_valid_element(char **av, int *fd, t_cub *cub)
{
	if (!xopen(fd, av[1], O_RDONLY))
		return (FALSE);
	if (!get_map_info(fd, cub))
		return (FALSE);
	if (!get_map(fd, &cub->data))
		return (failed_map(fd, cub));
	return (TRUE);
}
