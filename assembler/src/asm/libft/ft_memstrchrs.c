/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memstrchrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:47:14 by ishyian           #+#    #+#             */
/*   Updated: 2019/02/22 04:24:09 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

/*
** Function searching chars from *chrs in *mem, if found at least one, malloc
** and returns string with all founded chars.
** If found nothing, function returns NULL.
*/

char		*ft_memstrchrs(const void *mem, const char *chrs, size_t n)
{
	char	*ret;
	char	*ret_start;
	char	curr;

	ret_start = NULL;
	while (*chrs)
	{
		curr = *chrs;
		if (ft_memchr(mem, curr, n))
		{
			if (!ret)
			{
				ret = malloc(ft_strlen(chrs));
				ret_start = ret;
			}
			*ret = curr;
			ret++;
		}
		chrs++;
	}
	return (ret_start);
}
