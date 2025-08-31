/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:13:42 by shattori          #+#    #+#             */
/*   Updated: 2025/08/31 22:42:29 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	xopen(int *fd, char *filename, int flag)
{
	*fd = open(filename, flag);
	if (*fd == -1)
	{
		ft_putstr_fd("Error: can't open file\n", 2);
		return (FALSE);
	}
	return (TRUE);
}
