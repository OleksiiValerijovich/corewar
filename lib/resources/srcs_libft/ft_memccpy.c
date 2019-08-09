/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 10:18:37 by aturuk            #+#    #+#             */
/*   Updated: 2018/11/10 10:48:44 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*s1;
	const char	*s2;
	size_t		i;

	if ((dest == 0 && src == 0) || n == 0)
		return (NULL);
	s1 = (char *)dest;
	s2 = (const char *)src;
	i = 0;
	while (i < n)
	{
		if (s2[i] == (char)c)
		{
			s1[i] = s2[i];
			return (s1 + i + 1);
		}
		s1[i] = s2[i];
		i++;
	}
	return (NULL);
}
