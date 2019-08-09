/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 10:48:56 by aturuk            #+#    #+#             */
/*   Updated: 2018/11/12 14:29:32 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t n;
	size_t k;

	i = 0;
	n = 0;
	k = 0;
	if (ft_strlen(dest) >= size)
		return (ft_strlen(src) + size);
	while (dest[i] != '\0')
		i++;
	while (src[n] != '\0' && (i + n) < (size - 1))
	{
		dest[i + n] = src[n];
		n++;
	}
	dest[i + n] = '\0';
	while (src[k] != '\0')
		k++;
	return (i + k);
}
