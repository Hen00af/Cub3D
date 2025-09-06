/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:10:42 by shattori          #+#    #+#             */
/*   Updated: 2025/09/06 15:57:54 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_data	map;
	int		fd;

	if (is_valid_args(ac, av) || is_valid_maps(av, &fd, map))
		return (FALSE);
	xopen(&fd, av[1], O_RDONLY);
	init_maps(&map, fd);
	// minilib_init();
	// minilibx_destroy();
	return (0);
}
