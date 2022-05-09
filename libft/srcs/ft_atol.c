/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:56:03 by qujacob           #+#    #+#             */
/*   Updated: 2022/03/10 19:35:30 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long	ft_atol(const char *str)
{
	long	neg;
	long	res;
	int		count;

	while (ft_isspace(*str))
		str++;
	neg = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	res = 0;
	count = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str++ - '0';
		count++;
	}
	return (res * neg);
}
