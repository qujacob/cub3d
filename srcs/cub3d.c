#include "cub3d.h"

void	init_cub(t_cub *cub, char *file)
{
	*cub = (t_cub){.file = file};
	cub->wall = malloc(sizeof(t_wall));
	if (!cub->wall)
		free_message(cub, "Error : Malloc.\n", 1);
	*cub->wall = (t_wall){0};
	cub->mlx = malloc(sizeof(t_mlx));
	if (!cub->mlx)
		free_message(cub, "Error : Malloc.\n", 1);
	*cub->mlx = (t_mlx){.win_w = 1920, .win_h = 1080};
	cub->img = malloc(sizeof(t_img));
	if (!cub->img)
		free_message(cub, "Error : Malloc.\n", 1);
	*cub->img = (t_img){0};
}

void	draw(t_cub *cub)
{
	int	j;
	int	i;
	int	four;
	int	five;

	j = -1;
	while (++j < cub->size_y)
	{
		i = -1;
		while (++i < cub->size_x)
		{
			four = -1;
			while (++four < 20)
			{
				five = -1;
				while (++five < 20)
				{
					if (cub->map[j][i] == '1')
						my_mlx_pixel_put(cub->img, (20 * i) + five, (20 * j) + four, 0x00FF0000);
					else if (cub->map[j][i] == '0')
						my_mlx_pixel_put(cub->img, (20 * i) + five, (20 * j) + four, 0x00FFFFFF);
					else if (is_a_player(cub->map[j][i]))
						my_mlx_pixel_put(cub->img, (20 * i) + five, (20 * j) + four, 0x00FFFF00);
				}
			}
		}
	}
}

void	open_cub3d(t_cub *cub)
{
	cub->mlx->ptr = mlx_init();
	if (!cub->mlx->ptr)
		free_message(cub, "Error : Couldn't initialize MLX. Try again.\n", 1);
	cub->mlx->win = mlx_new_window(cub->mlx->ptr, cub->mlx->win_w, \
	cub->mlx->win_h, "CUB3D");
	mlx_hook(cub->mlx->win, 2, 1L<<0, select_action, cub);
	mlx_hook(cub->mlx->win, 17, 1L<<17, quit, cub);
	cub->img->img = mlx_new_image(cub->mlx->ptr, cub->mlx->win_w, \
	cub->mlx->win_h);
	cub->img->addr = mlx_get_data_addr(cub->img->img, \
	&(cub->img->bits_per_pixel), &(cub->img->line_length), \
	&(cub->img->endian));
	draw(cub);
	mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win, cub->img->img, 0, 0);
	mlx_destroy_image(cub->mlx->ptr, cub->img->img);
	mlx_loop(cub->mlx->ptr);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac == 1 || ac > 2)
		error_message("Error.\nUsage : \"./cub3D [file].cub\"\n", 1);
	init_cub(&cub, av[1]);
	parse_file(&cub);
	open_cub3d(&cub);
	free_cub(&cub);
	return (0);
}
