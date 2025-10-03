#ifndef CUB3D_H
# define CUB3D_H
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# define FALSE 0
# define TRUE 1

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_data
{
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	int				floor_color;
	int				ceiling_color;
	char			**map;
	int player_x;    // プレイヤーのX座標
	int player_y;    // プレイヤーのY座標
	char player_dir; // プレイヤーの向き (N/S/E/W)
}					t_data;

typedef struct s_bool_map_data
{
	int				exist_we_path;
	int				exist_ea_path;
	int				exist_no_path;
	int				exist_so_path;
	int				exist_floor_path;
	int				exist_color_path;
}					t_bool_map_data;

typedef struct s_cub
{
	t_data			data;
	t_bool_map_data	map_data;
}					t_cub;

int					exit_fd(int *fd);
int					is_valid_args(int ac, char **av);
int					is_valid_map(char **map, t_data *data);
int					xopen(int *fd, char *filename, int flag);
int					get_map(int *fd, t_data *data);
int					get_map_info(int *fd, t_cub *cub);
int					failed_texture(int *fd, t_cub *cub);
int					failed_color(int *fd, t_cub *cub);
int					invalid_element(int *fd, t_cub *cub);
void				init_maps(t_data *data);
int					is_valid_texture(t_data *data);
int					is_valid_texture_file(char *path);
int					parse_color(char *str);
void				separate_args(t_data *data, char *str);
void				cleanup_data(t_data *data);
void				free_map(t_data *map);
int					exit_cub(int *fd, t_cub *cub);
int					is_player_char(char c);
int					is_valid_element(char **av, int *fd, t_cub *cub);
void				find_player(int y, char *line, t_data *data);
int					is_valid_map(char **map, t_data *data);
void				p_init_player(t_data *data);
#endif
