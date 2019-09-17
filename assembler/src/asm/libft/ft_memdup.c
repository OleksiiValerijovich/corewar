/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:09:39 by ishyian           #+#    #+#             */
/*   Updated: 2018/12/03 16:43:31 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memdup(const void *src, size_t size)
{
	size_t			i;
	void			*dup;

	if (src == NULL)
		return (NULL);
	i = -1;
	dup = (void*)malloc(size);
	if (dup != NULL)
		while (++i < size)
			((unsigned char*)dup)[i] = ((unsigned char*)src)[i];
	return (dup);
}
