#include "cub3d.h"

void	error_message(char *message, int ret)
{
	ft_putstr_fd(message, 2);
	exit(ret);
}