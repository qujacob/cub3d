#include "cub3d.h"

void    check_elem(t_cub *cub)
{
    if (!cub->data.no || !cub->data.so || !cub->data.we || !cub->data.ea)
        free_message(cub, "Error : Textures.\n", 1);
    if (open(cub->data.no, O_RDONLY) == -1)
        free_message(cub, "Error : Textures.\n", 1);
    if (open(cub->data.so, O_RDONLY) == -1)
        free_message(cub, "Error : Textures.\n", 1);
    if (open(cub->data.we, O_RDONLY) == -1)
        free_message(cub, "Error : Textures.\n", 1);
    if (open(cub->data.ea, O_RDONLY) == -1)
        free_message(cub, "Error : Textures.\n", 1);
}

void	check_validity(t_cub *cub)
{
    int i;
	int	j;

    check_elem(cub);
	j = -1;
	while (++j < cub->size_y)
	    if (check_is_map(cub->map[j]) < 1)
            free_message(cub, "Error : Unvalid Map.\n", 1);
    j = -1;
    while (++j < cub->size_y)
    {
        i = -1;
        while (++i < cub->size_x)
        {
            break ;
        }
    }
}
