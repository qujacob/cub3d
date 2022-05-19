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
	cub->man.dir.x = 0;
	cub->man.dir.y = 1;
	cub->man.plane.x = 0.66;
	cub->man.plane.y = 0;
}

void	xpm_to_img(t_cub *cub, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(cub->mlx->ptr, path, &img->width, \
	&img->height);
	if (!img->img)
		free_message(cub, "Error : Textures.\n", 1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line, \
	&img->endian);
	if (!img->addr)
		free_message(cub, "Error : Textures.\n", 1);
}

void	set_walls(t_cub *cub)
{
	xpm_to_img(cub, &cub->wall->north, cub->wall->no);
	xpm_to_img(cub, &cub->wall->south, cub->wall->so);
	xpm_to_img(cub, &cub->wall->west, cub->wall->we);
	xpm_to_img(cub, &cub->wall->east, cub->wall->ea);
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
	cub->img.img = mlx_new_image(cub->mlx->ptr, cub->mlx->win_w, \
	cub->mlx->win_h);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bpp, \
	&cub->img.line, &cub->img.endian);
	set_walls(cub);
	draw(cub);
	mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win, cub->img.img, 0, 0);
	mlx_destroy_image(cub->mlx->ptr, cub->img.img);
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
