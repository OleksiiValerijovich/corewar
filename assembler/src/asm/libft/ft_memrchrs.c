/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:37:25 by ishyian           #+#    #+#             */
/*   Updated: 2019/02/22 04:24:25 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

/*
** Function searching chars in *mem from *chrs. If found anyone, returns pointer
** to it. Else, return NULL. r = reverse
*/

void		*ft_memrchrs(const void *mem, size_t size_mem,
						const char *chrs, size_t size_chrs)
{
	char	curr;
	void	*res;
	size_t	i;

	i = 0;
	while (i < size_chrs)
	{
		curr = *(chrs + i);
		if ((res = ft_memrchr(mem, curr, size_mem)))
			return (res);
		i++;
	}
	return (NULL);
}
