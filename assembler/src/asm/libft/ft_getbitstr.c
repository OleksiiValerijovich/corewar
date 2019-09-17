/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbitstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:21:08 by ishyian           #+#    #+#             */
/*   Updated: 2019/08/14 10:48:07 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static void		write_bits(char **bits, const unsigned char byte)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (byte & (1 << (8 - (i + 1))))
			**bits = '1';
		else
			**bits = '0';
		(*bits)++;
		i++;
	}
}

char			*ft_getbitstr(const void *p, size_t size)
{
	char	*bits;
	size_t	len;

	bits = ft_smalloc(size * 8 + 1);
	bits[size * 8] = '\0';
	len = size * 8;
	while (size > 0)
	{
		write_bits(&bits, *(const unsigned char*)p);
		size--;
		p++;
	}
	return (bits - len);
}
