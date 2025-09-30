#include "cub3D.h"

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	find_player(int y, char *line, t_data *data)
{
	int	x;
	int	player_count;

	if (!data->map)
		return ;
	player_count = 0;
	x = 0;
	while (line[x])
	{
		if (is_player_char(line[x]))
		{
			data->player_x = x;
			data->player_y = y;
			data->player_dir = line[x];
			player_count++;
		}
		x++;
	}
	if (player_count != 1)
		return ;
	return ;
}

static void	map_reallocate(char **new_map, int count, char *line, t_data *data)
{
	printf("%s", line);
	new_map[count] = ft_strdup(line);
	new_map[count + 1] = NULL;
	free(data->map);
	data->map = new_map;
	free(line);
}

int	append_map_line(char *line, t_data *data, int count)
{
	char	**new_map;
	int		i;

	new_map = malloc((count + 2) * sizeof(char *));
	if (!new_map)
		return (FALSE);
	i = 0;
	while (i < count)
	{
		new_map[i] = data->map[i];
		i++;
	}
	map_reallocate(new_map, count, line, data);
	return (TRUE);
}

int	get_map(int *fd, t_data *data)
{
	int		count;
	char	*line;
	int		is_malloc_error;

	data->map = NULL;
	count = 0;
	is_malloc_error = 1;
	line = get_next_line(*fd);
	while (line && is_malloc_error)
	{
		find_player(count, line, data);
		is_malloc_error = append_map_line(line, data, count);
		line = get_next_line(*fd);
		count++;
	}
	return (is_malloc_error);
}
