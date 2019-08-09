/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:01:50 by aturuk            #+#    #+#             */
/*   Updated: 2018/11/05 14:57:13 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *app, size_t n)
{
	size_t i;
	size_t k;

	i = ft_strlen(dest);
	k = 0;
	while (k < n && app[k] != '\0')
	{
		dest[i] = app[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}
