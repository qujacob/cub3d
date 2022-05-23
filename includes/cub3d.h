#ifndef CUB3D_H
# define CUB3D_H

/*
**		┌----------------------------------------------------------------┐
**		|				 												 |
**		|			 			INCLUDE AND DEFINE						 |
**		|				 												 |
**		└----------------------------------------------------------------┘
*/

# include "mlx.h"
# include "libft.h"
# include "structs.h"
# include <math.h>
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
# define K_W 119
# define K_S 115
# define K_D 100
# define K_A 97

/*
**		┌----------------------------------------------------------------┐
**		|				 												 |
**		|			 			FUNCTION PROTOTYPE						 |
**		|				 												 |
**		└----------------------------------------------------------------┘
*/

void	parse_file(t_cub *cub);
int		check_is_elem(char *line);

int		is_a_player(char c);
void	create_map(t_cub *cub);
int		recove_x_size(t_cub *cub);
int		check_is_map(char *line);
int		fill_map(t_cub *cub, char **line);

void	check_validity(t_cub *cub);

void	draw(t_cub *cub);
void	put_in_display(t_cub *cub, int x);

int		quit(t_cub *cub);
int		select_action(int key, t_cub *cub);
int		key_pressed(t_cub *cub);
int		key_released(int key, t_cub *cub);

void	free_cub(t_cub *cub);
void	error_message(char *message, int ret);
void	free_message(t_cub *cub, char *message, int ret);

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
char	*ft_strdup_no_nl(char *str);

void	go_forward(t_cub *cub);
void	go_backward(t_cub *cub);
void	go_left(t_cub *cub);
void	go_right(t_cub *cub);
void	set_player_pos(t_cub *cub);

void	rot_left(t_cub *cub);
void	rot_right(t_cub *cub);

#endif
