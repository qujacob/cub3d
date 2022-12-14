/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:09:18 by qujacob           #+#    #+#             */
/*   Updated: 2022/06/02 13:42:06 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rot_left(t_cub *cub)
{
	double		old_dirx;
	double		old_planex;

	old_dirx = cub->man.dir.x;
	old_planex = cub->man.plane.x;
	cub->man.dir.x = cub->man.dir.x * cos(cub->man.rotspeed)
		- cub->man.dir.y * sin(cub->man.rotspeed);
	cub->man.dir.y = old_dirx * sin(cub->man.rotspeed)
		+ cub->man.dir.y * cos(cub->man.rotspeed);
	cub->man.plane.x = cub->man.plane.x * cos(cub->man.rotspeed)
		- cub->man.plane.y * sin(cub->man.rotspeed);
	cub->man.plane.y = old_planex * sin(cub->man.rotspeed)
		+ cub->man.plane.y * cos(cub->man.rotspeed);
}

void	rot_right(t_cub *cub)
{
	double		old_dirx;
	double		old_planex;

	old_dirx = cub->man.dir.x;
	old_planex = cub->man.plane.x;
	cub->man.dir.x = cub->man.dir.x * cos(-cub->man.rotspeed)
		- cub->man.dir.y * sin(-cub->man.rotspeed);
	cub->man.dir.y = old_dirx * sin(-cub->man.rotspeed)
		+ cub->man.dir.y * cos(-cub->man.rotspeed);
	cub->man.plane.x = cub->man.plane.x * cos(cub->man.rotspeed)
		- cub->man.plane.y * sin(-cub->man.rotspeed);
	cub->man.plane.y = old_planex * sin(-cub->man.rotspeed)
		+ cub->man.plane.y * cos(-cub->man.rotspeed);
}
