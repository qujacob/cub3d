/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:09:00 by qujacob           #+#    #+#             */
/*   Updated: 2022/06/02 13:43:56 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	go_forward(t_cub *cub)
{
	if (cub->map[(int)cub->man.pos.y][(int)(cub->man.pos.x - \
	(cub->man.dir.x * cub->man.movespeed * 2))] != '1')
		cub->man.pos.x -= cub->man.dir.x * cub->man.movespeed;
	if (cub->map[(int)(cub->man.pos.y + (cub->man.dir.y * \
	cub->man.movespeed * 2))][(int)(cub->man.pos.x)] != '1')
		cub->man.pos.y += cub->man.dir.y * cub->man.movespeed;
}

void	go_backward(t_cub *cub)
{
	if (cub->map[(int)(cub->man.pos.y)][(int)(cub->man.pos.x + \
	(cub->man.dir.x * cub->man.movespeed * 2))] != '1')
			cub->man.pos.x += cub->man.dir.x * cub->man.movespeed;
	if (cub->map[(int)(cub->man.pos.y - (cub->man.dir.y * \
	cub->man.movespeed * 2))][(int)(cub->man.pos.x)] != '1')
			cub->man.pos.y -= cub->man.dir.y * cub->man.movespeed;
}

void	go_left(t_cub *cub)
{
	if (cub->map[(int)cub->man.pos.y][(int)(cub->man.pos.x + \
	cub->man.dir.y * (cub->man.movespeed * 2))] != '1')
		cub->man.pos.x += cub->man.dir.y * cub->man.movespeed;
	if (cub->map[(int)(cub->man.pos.y + (cub->man.dir.x * \
	cub->man.movespeed * 2))][(int)cub->man.pos.x] != '1')
		cub->man.pos.y += cub->man.dir.x * cub->man.movespeed;
}

void	go_right(t_cub *cub)
{
	if (cub->map[(int)cub->man.pos.y][(int)(cub->man.pos.x - \
	cub->man.dir.y * (cub->man.movespeed * 2))] != '1')
			cub->man.pos.x -= cub->man.dir.y * cub->man.movespeed;
	if (cub->map[(int)(cub->man.pos.y - (cub->man.dir.x * \
	cub->man.movespeed * 2))][(int)cub->man.pos.x] != '1')
			cub->man.pos.y -= cub->man.dir.x * cub->man.movespeed;
}

void	set_player_pos(t_cub *cub)
{
	if (cub->player == 'N')
	{
		cub->man.dir.y = -1;
		cub->man.plane.x = -0.66;
	}
	else if (cub->player == 'S')
	{
		cub->man.dir.y = 1;
		cub->man.plane.x = 0.66;
	}
	else if (cub->player == 'E')
	{
		cub->man.dir.x = -1;
		cub->man.plane.y = 0.66;
	}
	else if (cub->player == 'W')
	{
		cub->man.dir.x = 1;
		cub->man.plane.y = -0.66;
	}
}
