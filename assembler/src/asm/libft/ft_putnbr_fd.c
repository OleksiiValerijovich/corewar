/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:31:43 by ishyian           #+#    #+#             */
/*   Updated: 2018/12/02 21:32:42 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void		rec(int n, int sign, int fd)
{
	char		tmp;

	if (n > 9 || n < -9)
	{
		tmp = (n % 10 * sign) + '0';
		n = n / 10;
		rec(n, sign, fd);
		ft_putchar_fd(tmp, fd);
	}
	else
		ft_putchar_fd(((n % 10 * sign) + '0'), fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	int		sign;

	if (fd != -1)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			sign = -1;
		}
		else
			sign = 1;
		rec(n, sign, fd);
	}
}
