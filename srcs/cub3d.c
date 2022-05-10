#include "cub3d.h"

void	init_cub(t_cub *cub, char *file)
{
	cub->file = file;
	cub->fd = 0;
	cub->map = NULL;
	cub->size_x = 0;
	cub->size_y = 0;
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->f = NULL;
	cub->c = NULL;
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
	free_cub(&cub);
	return (0);
}
