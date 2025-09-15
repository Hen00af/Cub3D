/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 08:06:33 by shattori          #+#    #+#             */
/*   Updated: 2025/09/15 17:56:28 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map(t_data *map)
{
	if (map->no_path)
		free(map->no_path);
	if (map->so_path)
		free(map->so_path);
	if (map->ea_path)
		free(map->ea_path);
	if (map->we_path)
		free(map->we_path);
}

int	exit_fd(int *fd)
{
	if (*fd)
		close(*fd);
	return (FALSE);
}

int	exit_cub(int *fd, t_cub *cub)
{
	exit_fd(fd);
	free_map(&cub->data);
	return (FALSE);
}
