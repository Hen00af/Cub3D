#include "cub3D.h"

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

static void	fill(char **tab, t_point size, char tag, int row, int col)
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;
	if (tab[row][col] == 'F' || tab[row][col] != tag)
		return ;
	tab[row][col] = 'F';
	fill(tab, size, tag, row - 1, col);
	fill(tab, size, tag, row + 1, col);
	fill(tab, size, tag, row, col - 1);
	fill(tab, size, tag, row, col + 1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target;

	target = tab[begin.y][begin.x];
	fill(tab, size, target, begin.y, begin.x);
}

int	is_valid_map(char **map)
{
}
