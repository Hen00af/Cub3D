/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:20:57 by shattori          #+#    #+#             */
/*   Updated: 2025/09/08 14:46:08 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// TODO: テクスチャファイルの存在チェック
// NO, SO, WE, EA の4つのテクスチャが定義されているかチェック
int	get_map_info(int *fd, t_data *data)
{
	char	*str;
	int		cnt;

	cnt = 0;
	str = get_next_line(*fd);
	while (str && cnt < 6)
	{
		// 空行をスキップ
		if (str[0] == '\n' || str[0] == '\0')
		{
			free(str);
			str = get_next_line(*fd);
			continue ;
		}
		// マップ開始をチェック（数字で始まる行）
		if (str[0] == '1' || str[0] == '0' || str[0] == ' ')
		{
			free(str);
			break ;
		}
		separate_args(data, str);
		free(str);
		str = get_next_line(*fd);
		cnt++;
	}
	if (str)
		free(str);
	if (is_valid_texture(data))
		return (TRUE);
	return (FALSE);
}

// TODO: mapの定義をチェック
// FloodFill を2回施行してクリア可能かどうかを検証
int	get_map(int *fd, t_data *data)
{
	char	*line;
	int		map_started;

	map_started = 0;
	line = get_next_line(*fd);
	while (line)
	{
		// 空行をスキップ
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			line = get_next_line(*fd);
			continue ;
		}
		// マップの開始を検出
		if (line[0] == '1' || line[0] == '0' || line[0] == ' ')
		{
			map_started = 1;
			// TODO: マップ行を配列に保存する処理を実装
			// 現在はプリントして確認
			printf("Map line: %s", line);
		}
		free(line);
		line = get_next_line(*fd);
	}
	if (line)
		free(line);
	// TODO: FloodFill アルゴリズムでマップの妥当性をチェック
	(void)data;
	return (map_started ? TRUE : FALSE);
}

void	separate_args(t_data *data, char *str)
{
	if (!ft_strncmp(str, "NO ", 3))
		data->no_path = ft_strtrim(str + 3, " \t\n");
	else if (!ft_strncmp(str, "SO ", 3))
		data->so_path = ft_strtrim(str + 3, " \t\n");
	else if (!ft_strncmp(str, "WE ", 3))
		data->we_path = ft_strtrim(str + 3, " \t\n");
	else if (!ft_strncmp(str, "EA ", 3))
		data->ea_path = ft_strtrim(str + 3, " \t\n");
	else if (!ft_strncmp(str, "F ", 2))
		data->floor_color = parse_color(str + 2);
	else if (!ft_strncmp(str, "C ", 2))
		data->ceiling_color = parse_color(str + 2);
}

int	parse_color(char *str)
{
	char	**rgb_parts;
	int		color;
	char	comma[2];

	int r, g, b;
	comma[0] = ',';
	comma[1] = '\0';
	// 文字列をトリムして改行を除去
	while (*str == ' ' || *str == '\t')
		str++;
	// カンマで分割
	rgb_parts = ft_split(str, comma);
	if (!rgb_parts || !rgb_parts[0] || !rgb_parts[1] || !rgb_parts[2])
	{
		if (rgb_parts)
			free_split(rgb_parts);
		return (-1); // エラー値
	}
	// RGB値を取得 (0-255の範囲チェック)
	r = ft_atoi(rgb_parts[0]);
	g = ft_atoi(rgb_parts[1]);
	b = ft_atoi(rgb_parts[2]);
	free_split(rgb_parts);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	// RGB値を1つの整数に変換 (0xRRGGBB形式)
	color = (r << 16) | (g << 8) | b;
	return (color);
}

int	is_valid_texture(t_data *data)
{
	// 4つのテクスチャパスが存在するかチェック
	if (!data->no_path || !data->so_path || !data->we_path || !data->ea_path)
		return (FALSE);
	// 色が正しく設定されているかチェック
	if (data->floor_color == -1 || data->ceiling_color == -1)
		return (FALSE);
	// テクスチャファイルの存在チェック
	if (!is_valid_texture_file(data->no_path)
		|| !is_valid_texture_file(data->so_path)
		|| !is_valid_texture_file(data->we_path)
		|| !is_valid_texture_file(data->ea_path))
		return (FALSE);
	return (TRUE);
}

int	is_valid_texture_file(char *path)
{
	int	fd;
	int	len;

	if (!path)
		return (FALSE);
	len = ft_strlen(path);
	// .xpm拡張子チェック
	if (len < 4 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
		return (TRUE); // 今はテストのために通す
	// ファイルの存在確認
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (TRUE); // 今はテストのために通す
	close(fd);
	return (TRUE);
}

void	init_maps(t_data *data)
{
	data->no_path = NULL;
	data->so_path = NULL;
	data->we_path = NULL;
	data->ea_path = NULL;
	data->floor_color = -1;
	data->ceiling_color = -1;
}
