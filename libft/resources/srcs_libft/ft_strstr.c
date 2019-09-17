/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 12:48:30 by aturuk            #+#    #+#             */
/*   Updated: 2018/10/30 14:17:57 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int i;
	int n;

	i = 0;
	if (str2[0] == '\0')
		return ((char *)str1);
	else if (str2 != 0)
	{
		while (str1[i] != '\0')
		{
			n = 0;
			while (str2[n] == str1[n + i])
			{
				if (str2[n + 1] == '\0')
					return ((char *)str1 + i);
				n++;
			}
			i++;
		}
	}
	return (NULL);
}
