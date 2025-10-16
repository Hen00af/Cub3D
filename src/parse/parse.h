#ifndef PARSE_H
# define PARSE_H

# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define FALSE 0
# define TRUE 1

// プレイヤーの位置と向きを管理する構造体
typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

// マップ要素の存在確認フラグ
typedef struct s_bool_map_data
{
	int				exist_we_path;
	int				exist_ea_path;
	int				exist_no_path;
	int				exist_so_path;
	int				exist_floor_path;
	int				exist_color_path;
}					t_bool_map_data;

typedef struct s_data
{
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	int				floor_color;
	int				ceiling_color;
	char			**map;
	int				player_x;
	int				player_y;
	char			player_dir;
}					t_data;

// パース時の作業用構造体
typedef struct s_parse
{
	t_data			data;
	t_bool_map_data	map_data;
}					t_parse;

// parse module 内部関数のプロトタイプ宣言
int					xopen(int *fd, char *filename, int flag);
char				*to_not_empty_string(int *fd);
int					get_map(int *fd, t_data *data);
int					get_map_info(int *fd, t_parse *cub);
int					invalid_element(int *fd, t_parse *cub);
int					parse_color(char *str);
void				separate_args(t_data *data, char *str);
void				cleanup_data(t_data *data);
void				p_init_player(t_data *data);
int					failed_texture(int *fd, t_parse *cub);
int					failed_color(int *fd, t_parse *cub);
void				free_map(t_data *data);
void				find_player(int y, char *line, t_data *data);
int					exit_fd(int *fd);
int					exit_parse(int *fd, t_parse *cub);
int					is_player_char(char c);
int					is_valid_texture(t_data *data);
int					is_valid_texture_file(char *path);
int					is_valid_element(char **av, int *fd, t_parse *cub);
int					is_valid_map(char **map, t_data *data);
int					exit_cub(int *fd, t_parse *cub);
void				init_maps(t_data *data);
int					is_valid_args(int ac, char **av);
#endif
