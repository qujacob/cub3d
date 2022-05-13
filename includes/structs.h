#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_cub t_cub;
typedef struct s_img t_img;
typedef struct s_mlx t_mlx;
typedef struct s_wall t_wall;

struct s_cub
{
	char	*file;
	int		fd;
	char	**map;
	int		size_x;
	int		size_y;
	char	player;
	t_wall	*wall;
	t_mlx	*mlx;
	t_img	*img;
};

struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
};

struct s_mlx
{
	void	*ptr;
	void	*win;
	int		win_w;
	int		win_h;
};

struct s_wall
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
};

#endif
