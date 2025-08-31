/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_invalid_maps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:26:48 by shattori          #+#    #+#             */
/*   Updated: 2025/08/31 22:52:13 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	failed_texture(int fd)
{
	ft_putstr_fd("ERROR: invalid form of texture\n", 2);
	close(fd);
	return (FALSE);
}

int	failed_color(void)
{
	ft_putstr_fd("Error: Invalid color configuration\n", 2);
	return (FALSE);
}
