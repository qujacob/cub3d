/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:09:51 by qujacob           #+#    #+#             */
/*   Updated: 2022/05/23 17:09:51 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_minimap(t_cub *cub, int i, int j)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 10)
	{
		x = -1;
		while (++x < 10)
		{
			if (cub->map[j][i] == '1')
				my_mlx_pixel_put(&(cub->img), (10 * i) + x, (10 * j) + y, \
				0x00707078);
			else if (cub->map[j][i] == '0' || is_a_player(cub->map[j][i]))
				my_mlx_pixel_put(&(cub->img), (10 * i) + x, (10 * j) + y, \
				0x00CDE6F5);
			my_mlx_pixel_put(&(cub->img), (10 * cub->man.pos.x) + x / 2, \
			(10 * cub->man.pos.y) + y / 2, 0x00FF0000);
		}
	}
}

void	minimap(t_cub *cub)
{
	int	j;
	int	i;

	j = -1;
	while (++j < cub->size_y)
	{
		i = -1;
		while (++i < cub->size_x)
			print_minimap(cub, i, j);
	}
}
