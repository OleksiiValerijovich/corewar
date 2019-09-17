/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:42:15 by ishyian           #+#    #+#             */
/*   Updated: 2019/02/22 04:24:42 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static short	check(const void *haystack, size_t size,
					size_t i, const char *needle)
{
	while (i < size)
	{
		if (*needle == '\0')
			return (1);
		if (((unsigned char*)haystack)[i] != (unsigned char)*needle)
			break ;
		i++;
		needle++;
	}
	return (0);
}

void			*ft_memstr(const void *haystack, const char *needle,
						size_t size)
{
	size_t		i;

	if (*needle == '\0')
		return ((void*)haystack);
	i = 0;
	while (i < size)
	{
		if (((unsigned char*)haystack)[i] == (unsigned char)*needle)
			if (check(haystack, size, i, needle))
				return ((void*)(haystack + i));
		i++;
	}
	return (NULL);
}
