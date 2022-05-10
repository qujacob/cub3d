#include "cub3d.h"

void	create_map(t_cub *cub)
{
	int		x;

	x = -1;
	cub->map = (char **)malloc(sizeof(char *) * cub->size_y);
	if (!cub->map)
		error_message("Error : malloc problems.\n", 1);
	while (++x < cub->size_x)
	{
		cub->map[x] = malloc(cub->size_x + 1);
		if (!cub->map[x])
			error_message("Error : malloc problems.\n", 1);
	}
}

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

int	check_is_map(t_cub *cub, char *line)
{
	int	i;
	(void)cub;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1' && \
		line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

int	fill_map(t_cub *cub, char *line)
{
	int	i;
	int	j;

	j = -1;
	if (!check_is_map(cub, line))
		return (0);
	create_map(cub);
	if (cub->map)
	while(++j < cub->size_y && line)
	{
		i = -1;
		while (++i < cub->size_x)
		{
			if (line[i] == ' ' || i >= (int)ft_strlen(line))
				cub->map[j][i] = '3';
			else if (line[i] != '\n')
				cub->map[j][i] = line[i];
		}
		cub->map[j][i] = '\0';
		if (line)
			free(line);
		line = get_next_line(cub->fd);
	}
	return (1);
}

void	get_file(t_cub *cub)
{
	char	*line;

	line = get_next_line(cub->fd);
	while (line)
	{
		if (cub->map)
			free_message(cub, "Error : Parsing4\n", 1);
		if (!check_is_elem(cub, line))
		{
			if (fill_map(cub, line) == -1)
			{
				free(line);
				free_message(cub, "Error : Parsing3\n", 1);
			}
		}
		else if (!check_is_elem(cub, line) && line[0] != '\n')
		{
			free(line);
			free_message(cub, "Error : Parsing1\n", 1);
		}
		if (line)
			free(line);
		line = get_next_line(cub->fd);
	}
	if (!cub->map)
		free_message(cub, "Error : Parsing2\n", 1);
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

void	parse_map(t_cub *cub)
{
	open_file(cub);
	cub->size_x = recove_x_size(cub);
	get_file(cub);
	for (int i = 0; i < cub->size_y; i++)
		printf("%s\n",cub->map[i]);

	close(cub->fd);
}
