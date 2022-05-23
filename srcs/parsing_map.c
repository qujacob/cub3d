/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:09:09 by qujacob           #+#    #+#             */
/*   Updated: 2022/05/23 17:09:27 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_a_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	create_map(t_cub *cub)
{
	int	x;

	x = -1;
	cub->map = (char **)malloc(sizeof(char *) * (cub->size_y + 1));
	if (!cub->map)
		error_message("Error : Malloc.\n", 1);
	cub->map[cub->size_y] = NULL;
	while (++x < cub->size_y)
	{
		cub->map[x] = malloc(cub->size_x + 1);
		if (!cub->map[x])
			error_message("Error : Malloc.\n", 1);
	}
}

int	recove_x_size(t_cub *cub)
{
	int		size;
	char	*str;
	int		fd;

	size = 0;
	fd = open(cub->file, O_RDONLY);
	if (fd == -1)
		free_message(cub, "Error : Parsing\n", 1);
	str = get_next_line(fd);
	while (str && (check_is_elem(str) || str[0] == '\n'))
	{
		if (str)
			free(str);
		str = get_next_line(fd);
	}
	while (str)
	{
		if (ft_strlen(str) > (size_t)size)
			size = ft_strlen(str);
		free(str);
		str = get_next_line(fd);
		cub->size_y++;
	}
	close(fd);
	return (size);
}

int	check_is_map(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '\n')
		return (0);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1' && \
		line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
			return (-1);
		i++;
	}
	return (1);
}

int	fill_map(t_cub *cub, char **line)
{
	int	i;
	int	j;

	j = -1;
	if (check_is_map(*line) < 1)
		return (check_is_map(*line));
	create_map(cub);
	while (*line && ++j < cub->size_y)
	{
		i = -1;
		while (++i < cub->size_x)
		{
			if (i >= (int)ft_strlen(*line) || (*line)[i] == ' ' \
			|| (*line)[i] == '\n')
				cub->map[j][i] = ' ';
			else if ((*line)[i] != '\n')
				cub->map[j][i] = (*line)[i];
		}
		cub->map[j][i] = '\0';
		if (*line)
			free(*line);
		*line = get_next_line(cub->fd);
	}
	return (1);
}
