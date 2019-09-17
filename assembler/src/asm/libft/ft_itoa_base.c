/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 04:26:32 by ishyian           #+#    #+#             */
/*   Updated: 2019/02/22 04:26:33 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft.h"

static char		cnv(int n)
{
	if (n <= 9)
		return ('0' + n);
	else
		return ('a' + n - 10);
}

static void		calc(int n, char *res, short sign, int base)
{
	int		tmp;

	if (n > base - 1 || (base == 10 && n < -9))
	{
		tmp = n % base * sign;
		n = n / base;
		calc(n, res - 1, sign, base);
	}
	else
		tmp = n % base * sign;
	*res = cnv(tmp);
}

char			*ft_itoa_base(int n, int base)
{
	char	*res;
	char	*first;
	short	len;
	short	sign;

	sign = 1;
	len = ft_numlen_base(n, base);
	if (n < 0)
	{
		len += base == 10 ? 1 : 0;
		sign = -1;
	}
	res = malloc(len + 1);
	first = res;
	if (n < 0 && base == 10)
		*res = '-';
	res += len - 1;
	calc(n, res, sign, base);
	first[len] = '\0';
	return (first);
}
