/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:33:55 by ishyian           #+#    #+#             */
/*   Updated: 2018/12/02 22:06:13 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i[3];

	i[0] = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i[0]] != '\0')
	{
		i[1] = 0;
		if (haystack[i[0]] == needle[i[1]])
		{
			i[2] = i[0];
			while (haystack[0] != '\0' && haystack[i[0]] == needle[i[1]])
			{
				i[0]++;
				i[1]++;
				if (needle[i[1]] == '\0')
					return ((char*)haystack + (i[0] - i[1]));
			}
			i[0] = i[2] + 1;
		}
		else
			i[0]++;
	}
	return (NULL);
}
