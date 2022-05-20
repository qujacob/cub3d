#ifndef STRUCTS_H
# define STRUCTS_H


typedef struct s_cub t_cub;
typedef struct s_img t_img;
typedef struct s_mlx t_mlx;
typedef struct s_wall t_wall;
typedef struct s_vec t_vec;
typedef struct s_man t_man;
typedef struct s_ray t_ray;
typedef enum e_side	t_side;

enum e_side
{
	NO,
	EA,
	SO,
	WE
};

struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
	int		color;
	int		height;
	int		width;
};

struct s_vec
{
	double	x;
	double	y;
};

struct s_ray
{
	t_vec	cam;
	t_vec	dir;
	t_vec	map;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	t_vec	side_dist;
	t_vec	delta_dist;
	double	wall_dist;
	int		hit;
	t_side	side;
	int		line_height;
	int		wall_start;
	int		wall_end;

	double	wall_x;
};

struct s_man
{
	t_vec	pos;
	t_vec	plane;
	t_vec	dir;
	double	movespeed;
	double	rotspeed;
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
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
	char	*f;
	char	*c;
	int		*f_tab;
	int		*c_tab;
};

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
	t_img	img;
	t_ray	ray;
	t_man	man;
	int		key_w;
	int		key_s;
	int		key_d;
	int		key_a;
	int		key_l;
	int		key_r;
};

#endif
