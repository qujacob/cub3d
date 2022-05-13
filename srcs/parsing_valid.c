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
	if (!cub->wall->no || !cub->wall->so || !cub->wall->we || \
	!cub->wall->ea || !cub->wall->f || !cub->wall->c)
		free_message(cub, "Error : Textures.\n", 1);
	if (open(cub->wall->no, O_RDONLY | __O_NOFOLLOW) == -1)
		free_message(cub, "Error : Textures.\n", 1);
	if (open(cub->wall->so, O_RDONLY | __O_NOFOLLOW) == -1)
		free_message(cub, "Error : Textures.\n", 1);
	if (open(cub->wall->we, O_RDONLY | __O_NOFOLLOW) == -1)
		free_message(cub, "Error : Textures.\n", 1);
	if (open(cub->wall->ea, O_RDONLY | __O_NOFOLLOW) == -1)
		free_message(cub, "Error : Textures.\n", 1);
	if (!check_colors(cub->wall->f) || !check_colors(cub->wall->c))
		free_message(cub, "Error : Colors.\n", 1);
}

int		is_a_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	check_map_valid(t_cub *cub, int j, int i)
{
	if (cub->player && is_a_player(cub->map[j][i]))
		free_message(cub, "Error : Multiplayer declaration.\n", 1);
	if (is_a_player(cub->map[j][i]))
		cub->player = cub->map[j][i];
	if (cub->map[j][i] == ' ')
	{
		if (i != 0 && (cub->map[j][i - 1] != '1' && cub->map[j][i - 1] != ' '))
			free_message(cub, "Error : Wall Not Closed.\n", 1);
		if (i != cub->size_x - 1 && (cub->map[j][i + 1] != '1' && \
		cub->map[j][i + 1] != ' '))
			free_message(cub, "Error : Wall Not Closed.\n", 1);
		if (j != 0 && (cub->map[j - 1][i] != '1' && cub->map[j - 1][i] != ' '))
			free_message(cub, "Error : Wall Not Closed.\n", 1);
		if (j != cub->size_y - 1 && (cub->map[j + 1][i] != '1' && \
		cub->map[j + 1][i] != ' '))
			free_message(cub, "Error : Wall Not Closed.\n", 1);
	}
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
			check_map_valid(cub, j, i);
	}
	if (!cub->player)
		free_message(cub, "Error : No Player.\n", 1);
}
