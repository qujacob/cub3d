#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * \
	(img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

char	*ft_strdup_no_nl(char *str)
{
	int		i;
	char	*final;

	if (!str)
		return (NULL);
	final = malloc(sizeof(char) * ft_strlen(str));
	if (!final)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		final[i] = str[i];
		i++;
	}
	final[i] = '\0';
	return (final);
}
