#include "cub3d.h"

void	open_file(t_cub *cub)
{
	char	*needle;

	needle = ft_strstr(cub->file, ".cub");
	if (!needle || ft_strcmp(needle, ".cub"))
		error_message("Error : Invalid map name.\n", 1);
	cub->fd = open(cub->file, O_RDWR);
	if (cub->fd == -1)
		error_message("Error : File doesn't exist.\n", 1);
}

void	parse_map(t_cub *cub)
{
	open_file(cub);	
	close(cub->fd);
}
