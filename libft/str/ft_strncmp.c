/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:51:45 by shattori          #+#    #+#             */
/*   Updated: 2025/09/15 13:20:13 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t count)
{
	size_t	s;

	s = 0;
	if (!string1 && !string2)
		return (-1);
	while (s < count)
	{
		if (!string1[s] && !string2[s])
		{
			return ((unsigned char)string1[s] - (unsigned char)string2[s]);
		}
		if ((int)((string1[s] != string2[s])))
		{
			return ((unsigned char)string1[s] - (unsigned char)string2[s]);
		}
		s++;
	}
	return (0);
}
