#include "cub3d.h"

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (++i)
		free(map[i]);
	free(map);
}

void	free_cub(t_cub *cub)
{
	if (cub->map)
		free_map(cub->map);
	if (cub->no)
		free(cub->no);
	if (cub->so)
		free(cub->so);
	if (cub->we)
		free(cub->we);
	if (cub->ea)
		free(cub->ea);
	if (cub->f)
		free(cub->f);
	if (cub->c)
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
