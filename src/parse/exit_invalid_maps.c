/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_invalid_maps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:26:48 by shattori          #+#    #+#             */
/*   Updated: 2025/09/29 00:36:30 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	failed_texture(int *fd, t_cub *cub)
{
	ft_putstr_fd("ERROR: invalid form of texture\n", 2);
	return (exit_cub(fd, cub));
}

int	failed_color(int *fd, t_cub *cub)
{
	ft_putstr_fd("Error: Invalid color configuration\n", 2);
	return (exit_cub(fd, cub));
}

int	invalid_element(int *fd, t_cub *cub)
{
	ft_putstr_fd("Error: Invalid element configuration\n", 2);
	return (exit_cub(fd, cub));
}
