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

#endif
