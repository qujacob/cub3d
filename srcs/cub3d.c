#include "cub3d.h"

void	init_cub(t_cub *cub, char *file)
{
	*cub = (t_cub){.file = file};
	// cub->file = file;
	// cub->fd = 0;
	// cub->map = NULL;
	// cub->size_x = 0;
	// cub->size_y = 0;
	// cub->player = 0;
	cub->wall = malloc(sizeof(t_wall));
	if (!cub->wall)
		free_message(cub, "Error : Malloc.\n", 1);
	*cub->wall = (t_wall){0};
	cub->mlx = malloc(sizeof(t_mlx));
	if (!cub->mlx)
		free_message(cub, "Error : Malloc.\n", 1);
	*cub->mlx = (t_mlx){.win_w = 1920, .win_h = 1080};
}

void open_cub3d(t_cub *cub)
{
	cub->mlx->ptr = mlx_init();
	if (!cub->mlx->ptr)
		free_message(cub, "Error : Couldn't initialize MLX. Try again.\n", 1);
	cub->mlx->win = mlx_new_window(cub->mlx->ptr, cub->mlx->win_w, \
	cub->mlx->win_h, "CUB3D");
	mlx_loop(cub->mlx->ptr);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac == 1 || ac > 2)
	{
		printf("Error.\nUsage : \"./cub3D [file].cub\"\n");
		return (1);
	}
	init_cub(&cub, av[1]);
	parse_file(&cub);
	open_cub3d(&cub);
	free_cub(&cub);
	return (0);
}
