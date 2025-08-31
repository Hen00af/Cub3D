/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:27:03 by shattori          #+#    #+#             */
/*   Updated: 2025/08/31 20:48:51 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#define INVALID_ARGS 10

int	is_mach(char *str1, char *str2)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str1) - 4;
	while (str1[len] && str2[i])
	{
		if (str1[len++] != str2[i++])
		{
			printf("write a map in format .cub\n");
			return (0);
		}
	}
	return (1);
}

int	is_valid(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		printf("write only 1 args\n");
		exit(INVALID_ARGS);
	}
	if (is_mach(av[1], ".cub"))
	{
		fd = open(av[1], O_RDWR);
		if (fd == -1)
		{
			printf("addprefix should be .cub\n");
			exit(INVALID_ARGS);
		}
		return (0);
	}
	exit(INVALID_ARGS);
}
