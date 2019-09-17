/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:40:49 by ishyian           #+#    #+#             */
/*   Updated: 2018/12/02 22:46:34 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	i = -1;
	if (dst < src && len > 0)
		while (++i < len)
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
	else
		while (len-- != 0)
			((unsigned char*)dst)[len] = ((unsigned char*)src)[len];
	return (dst);
}
