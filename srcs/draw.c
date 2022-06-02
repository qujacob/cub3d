/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:08:44 by qujacob           #+#    #+#             */
/*   Updated: 2022/06/02 13:45:59 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_dist(t_cub *cub)
{
	if (cub->ray.side == WE || cub->ray.side == EA)
		cub->ray.wall_dist = (cub->ray.mapx - cub->man.pos.x
				+ (1 - cub->ray.stepx) / 2) / cub->ray.dir.x;
	else if (cub->ray.side == NO || cub->ray.side == SO)
		cub->ray.wall_dist = (cub->ray.mapy - cub->man.pos.y
				+ (1 - cub->ray.stepy) / 2) / cub->ray.dir.y;
	cub->ray.line_height = (int)(cub->mlx->win_h / cub->ray.wall_dist);
	cub->ray.wall_start = -cub->ray.line_height / 2 + cub->mlx->win_h / 2;
	cub->ray.wall_end = cub->ray.line_height / 2 + cub->mlx->win_h / 2;
	if (cub->ray.side == WE || cub->ray.side == EA)
		cub->ray.wall_x = cub->man.pos.y + cub->ray.wall_dist
			* cub->ray.dir.y;
	else
		cub->ray.wall_x = cub->man.pos.x + cub->ray.wall_dist
			* cub->ray.dir.x;
	cub->ray.wall_x -= floor(cub->ray.wall_x);
}

void	loop_hit(t_cub *cub)
{
	while (cub->ray.hit == FALSE)
	{
		if (cub->ray.side_dist.x < cub->ray.side_dist.y)
		{
			cub->ray.side_dist.x += cub->ray.delta_dist.x;
			cub->ray.mapx += cub->ray.stepx;
			if (cub->ray.dir.x > 0)
				cub->ray.side = EA;
			else
				cub->ray.side = WE;
		}
		else
		{
			cub->ray.side_dist.y += cub->ray.delta_dist.y;
			cub->ray.mapy += cub->ray.stepy;
			if (cub->ray.dir.y > 0)
				cub->ray.side = SO;
			else
				cub->ray.side = NO;
		}
		if (cub->map[cub->ray.mapy][cub->ray.mapx] == '1')
			cub->ray.hit = TRUE;
	}
}

void	calcul_raydis(t_cub *cub)
{
	if (cub->ray.dir.x < 0)
	{
		cub->ray.stepx = -1;
		cub->ray.side_dist.x = (cub->man.pos.x - cub->ray.mapx)
			* cub->ray.delta_dist.x;
	}
	else
	{
		cub->ray.stepx = 1;
		cub->ray.side_dist.x = (cub->ray.mapx + 1.0 - cub->man.pos.x)
			* cub->ray.delta_dist.x;
	}
	if (cub->ray.dir.y < 0)
	{
		cub->ray.stepy = -1;
		cub->ray.side_dist.y = (cub->man.pos.y - cub->ray.mapy)
			* cub->ray.delta_dist.y;
	}
	else
	{
		cub->ray.stepy = 1;
		cub->ray.side_dist.y = (cub->ray.mapy + 1.0 - cub->man.pos.y)
			* cub->ray.delta_dist.y;
	}
}

void	draw(t_cub *cub)
{
	int	x;

	x = 0;
	while (x < cub->mlx->win_w)
	{
		cub->ray.hit = FALSE;
		cub->ray.cam.x = 2 * x / (double)cub->mlx->win_w - 1;
		cub->ray.dir.x = -(cub->man.dir.x + cub->man.plane.x * cub->ray.cam.x);
		cub->ray.dir.y = cub->man.dir.y + cub->man.plane.y * cub->ray.cam.x;
		cub->ray.hit = FALSE;
		cub->ray.mapx = (int)cub->man.pos.x;
		cub->ray.mapy = (int)cub->man.pos.y;
		cub->ray.delta_dist.x = fabs(1 / cub->ray.dir.x);
		cub->ray.delta_dist.y = fabs(1 / cub->ray.dir.y);
		calcul_raydis(cub);
		loop_hit(cub);
		wall_dist(cub);
		put_in_display(cub, x);
		x++;
	}
	minimap(cub);
	mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win, cub->img.img, 0, 0);
}
