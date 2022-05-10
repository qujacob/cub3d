#include "cub3d.h"

int	check_is_elem(t_cub *cub, char *line)
{
	if (!ft_strncmp("NO ", line, 3))
	{
		cub->no = ft_strdup(&line[3]);
		if (!cub->no)
			free_message(cub, "Error : Parsing\n", 1);
	}
	else if (!ft_strncmp("SO ", line, 3))
	{
		cub->so = ft_strdup(&line[3]);
		if (!cub->so)
			free_message(cub, "Error : Parsing\n", 1);
	}
	else if (!ft_strncmp("WE ", line, 3))
	{
		cub->we = ft_strdup(&line[3]);
		if (!cub->we)
			free_message(cub, "Error : Parsing\n", 1);
	}
	else if (!ft_strncmp("EA ", line, 3))
	{
		cub->ea = ft_strdup(&line[3]);
		if (!cub->ea)
			free_message(cub, "Error : Parsing\n", 1);
	}
	else if (!ft_strncmp("F ", line, 2))
	{
		cub->f = ft_strdup(&line[2]);
		if (!cub->f)
			free_message(cub, "Error : Parsing\n", 1);
	}
	else if (!ft_strncmp("C ", line, 2))
	{
		cub->c = ft_strdup(&line[2]);
		if (!cub->c)
			free_message(cub, "Error : Parsing\n", 1);
	}
	else
		return (0);
	return (1);
}

void	get_file(t_cub *cub)
{
	char	*line;

	line = get_next_line(cub->fd);
	if (!line)
		free_message(cub, "Error : Parsing.\n", 1);
	while (1)
	{
		if (check_is_elem(cub, line))
		{
			break ;
		}
		free(line);
		line = get_next_line(cub->fd);
		if (!line)
			free_message(cub, "Error : Parsing.\n", 1);
	}
}

void	open_file(t_cub *cub)
{
	char	*needle;

	needle = ft_strstr(cub->file, ".cub");
	if (!needle || ft_strcmp(needle, ".cub"))
		error_message("Error : Invalid map name.\n", 1);
	cub->fd = open(cub->file, O_RDWR);
	if (cub->fd == -1)
		error_message("Error : File doesn't exist.\n", 1);
}

int	recove_x_size(t_cub *cub)
{
	int		size;
	char	*str;
	int		fd;

	size = 0;
	fd = open(cub->file, O_RDONLY);
	if (fd == -1)
		free_message(cub, "error parsing\n", 1);
	str = get_next_line(fd);
	while (str && (check_is_elem(cub, str) || str[0] == '\n'))
	{
		if (str)
			free(str);
		str = get_next_line(fd);
	}
	while (str)
	{
		if (ft_strlen(str) > (size_t)size)
			size = ft_strlen(str);
		if (str)
			free(str);
		str = get_next_line(fd);
		cub->size_y++;
	}
	close(fd);
	return (size);
}


void	parse_map(t_cub *cub)
{
	open_file(cub);
	get_file(cub);
	cub->size_x = recove_x_size(cub);
	printf("x = %d, y = %d\n", cub->size_x, cub->size_y);
	close(cub->fd);
}
