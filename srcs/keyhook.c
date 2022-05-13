#include "cub3d.h"

int	quit(t_cub *cub)
{
	if (cub->mlx->ptr)
	{
		if (cub->mlx->win)
			mlx_destroy_window(cub->mlx->ptr, cub->mlx->win);
		mlx_destroy_display(cub->mlx->ptr);
	}
	free_message(cub, "Goodbye !\n", 0);
	return (1);
}

int	select_action(int key, t_cub *cub)
{
	if (key == ESC || key == QUIT)
		quit(cub);
	return (0);
}
