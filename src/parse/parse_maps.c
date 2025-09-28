/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:57:20 by shattori          #+#    #+#             */
/*   Updated: 2025/09/29 02:22:15 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_valid_element(char **av, int *fd, t_cub *cub)
{
	if (!xopen(fd, av[1], O_RDONLY))
		return (ft_put_str("failed xopen"), FALSE);
	if (!get_map_info(fd, cub))
		return (invalid_element(fd, cub));
	if (!get_map(fd, &cub->data))
		return (invalid_element(fd, cub));
	if (!is_valid_map(cub->data.map, &cub->data))
		return (invalid_element(fd, cub));
	return (TRUE);
}
