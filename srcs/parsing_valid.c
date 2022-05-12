#include "cub3d.h"

int	check_colors(char *color)
{
	int	i;
	int	coma;

	i = -1;
	while (color[++i])
		if (!ft_isdigit(color[0]) || \
		(!ft_isdigit(color[i]) && color[i] != ','))
			return (0);
	i = 0;
	coma = 0;
	while (color[i])
	{
		if (ft_atoi(&color[i]) > 225 || color[i] == ',')
			return (0);
		while (ft_isdigit(color[i]))
			i++;
		if (color[i])
		{
			i++;
			coma++;
		}
	}
	if (coma != 2)
		return (0);
	return (1);
}

void	check_elem(t_cub *cub)
{
	if (!cub->no || !cub->so || !cub->we || !cub->ea)
		free_message(cub, "Error : Textures.\n", 1);
	if (open(cub->no, O_RDONLY) == -1)
		free_message(cub, "Error : Textures.\n", 1);
	if (open(cub->so, O_RDONLY) == -1)
		free_message(cub, "Error : Textures.\n", 1);
	if (open(cub->we, O_RDONLY) == -1)
		free_message(cub, "Error : Textures.\n", 1);
	if (open(cub->ea, O_RDONLY) == -1)
	{
		free_message(cub, "Error : Textures.\n", 1);
	}
	if (!check_colors(cub->f) || !check_colors(cub->c))
		free_message(cub, "Error : Colors.\n", 1);
}

void	check_validity(t_cub *cub)
{
	int	i;
	int	j;

	check_elem(cub);
	j = -1;
	while (++j < cub->size_y)
		if (check_is_map(cub->map[j]) < 1)
			free_message(cub, "Error : Unvalid Map.\n", 1);
	j = -1;
	while (++j < cub->size_y)
	{
		i = -1;
		while (++i < cub->size_x)
		{
			break ;
		}
	}
}
