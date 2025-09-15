#include "cub3D.h"

int	get_map(int *fd, t_data *data)
{
	char	*line;
	int		count;
	char	**tmp;
	int		i;

	data->map = NULL;
	count = 0;
	line = get_next_line(*fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			continue ;
		}
		tmp = malloc(sizeof(char *) * (count + 2));
		if (!tmp)
			return (FALSE);
		i = 0;
		while (i < count)
		{
			tmp[i] = data->map[i];
			i++;
		}
		tmp[count] = line;
		tmp[count + 1] = NULL;
		if (data->map)
			free(data->map);
		data->map = tmp;
		printf("%s\n", data->map[count]);
		count++;
		line = get_next_line(*fd);
	}
	return (TRUE);
}
