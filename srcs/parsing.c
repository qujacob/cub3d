#include "cub3d.h"

void	do_elem_2(t_cub *cub, char *line)
{
	if (!ft_strncmp("EA ", line, 3))
	{
		if (cub->ea)
			free_message(cub, "Error : Double.\n", 1);
		cub->ea = ft_strdup(&line[3]);
		if (!cub->ea)
			free_message(cub, "Error : Parsing\n", 1);
	}
	else if (!ft_strncmp("F ", line, 2))
	{
		if (cub->f)
			free_message(cub, "Error : Double.\n", 1);
		cub->f = ft_strdup(&line[2]);
		if (!cub->f)
			free_message(cub, "Error : Parsing\n", 1);
	}
	else if (!ft_strncmp("C ", line, 2))
	{
		if (cub->c)
			free_message(cub, "Error : Double.\n", 1);
		cub->c = ft_strdup(&line[2]);
		if (!cub->c)
			free_message(cub, "Error : Parsing\n", 1);
	}
}

void	do_elem(t_cub *cub, char *line)
{
	if (!ft_strncmp("NO ", line, 3))
	{
		if (cub->no)
			free_message(cub, "Error : Double.\n", 1);
		cub->no = ft_strdup(&line[3]);
		if (!cub->no)
			free_message(cub, "Error : Parsing\n", 1);
	}
	else if (!ft_strncmp("SO ", line, 3))
	{
		if (cub->so)
			free_message(cub, "Error : Double.\n", 1);
		cub->so = ft_strdup(&line[3]);
		if (!cub->so)
			free_message(cub, "Error : Parsing\n", 1);
	}
	else if (!ft_strncmp("WE ", line, 3))
	{
		if (cub->we)
			free_message(cub, "Error : Double.\n", 1);
		cub->we = ft_strdup(&line[3]);
		if (!cub->we)
			free_message(cub, "Error : Parsing\n", 1);
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
		error_message("Error : Invalid map name.\n", 1);
	cub->fd = open(cub->file, O_RDWR);
	if (cub->fd == -1)
		error_message("Error : File doesn't exist.\n", 1);
	cub->size_x = recove_x_size(cub);
	get_file(cub);
	check_validity(cub);
	for (int i = 0; cub->map[i]; i++)
		printf("%s\n", cub->map[i]);
	close(cub->fd);
}
