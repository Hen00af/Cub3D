#include "cub3D.h"

int	is_valid_texture(t_data *data)
{
	if (!data->no_path || !data->so_path || !data->we_path || !data->ea_path)
		return (FALSE);
	if (data->floor_color == -1 || data->ceiling_color == -1)
		return (FALSE);
	if (!is_valid_texture_file(data->no_path)
		|| !is_valid_texture_file(data->so_path)
		|| !is_valid_texture_file(data->we_path)
		|| !is_valid_texture_file(data->ea_path))
		return (FALSE);
	return (TRUE);
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
