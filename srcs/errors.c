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
	if (cub->wall)
	{
		free(cub->wall->no);
		free(cub->wall->so);
		free(cub->wall->we);
		free(cub->wall->ea);
		free(cub->wall->f);
		free(cub->wall->c);
		free(cub->wall->f_tab);
		free(cub->wall->c_tab);
		free(cub->wall);
	}
	if (cub->mlx)
	{
		free(cub->mlx->ptr);
		free(cub->mlx);
	}
	// if (cub->img)
	// 	free(cub->img);
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
