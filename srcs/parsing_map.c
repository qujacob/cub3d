#include "cub3d.h"

void	create_map(t_cub *cub)
{
	int		x;

	x = -1;
	cub->map = (char **)malloc(sizeof(char *) * (cub->size_y + 1));
	if (!cub->map)
		error_message("Error : malloc problems.\n", 1);
	cub->map[cub->size_y] = NULL;
	while (++x < cub->size_y)
	{
		cub->map[x] = malloc(cub->size_x + 1);
		if (!cub->map[x])
			error_message("Error : malloc problems.\n", 1);
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
			if ( i >= (int)ft_strlen(line) || line[i] == ' ')
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
