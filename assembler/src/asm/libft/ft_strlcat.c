/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:19:55 by ishyian           #+#    #+#             */
/*   Updated: 2018/12/02 22:49:36 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ii;
	size_t	lend;
	size_t	lens;

	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	if (lend >= dstsize)
		return (dstsize + lens);
	i = 0;
	ii = 0;
	while (dst[i] != '\0')
		i++;
	while (src[ii] != '\0' && ii < (dstsize - lend - 1))
	{
		dst[i] = src[ii];
		i++;
		ii++;
	}
	dst[i] = '\0';
	return (lend + lens);
}
