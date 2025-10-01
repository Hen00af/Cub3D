/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:10:42 by shattori          #+#    #+#             */
/*   Updated: 2025/10/01 16:33:36 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "src/game/game.h"

int	main(int ac, char **av)
{
	t_cub	cub;
	int		fd;

	fd = 0;
	init_maps(&cub.data);
	if (!is_valid_args(ac, av) || !is_valid_element(av, &fd, &cub))
		return (1);
	printf("Map parsing completed successfully!\n");
	run_game(&cub.data);
	close(fd);
	exit_cub(&fd, &cub);
	// minilib_init();
	// minilibx_destroy();
	return (0);
}
