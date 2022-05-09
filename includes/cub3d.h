#ifndef CUB3D_H
# define CUB3D_H

/*
**		┌----------------------------------------------------------------┐
**		|				 												 |
**		|			 			INCLUDE AND DEFINE						 |
**		|				 												 |
**		└----------------------------------------------------------------┘
**
*/

# include "mlx.h"
# include "libft.h"
# include "structs.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>

/*
**		┌----------------------------------------------------------------┐
**		|						DEFINE LOCAL VARIABLES					 |
**		└----------------------------------------------------------------┘
*/

# define TRUE 1
# define FALSE 0

# define ESC 65307
# define DEL 65288
# define QUIT 79708224

# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364

/*
**		┌----------------------------------------------------------------┐
**		|				 												 |
**		|			 			FUNCTION PROTOTYPE						 |
**		|				 												 |
**		└----------------------------------------------------------------┘
*/

void	parse_map(t_cub *cub);

void	error_message(char *message, int ret);

#endif
