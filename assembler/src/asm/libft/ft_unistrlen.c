/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unistrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:23:51 by ishyian           #+#    #+#             */
/*   Updated: 2019/03/14 17:35:08 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_unistrlen(const unsigned char *s)
{
	size_t	len;
	short	i;

	len = 0;
	while (s && *s)
	{
		if (*s >> 7 == 0)
			i = 1;
		else if (*s >> 5 == 6)
			i = 2;
		else if (*s >> 4 == 14)
			i = 3;
		else
			i = 4;
		len++;
		s = s + i;
	}
	return (len);
}
