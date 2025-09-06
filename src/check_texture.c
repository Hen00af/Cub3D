/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:20:57 by shattori          #+#    #+#             */
/*   Updated: 2025/09/06 17:44:09 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// TODO: テクスチャファイルの存在チェック
// NO, SO, WE, EA の4つのテクスチャが定義されているかチェック
int	get_map_info(int *fd, t_data *data)
{
	char	*get_str;

	(void)to_not_empty_string(fd);
	get_str = get_next_line(*fd);
	if (is_valid_texture(data))
		return (TRUE);
	return (FALSE);
}

// TODO: mapの定義をチェック
// FloodFill を2回施行してクリア可能かどうかを検証
int	get_map(int *fd, t_data *data)
{
	return (TRUE);
}
