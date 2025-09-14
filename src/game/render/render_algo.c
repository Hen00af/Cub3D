/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:13:48 by nando             #+#    #+#             */
/*   Updated: 2025/09/14 19:24:39 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	calculate_ray(t_game_data *g, int x)
{
	double	camera_x;

	//カメラ空間のX座標を正規化したやつ
	camera_x = 2 * x / WIN_W - 1;
	//光線のベクトルを算出
	g->ray.ray_dir_x = g->player.dir_vec_x + g->player.plane_x * camera_x;
	g->ray.ray_dir_x = g->player.dir_vec_y + g->player.plane_y * camera_x;
}

void	dda(t_game_data *g)
{
	
}