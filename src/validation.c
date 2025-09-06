/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:12:20 by shattori          #+#    #+#             */
/*   Updated: 2025/09/06 15:39:06 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_valid_texture(t_data *data)
{
	if (!ft_strncmp(data->no_path, "NO ./", 5))
		return (FALSE);
	if (!ft_strncmp(data->no_path, "SO ./", 5))
		return (FALSE);
	if (!ft_strncmp(data->no_path, "WE ./", 5))
		return (FALSE);
	if (!ft_strncmp(data->no_path, "EA ./", 5))
		return (FALSE);
	return (TRUE);
}
