#include "cub3d.h"

int	quit(t_cub *cub)
{
	if (cub->mlx->ptr)
	{
		if (cub->mlx->win)
		{
			if (cub->img.img)
				mlx_destroy_image(cub->mlx->ptr, cub->img.img);
			mlx_destroy_image(cub->mlx->ptr, cub->wall->north.img);
			mlx_destroy_image(cub->mlx->ptr, cub->wall->south.img);
			mlx_destroy_image(cub->mlx->ptr, cub->wall->west.img);
			mlx_destroy_image(cub->mlx->ptr, cub->wall->east.img);	
		}
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
	if (key == K_W)
		cub->key_w = 1;
	else if (key == K_S)
		cub->key_s = 1;
	else if (key == K_A)
		cub->key_a = 1;
	else if (key == K_D)
		cub->key_d = 1;
	else if (key == LEFT)
		cub->key_l = 1;
	else if (key == RIGHT)
		cub->key_r = 1;
	return (0);
}

int	key_hook(t_cub *cub)
{
	if (cub->key_w == 1)
		go_forward(cub);
	else if (cub->key_s == 1)
		go_backward(cub);
	else if (cub->key_a == 1)
		go_left(cub);
	else if (cub->key_d == 1)
		go_right(cub);
	else if (cub->key_l == 1)
		rot_left(cub);
	else if (cub->key_r == 1)
		rot_right(cub); 
	return (0);
}

int	key_pressed(t_cub *cub)
{
	key_hook(cub);
	draw(cub);
	return (0);
}

int	key_released(int key, t_cub *cub)
{
	if (key == K_W)
		cub->key_w = 0;
	else if (key == K_S)
		cub->key_s = 0;
	else if (key == K_A)
		cub->key_a = 0;
	else if (key == K_D)
		cub->key_d = 0;
	else if (key == LEFT)
		cub->key_l = 0;
	else if (key == RIGHT)
		cub->key_r = 0;
	return (0);
}
