/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 00:14:22 by shattori          #+#    #+#             */
/*   Updated: 2025/10/17 00:15:10 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	init_maps(t_data *data)
{
	data->no_path = NULL;
	data->so_path = NULL;
	data->we_path = NULL;
	data->ea_path = NULL;
	data->floor_color = -1;
	data->ceiling_color = -1;
	data->map = NULL;
	p_init_player(data);
}

void	cleanup_data(t_data *data)
{
	int	i;

	if (data->no_path)
		free(data->no_path);
	if (data->so_path)
		free(data->so_path);
	if (data->we_path)
		free(data->we_path);
	if (data->ea_path)
		free(data->ea_path);
	if (data->map)
	{
		i = 0;
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
}

void	p_init_player(t_data *data)
{
	data->player_x = -1;
	data->player_y = -1;
	data->player_dir = '\0';
}
