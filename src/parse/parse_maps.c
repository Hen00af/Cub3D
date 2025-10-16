/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:57:20 by shattori          #+#    #+#             */
/*   Updated: 2025/10/16 13:12:28 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_valid_element(char **av, int *fd, t_parse *parse)
{
	if (!xopen(fd, av[1], O_RDONLY))
		return (ft_put_str("failed xopen"), FALSE);
	if (!get_map_info(fd, parse))
		return (invalid_element(fd, parse));
	if (!get_map(fd, &parse->data))
		return (invalid_element(fd, parse));
	if (!is_valid_map(parse->data.map, &parse->data))
		return (invalid_element(fd, parse));
	return (TRUE);
}
