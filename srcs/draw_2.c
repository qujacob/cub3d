/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:08:50 by qujacob           #+#    #+#             */
/*   Updated: 2022/05/23 17:57:59 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rgb(t_cub *cub, int color[3], int y, int x)
{
	if (cub->img.endian == 1)
	{
		cub->img.addr[(x * cub->img.bpp >> 3) + y * cub->img.line] = color[0];
		cub->img.addr[(x * cub->img.bpp >> 3) + 1 + \
		y * cub->img.line] = color[1];
		cub->img.addr[(x * cub->img.bpp >> 3) + 2 + \
		y * cub->img.line] = color[2];
	}
	else
	{
		cub->img.addr[(x * cub->img.bpp >> 3) + y * cub->img.line] = color[2];
		cub->img.addr[(x * cub->img.bpp >> 3) + 1 + \
		y * cub->img.line] = color[1];
		cub->img.addr[(x * cub->img.bpp >> 3) + 2 + \
		y * cub->img.line] = color[0];
	}
}

void	draw_wall(t_cub *cub, t_img *tex, int y, int x)
{
	cub->img.addr[(x * cub->img.bpp >> 3)
		+ y * cub->img.line]
		= tex->addr[(int)(cub->ray.wall_x * tex->width) * (tex->bpp >> 3)
		+ (int)((y - cub->ray.wall_start * 1.0) / cub->ray.line_height
			* tex->height) *tex->line];
	cub->img.addr[(x * cub->img.bpp >> 3)
		+ 1 + y * cub->img.line]
		= tex->addr[(int)(cub->ray.wall_x * tex->width) * (tex->bpp >> 3)
		+ 1 + (int)((y - cub->ray.wall_start * 1.0)
			/ cub->ray.line_height * tex->height) *tex->line];
	cub->img.addr[(x * cub->img.bpp >> 3)
		+ 2 + y * cub->img.line]
		= tex->addr[(int)(cub->ray.wall_x * tex->width) * (tex->bpp >> 3)
		+ 2 + (int)((y - cub->ray.wall_start * 1.0)
			/ cub->ray.line_height * tex->height) *tex->line];
}

void	draw_tmp(t_cub *cub, int y, int x)
{
	if (cub->ray.side == NO)
		draw_wall(cub, &cub->wall->north, y, x);
	else if (cub->ray.side == SO)
		draw_wall(cub, &cub->wall->south, y, x);
	else if (cub->ray.side == WE)
		draw_wall(cub, &cub->wall->west, y, x);
	else if (cub->ray.side == EA)
		draw_wall(cub, &cub->wall->east, y, x);
}

void	set_stop(t_cub *cub, int *start, int *end)
{
	if (cub->ray.wall_start < 0)
		*start = 0;
	else
		*start = cub->ray.wall_start;
	if (cub->ray.wall_end >= cub->mlx->win_h)
		*end = cub->mlx->win_h - 1;
	else
		*end = cub->ray.wall_end;
}

void	put_in_display(t_cub *cub, int x)
{
	int	y;
	int	start;
	int	end;

	y = 0;
	set_stop(cub, &start, &end);
	while (y < start)
	{
		draw_rgb(cub, cub->wall->c_tab, y, x);
		y++;
	}
	while (y < end)
	{
		draw_tmp(cub, y, x);
		y++;
	}
	while (y < cub->mlx->win_h - 1)
	{
		draw_rgb(cub, cub->wall->f_tab, y, x);
		y++;
	}
}
