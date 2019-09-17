/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrchrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:37:25 by ishyian           #+#    #+#             */
/*   Updated: 2019/06/21 22:49:34 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

/*
** Function searching chars from *chrs in *s, if found at least one, malloc and
** returns string with all founded chars.
** If found nothing, function returns NULL.
*/

char		*ft_strstrchrs(const char *s, const char *chrs)
{
	char	*ret;
	char	*ret_start;

	ret = NULL;
	ret_start = NULL;
	while (*chrs)
	{
		if (ft_strchr(s, *chrs))
		{
			if (!ret)
			{
				ret = malloc(ft_strlen(chrs) + 1);
				ft_bzero(ret, ft_strlen(chrs) + 1);
				ret_start = ret;
			}
			*ret = *chrs;
			ret++;
		}
		chrs++;
	}
	return (ret_start);
}
