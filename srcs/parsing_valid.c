/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:08:57 by qujacob           #+#    #+#             */
/*   Updated: 2022/05/31 15:02:45 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_colors(t_wall *wall)
{
	int	i;
	int	j;
	int	k;

	wall->f_tab = malloc(sizeof(int) * 3);
	wall->c_tab = malloc(sizeof(int) * 3);
	if (!wall->f_tab || !wall->c_tab)
		return (0);
	i = -1;
	j = 0;
	k = 0;
	while (++i < 3)
	{
		wall->f_tab[i] = ft_atoi(&wall->f[j]);
		wall->c_tab[i] = ft_atoi(&wall->c[k]);
		while (ft_isdigit(wall->f[j]))
			j++;
		while (ft_isdigit(wall->c[k]))
			k++;
		j++;
		k++;
	}
	return (1);
}

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
		if (ft_atoi(&color[i]) > 255 || color[i] == ',')
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
	if (!set_colors(cub->wall))
		free_message(cub, "Error : Parsing.\n", 1);
}

void	check_map_valid(t_cub *cub, int j, int i)
{
	if (cub->player && is_a_player(cub->map[j][i]))
		free_message(cub, "Error : Multiplayer declaration.\n", 1);
	if (is_a_player(cub->map[j][i]))
	{
		cub->player = cub->map[j][i];
		cub->man.pos.x = i + 0.5;
		cub->man.pos.y = j + 0.5;
	}
	if (cub->map[j][i] == '0' && (i == 0 || i == cub->size_x - 1 \
	|| j == 0 || j == cub->size_y - 1))
		free_message(cub, "Error : Wall Not Closed.\n", 1);
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
