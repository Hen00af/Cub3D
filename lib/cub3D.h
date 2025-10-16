#ifndef CUB3D_H
# define CUB3D_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../src/parse/parse.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define FALSE 0
# define TRUE 1

// ✅ 共通関数プロトタイプ
void	init_maps(t_data *data);
int		is_valid_args(int ac, char **av);
int		is_valid_element(char **av, int *fd, t_parse *cub);
int		exit_cub(int *fd, t_parse *cub);
void	free_map(t_data *data);

#endif
