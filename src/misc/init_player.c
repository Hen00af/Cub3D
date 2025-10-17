/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:24:19 by nando             #+#    #+#             */
/*   Updated: 2025/10/17 17:24:52 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parse.h"

static void	player_north(t_player *p)
{
	p->dir_vec_x = 0;
	p->dir_vec_y = DIR_BACKWARD;
	p->plane_x = VIEWING_ANGLE;
	p->plane_y = 0;
}

static void	player_south(t_player *p)
{
	p->dir_vec_x = 0;
	p->dir_vec_y = DIR_FORWARD;
	p->plane_x = -VIEWING_ANGLE;
	p->plane_y = 0;
}

static void	player_east(t_player *p)
{
	p->dir_vec_x = DIR_RIGHT;
	p->dir_vec_y = 0;
	p->plane_x = 0;
	p->plane_y = VIEWING_ANGLE;
}

static void	player_west(t_player *p)
{
	p->dir_vec_x = DIR_LEFT;
	p->dir_vec_y = 0;
	p->plane_x = 0;
	p->plane_y = -VIEWING_ANGLE;
}

// 🔹 プレイヤー初期化（方角文字に応じて方向ベクトルとカメラ面を設定）
void	init_player_from_data(t_player *p, t_data *data)
{
	p->pos_x = data->player_x + 0.5;
	p->pos_y = data->player_y + 0.5;
	if (data->player_dir == 'N')
		player_north(p);
	else if (data->player_dir == 'S')
		player_south(p);
	else if (data->player_dir == 'E')
		player_east(p);
	else if (data->player_dir == 'W')
		player_west(p);
}
