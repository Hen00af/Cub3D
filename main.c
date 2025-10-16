/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:10:42 by shattori          #+#    #+#             */
/*   Updated: 2025/10/16 16:38:28 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/cub3D.h"
#include "src/game/game.h"

int	main(int ac, char **av)
{
	int		fd;
	t_parse	parse;
	t_game	game;

	fd = 0;
	init_maps(&parse.data);
	if (!is_valid_args(ac, av) || !is_valid_element(av, &fd, &parse))
		return (1);
	printf("Map parsing completed successfully!\n");
	load_game(&parse, &game);
	execute_game(&game);
	// exit_game(&game);
	return (0);
}
