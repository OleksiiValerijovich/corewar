/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:34:06 by aturuk            #+#    #+#             */
/*   Updated: 2018/11/05 15:35:08 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t i;
	size_t n;

	i = 0;
	n = 0;
	if (*str2 == '\0')
		return ((char *)str1);
	while (i < len && str1[i] != '\0')
	{
		n = 0;
		while (str2[n] == str1[n + i] && (n + i) < len)
		{
			if (str2[n + 1] == '\0')
				return ((char *)str1 + i);
			n++;
		}
		i++;
	}
	return (NULL);
}
