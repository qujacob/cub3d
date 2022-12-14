/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:02:50 by qujacob           #+#    #+#             */
/*   Updated: 2021/07/29 15:08:17 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbru(unsigned int nb)
{
	if (nb >= 10)
		ft_putnbru(nb / 10);
	nb %= 10;
	nb += '0';
	ft_putchar(nb);
}
