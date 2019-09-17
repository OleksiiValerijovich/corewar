/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 04:21:04 by ishyian           #+#    #+#             */
/*   Updated: 2019/02/22 04:21:15 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft.h"

static char		cnv(unsigned int n)
{
	if (n <= 9)
		return ('0' + n);
	else
		return ('a' + n - 10);
}

static void		calc(unsigned int n, char *res, unsigned int base)
{
	unsigned int	tmp;

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

char			*ft_uitoa_base(unsigned int n, int base)
{
	char			*res;
	char			*first;
	short			len;

	len = ft_unumlen_base(n, base);
	res = malloc(len + 1);
	first = res;
	res += len - 1;
	calc(n, res, (unsigned int)base);
	first[len] = '\0';
	return (first);
}
