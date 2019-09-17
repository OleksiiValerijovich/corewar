/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 00:03:54 by ishyian           #+#    #+#             */
/*   Updated: 2019/03/13 18:45:42 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft.h"

static char		cnv(unsigned long long n)
{
	if (n <= 9)
		return ('0' + n);
	else
		return ('a' + n - 10);
}

static void		calc(unsigned long long n, char *res, unsigned int base)
{
	unsigned long long	tmp;

	if (n > base - 1)
	{
		tmp = n % base;
		n = n / base;
		calc(n, res - 1, base);
	}
	else
		tmp = n % base;
	*res = cnv(tmp);
}

char			*ft_ulltoa_base(unsigned long long n, int base)
{
	char				*res;
	char				*first;
	short				len;

	len = ft_unumlen_base(n, base);
	res = malloc(len + 1);
	first = res;
	res += len - 1;
	calc(n, res, (unsigned int)base);
	first[len] = '\0';
	return (first);
}
