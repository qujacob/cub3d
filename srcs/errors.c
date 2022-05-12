#include "cub3d.h"

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	free_cub(t_cub *cub)
{
	if (cub->map)
		free_map(cub->map);
	free(cub->no);
	free(cub->so);
	free(cub->we);
	free(cub->ea);
	free(cub->f);
	free(cub->c);
}

void	error_message(char *message, int ret)
{
	ft_putstr_fd(message, 2);
	exit(ret);
}

void	free_message(t_cub *cub, char *message, int ret)
{
	free_cub(cub);
	error_message(message, ret);
}
