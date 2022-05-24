/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:08:59 by qujacob           #+#    #+#             */
/*   Updated: 2022/05/24 17:34:49 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	do_elem_2(t_cub *cub, char *line)
{
	if (!ft_strncmp("EA ", line, 3))
	{
		if (cub->wall->ea)
			free_message_line(cub, "Error : Double.\n", 1, line);
		cub->wall->ea = ft_strdup_no_nl(&line[3]);
		if (!cub->wall->ea)
			free_message_line(cub, "Error : Parsing\n", 1, line);
	}
	else if (!ft_strncmp("F ", line, 2))
	{
		if (cub->wall->f)
			free_message_line(cub, "Error : Double.\n", 1, line);
		cub->wall->f = ft_strdup_no_nl(&line[2]);
		if (!cub->wall->f)
			free_message_line(cub, "Error : Parsing\n", 1, line);
	}
	else if (!ft_strncmp("C ", line, 2))
	{
		if (cub->wall->c)
			free_message_line(cub, "Error : Double.\n", 1, line);
		cub->wall->c = ft_strdup_no_nl(&line[2]);
		if (!cub->wall->c)
			free_message_line(cub, "Error : Parsing\n", 1, line);
	}
}

void	do_elem(t_cub *cub, char *line)
{
	if (!ft_strncmp("NO ", line, 3))
	{
		if (cub->wall->no)
			free_message_line(cub, "Error : Double.\n", 1, line);
		cub->wall->no = ft_strdup_no_nl(&line[3]);
		if (!cub->wall->no)
			free_message_line(cub, "Error : Parsing\n", 1, line);
	}
	else if (!ft_strncmp("SO ", line, 3))
	{
		if (cub->wall->so)
			free_message_line(cub, "Error : Double.\n", 1, line);
		cub->wall->so = ft_strdup_no_nl(&line[3]);
		if (!cub->wall->so)
			free_message_line(cub, "Error : Parsing\n", 1, line);
	}
	else if (!ft_strncmp("WE ", line, 3))
	{
		if (cub->wall->we)
			free_message_line(cub, "Error : Double.\n", 1, line);
		cub->wall->we = ft_strdup_no_nl(&line[3]);
		if (!cub->wall->we)
			free_message_line(cub, "Error : Parsing\n", 1, line);
	}
	do_elem_2(cub, line);
}

int	check_is_elem(char *line)
{
	if (!ft_strncmp("NO ", line, 3))
		return (1);
	else if (!ft_strncmp("SO ", line, 3))
		return (1);
	else if (!ft_strncmp("WE ", line, 3))
		return (1);
	else if (!ft_strncmp("EA ", line, 3))
		return (1);
	else if (!ft_strncmp("F ", line, 2))
		return (1);
	else if (!ft_strncmp("C ", line, 2))
		return (1);
	return (0);
}

void	get_file(t_cub *cub)
{
	char	*line;

	line = get_next_line(cub->fd);
	while (line)
	{
		if (!check_is_elem(line) && line[0] != '\n')
		{
			if (fill_map(cub, &line) == -1)
			{
				free(line);
				free_message(cub, "Error : Map not valid\n", 1);
			}
		}
		else
			do_elem(cub, line);
		if (line)
			free(line);
		line = get_next_line(cub->fd);
	}
	if (!cub->map)
		free_message(cub, "Error : No map\n", 1);
}

void	parse_file(t_cub *cub)
{
	char	*needle;

	needle = ft_strstr(cub->file, ".cub");
	if (!needle || ft_strcmp(needle, ".cub"))
		free_message(cub, "Error : Invalid map name.\n", 1);
	cub->fd = open(cub->file, O_RDWR);
	if (cub->fd == -1)
		free_message(cub, "Error : File doesn't exist.\n", 1);
	cub->size_x = recove_x_size(cub);
	get_file(cub);
	check_validity(cub);
	close(cub->fd);
}
