/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:14:56 by nando             #+#    #+#             */
/*   Updated: 2025/10/17 17:14:57 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *ptr, size_t new_size)
{
	char	*new_ptr;
	size_t	old_size;

	if (!ptr)
		return (malloc(new_size));
	old_size = ft_strlen(ptr) + 1;
	if (old_size > new_size)
		old_size = new_size;
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}

// int main(void)
// {
//     char *str = malloc(6);
//     if (!str)
//         return (1);
//     ft_strlcpy(str, "qwerty", 6);

//     str = ft_realloc(str, 10);
//     if (str)
//         printf("%s\n", str);

//     free(str);
//     return (0);
// }
