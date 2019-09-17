/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchrcount.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:04:27 by ishyian           #+#    #+#             */
/*   Updated: 2019/06/20 20:55:00 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Function returns a count of appearence int c in memory.
*/

size_t		ft_memchrcount(const void *s, int c, size_t n)
{
	size_t	i;
	size_t	count;

	i = -1;
	count = 0;
	while (++i < n)
		if (((unsigned char*)s)[i] == (unsigned char)c)
			count++;
	return (count);
}
