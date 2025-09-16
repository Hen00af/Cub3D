#include "cub3D.h"

int	get_map(int *fd, t_data *data)
{
	int		count;
	int		i;
	char	**new_map;
	char	*line;

	data->map = NULL;
	count = 0;
	line = get_next_line(*fd);
	while (line)
	{
		new_map = malloc((count + 2) * sizeof(char *));
		if (!new_map)
			return (FALSE);
		i = 0;
		while (i < count)
		{
			new_map[i] = data->map[i];
			i++;
		}
		new_map[count] = ft_strdup(line);
		new_map[count + 1] = NULL;
		free(data->map);
		data->map = new_map;
		free(line);
		line = get_next_line(*fd);
		count++;
	}
	return (TRUE);
}
