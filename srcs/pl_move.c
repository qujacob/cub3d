#include "cub3d.h"

void	go_forward(t_cub *cub)
{
	if (cub->map[(int)cub->man.pos.y][(int)(cub->man.pos.x + (cub->man.dir.x * cub->man.movespeed * 2))] != '1')
		cub->man.pos.x += cub->man.dir.x * cub->man.movespeed;
	if (cub->map[(int)(cub->man.pos.y + (cub->man.dir.y * cub->man.movespeed * 2))][(int)(cub->man.pos.x)] != '1')
		cub->man.pos.y+= cub->man.dir.y * cub->man.movespeed;
	return ;
}

void	go_backward(t_cub *cub)
{
	if (cub->map[(int)(cub->man.pos.y)][(int)(cub->man.pos.x - \
	(cub->man.dir.x * cub->man.movespeed * 2))] != '1')
			cub->man.pos.x -= cub->man.dir.x * cub->man.movespeed;
	if (cub->map[(int)(cub->man.pos.y - (cub->man.dir.y * \
	cub->man.movespeed * 2))][(int)(cub->man.pos.x)] != '1')
			cub->man.pos.y -= cub->man.dir.y * cub->man.movespeed;
}

void	go_left(t_cub *cub)
{
		if (cub->map[(int)cub->man.pos.y][(int)(cub->man.pos.x - cub->man.dir.y * (cub->man.movespeed * 2))] != '1')
			cub->man.pos.x -= cub->man.dir.y * cub->man.movespeed;
		if (cub->map[(int)(cub->man.pos.y + cub->man.dir.x * (cub->man.movespeed * 2))][(int)cub->man.pos.x] != '1')
			cub->man.pos.y += cub->man.dir.x * cub->man.movespeed;
		return ;
}

void	go_right(t_cub *cub)
{
	if (cub->map[(int)cub->man.pos.y][(int)(cub->man.pos.x + cub->man.dir.y * (cub->man.movespeed * 2))] != '1')
			cub->man.pos.x += cub->man.dir.y * cub->man.movespeed;
	if (cub->map[(int)(cub->man.pos.y - cub->man.dir.x * (cub->man.movespeed * 2))][(int)cub->man.pos.x] != '1')
			cub->man.pos.y -= cub->man.dir.x * cub->man.movespeed;
	return ;
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
