/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:49:30 by shattori          #+#    #+#             */
/*   Updated: 2025/10/16 17:50:16 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_map(t_data *data)
{
	if (data->no_path)
		free(data->no_path);
	if (data->so_path)
		free(data->so_path);
	if (data->ea_path)
		free(data->ea_path);
	if (data->we_path)
		free(data->we_path);
	free_split(data->map);
}

int	exit_fd(int *fd)
{
	if (*fd)
		close(*fd);
	return (FALSE);
}

int	exit_parse(int *fd, t_parse *parse)
{
	exit_fd(fd);
	free_map(&parse->data);
	return (FALSE);
}
