#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_cub t_cub;

struct s_cub
{
	char	*file;
	int		fd;
	char	**map;
	int		size_x;
	int		size_y;
	char	player;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
};

#endif
