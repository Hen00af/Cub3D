/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:14:23 by nando             #+#    #+#             */
/*   Updated: 2025/10/17 17:37:03 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "game.h"
# include "get_next_line.h"
# include "libft.h"
# include "parse.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define FALSE 0
# define TRUE 1

// ✅ 共通関数プロトタイプ
void	load_game(t_parse *parse, t_game *data);
void	init_player_from_data(t_player *p, t_data *data);

#endif
