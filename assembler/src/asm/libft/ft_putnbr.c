/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:48:13 by ishyian           #+#    #+#             */
/*   Updated: 2018/12/02 21:32:25 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print(int nbr, int sign)
{
	int		tmp;

	if (nbr > 9 || nbr < -9)
	{
		tmp = (nbr % 10 * sign) + '0';
		nbr = nbr / 10;
		print(nbr, sign);
		ft_putchar(tmp);
	}
	else
		ft_putchar((nbr % 10 * sign) + '0');
}

void			ft_putnbr(int n)
{
	int		sign;

	if (n < 0)
	{
		ft_putchar('-');
		sign = -1;
	}
	else
		sign = 1;
	print(n, sign);
}
