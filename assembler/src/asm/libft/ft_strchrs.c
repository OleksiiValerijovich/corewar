/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:37:25 by ishyian           #+#    #+#             */
/*   Updated: 2019/06/22 10:35:26 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/*
** Function searching chars in *s from *chrs. If found one, returns pointer
** to it. If found a few, returns pointer to the very first. Else, return NULL.
*/

char		*ft_strchrs(const char *s, const char *chrs)
{
	char	*ret;
	char	*res;

	res = NULL;
	while (*chrs)
	{
		if ((ret = ft_strchr(s, *chrs)))
		{
			if (!res)
				res = ret;
			else if (res > ret)
				res = ret;
		}
		chrs++;
	}
	return (res);
}
