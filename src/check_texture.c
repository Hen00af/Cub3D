/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:20:57 by shattori          #+#    #+#             */
/*   Updated: 2025/09/01 09:28:11 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_texture(int *fd, t_data *map)
{
	int	i;

	// TODO: テクスチャファイルの存在チェック
	// NO, SO, WE, EA の4つのテクスチャが定義されているかチェック
	i = 0;
	while (i < 4)
	{
		map->no_path = get_next_line(*fd);
		i++;
	}
	return (TRUE);
}

int	get_color(int *fd, t_data *map)
{
	// TODO: 色の定義チェック
	// F (floor) と C (ceiling) の色が正しく定義されているかチェック
	return (TRUE);
}

int	get_map(int *fd, t_data *map)
{
	// TODO: mapの定義をチェック
	// FloodFill を2回施行してクリア可能かどうかを検証
	return (TRUE);
}
