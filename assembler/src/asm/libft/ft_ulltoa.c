/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 00:17:00 by ishyian           #+#    #+#             */
/*   Updated: 2019/02/22 00:20:10 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft.h"

static void		calc(unsigned long long n, char *res)
{
	long long	tmp;

	if (n > 10 - 1)
	{
		tmp = n % 10;
		n = n / 10;
		calc(n, res - 1);
	}
	else
		tmp = n % 10;
	*res = '0' + tmp;
}

char			*ft_ulltoa(unsigned long long n)
{
	char	*res;
	char	*first;
	short	len;

	len = ft_unumlen(n);
	res = malloc(len + 1);
	first = res;
	res += len - 1;
	calc(n, res);
	first[len] = '\0';
	return (first);
}
