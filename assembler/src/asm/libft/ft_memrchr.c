/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:37:25 by ishyian           #+#    #+#             */
/*   Updated: 2019/02/15 17:19:23 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memrchr(const void *s, int c, size_t n)
{
	while (n-- > 0)
		if (((unsigned char*)s)[n] == (unsigned char)c)
			return ((unsigned char*)s + n);
	return (NULL);
}
