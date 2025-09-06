/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:12:33 by shattori          #+#    #+#             */
/*   Updated: 2025/09/06 17:42:47 by shattori         ###   ########.fr       */
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

typedef struct s_data
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*floor_color;
	char	*ceiling_color;
}			t_data;

int			exit_fd(int fd);
int			is_valid_args(int ac, char **av);
int			is_valid_maps(char **av, int *fd, t_data data);
int			xopen(int *fd, char *filename, int flag);
int			get_map(int *fd, t_data *data);
int			failed_texture(int *fd, t_data *data);
int			failed_color(int *fd, t_data *data);
int			failed_map(int *fd, t_data *data);
void		init_maps(t_data *data, int fd);
int			get_map_info(int *fd, t_data *data);
int			is_valid_texture(t_data *data);
#endif
