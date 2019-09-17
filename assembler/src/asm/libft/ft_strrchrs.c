/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:25:57 by ishyian           #+#    #+#             */
/*   Updated: 2019/06/21 22:47:54 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/*
** Function searching chars in *s from *chrs. If found anyone, returns pointer
** to it. Else, return NULL. r = reverse.
*/

char		*ft_strrchrs(const char *s, const char *chrs)
{
	char	curr;
	char	*res;

	while (*chrs)
	{
		curr = *chrs;
		if ((res = ft_strrchr(s, curr)))
			return (res);
		chrs++;
	}
	return (NULL);
}
