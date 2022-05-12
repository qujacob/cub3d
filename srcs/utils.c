#include "cub3d.h"

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
