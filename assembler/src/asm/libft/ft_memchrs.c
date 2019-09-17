/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:37:25 by ishyian           #+#    #+#             */
/*   Updated: 2019/02/20 00:28:35 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

/*
** Function searching chars in *mem from *chrs. If found one, returns pointer
** to it. If found a few, returns pointer to the very first. Else, return NULL.
*/

void		*ft_memchrs(const void *mem, const char *chrs, size_t size)
{
	char	curr;
	void	*ret;
	void	*res;

	res = NULL;
	while (*chrs)
	{
		curr = *chrs;
		if ((ret = ft_memchr(mem, curr, size)))
		{
			if (!res)
				res = ret;
			else if (res > ret)
				res = ret;
		}
		chrs++;
	}
	return (ret);
}
