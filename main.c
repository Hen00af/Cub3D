/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:10:42 by shattori          #+#    #+#             */
/*   Updated: 2025/10/16 13:45:00 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/cub3D.h"
#include "src/game/game.h"

int	main(int ac, char **av)
{
	int			fd;
	t_parse		parse;
	t_game_data	game;

	fd = 0;
	init_maps(&parse.data);
	if (!is_valid_args(ac, av) || !is_valid_element(av, &fd, &parse))
		return (1);
	printf("Map parsing completed successfully!\n");
	data_trancefar(&parse,&game);
	run_game(&parse.data, &game);
	close(fd);
	exit_parse(&fd, &parse);
	return (0);
}
