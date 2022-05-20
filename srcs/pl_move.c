#include "cub3d.h"

void	go_forward(t_cub *cub)
{
	if (cub->map[(int)(cub->man.pos.x + (cub->man.dir.x * cub->man.movespeed * 2))][(int)cub->man.pos.y] == '0')
		cub->man.pos.x += cub->man.dir.x * cub->man.movespeed;
	if (cub->map[(int)(cub->man.pos.x)][(int)(cub->man.pos.y + (cub->man.dir.y * cub->man.movespeed * 2))] == '0')
		cub->man.pos.y+= cub->man.dir.y * cub->man.movespeed;
	printf ("ok\n");
	return ;
}

void	go_backward(t_cub *cub)
{
	if (cub->map[(int)(cub->man.pos.x - (cub->man.dir.x * cub->
		man.movespeed * 2))][(int)(cub->man.pos.y)] == '0')
			cub->man.pos.x -= cub->man.dir.x * cub->man.movespeed;
	if (cub->map[(int)(cub->man.pos.x)][(int)(cub->man.pos.y -
		(cub->man.dir.y * cub->man.movespeed * 2))] == '0')
			cub->man.pos.y -= cub->man.dir.y * cub->man.movespeed;
}

void	go_left(t_cub *cub)
{
		if (cub->map[(int)(cub->man.pos.x - cub->man.dir.y * (cub->man.movespeed * 2))][(int)cub->man.pos.y] == '0')
			cub->man.pos.x -= cub->man.dir.y * cub->man.movespeed;
		if (cub->map[(int)cub->man.pos.x][(int)(cub->man.pos.y + cub->man.dir.x * (cub->man.movespeed * 2))] == '0')
			cub->man.pos.y += cub->man.dir.x * cub->man.movespeed;
		return ;
}

void	go_right(t_cub *cub)
{
	if (cub->map[(int)(cub->man.pos.x + cub->man.dir.y * (cub->man.movespeed * 2))][(int)cub->man.pos.y] == '0')
			cub->man.pos.x += cub->man.dir.y * cub->man.movespeed;
	if (cub->map[(int)cub->man.pos.x][(int)(cub->man.pos.y - cub->man.dir.x *	(cub->man.movespeed * 2))] == '0')
			cub->man.pos.y -= cub->man.dir.x * cub->man.movespeed;
	return ;
}
