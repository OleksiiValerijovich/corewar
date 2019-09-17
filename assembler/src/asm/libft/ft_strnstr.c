/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:27:33 by ishyian           #+#    #+#             */
/*   Updated: 2018/12/02 22:03:29 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i[3];

	i[0] = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (i[0] < len && haystack[i[0]] != '\0')
	{
		i[1] = 0;
		if (i[0] < len && haystack[i[0]] == needle[i[1]])
		{
			i[2] = i[0];
			while (haystack[i[0]] != '\0' && i[0] < len
				&& haystack[i[0]] == needle[i[1]] && ++i[0] && ++i[1])
				if (i[0] <= len && needle[i[1]] == '\0')
					return ((char*)haystack + (i[0] - i[1]));
			i[0] = i[2] + 1;
		}
		else
			i[0]++;
	}
	return (NULL);
}
