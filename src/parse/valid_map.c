/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 00:13:09 by shattori          #+#    #+#             */
/*   Updated: 2025/10/17 00:25:26 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	fill_false(int *flag)
{
	*flag = FALSE;
	return ;
}

static void	fill(char **tab, int row, int col, int *flag)
{
	if (flag == FALSE)
		return ;
	if (row < 0 || tab[row] == NULL)
		return (fill_false(flag));
	if (col < 0 || tab[row][col] == '\0')
		return (fill_false(flag));
	if (tab[row][col] == ' ')
		return (fill_false(flag));
	if (tab[row][col] == '1' || tab[row][col] == 'F')
		return ;
	if (tab[row][col] != '0' && tab[row][col] != 'N' && tab[row][col] != 'S'
		&& tab[row][col] != 'E' && tab[row][col] != 'W')
		return (fill_false(flag));
	tab[row][col] = 'F';
	fill(tab, row - 1, col, flag);
	fill(tab, row + 1, col, flag);
	fill(tab, row, col - 1, flag);
	fill(tab, row, col + 1, flag);
}

static int	flood_fill(char **map, t_point player)
{
	int	flag;

	flag = TRUE;
	fill(map, player.y, player.x, &flag);
	return (flag);
}

static void	mapping_player(t_point *point, t_data *data)
{
	point->x = data->player_x;
	point->y = data->player_y;
}

int	is_valid_map(char **map, t_data *data)
{
	t_point	player;
	char	**copy;
	int		flag;

	mapping_player(&player, data);
	if (player.x < 0 || player.y < 0)
		return (FALSE);
	copy = map_copy(map);
	if (!copy)
		return (FALSE);
	flag = flood_fill(copy, player);
	if (copy)
		free_split(copy);
	return (flag);
}
