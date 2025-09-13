/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:10:42 by shattori          #+#    #+#             */
/*   Updated: 2025/09/08 14:45:50 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_cub	cub;
	int		fd;

	fd = 0;
	init_maps(&cub.data);
	if (!is_valid_args(ac, av) || !is_valid_maps(av, &fd, &cub.data))
		return (1);
	printf("Map parsing completed successfully!\n");
	close(fd);
	// minilib_init();
	// minilibx_destroy();
	return (0);
}
