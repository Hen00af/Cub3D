/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:12:33 by shattori          #+#    #+#             */
/*   Updated: 2025/08/31 22:52:19 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# define FALSE 0
# define TRUE 1

typedef struct s_map
{
}	t_map;

int	is_valid_args(int ac, char **av);
int	is_valid_maps(char **av);
int	xopen(int *fd, char *filename, int flag);
int	check_texture(int fd);
int	check_color(int fd);
int	failed_texture(void);
int	failed_color(void);
// int	check_map(int fd);
// int	faild_map(void);
// void	init_maps(t_map *map, int fd);
#endif
