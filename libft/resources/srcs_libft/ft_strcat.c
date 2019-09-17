/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:37:53 by aturuk            #+#    #+#             */
/*   Updated: 2018/11/02 12:02:14 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *app)
{
	int i;
	int n;

	i = ft_strlen(dest);
	n = 0;
	while (app[n] != '\0')
	{
		dest[i + n] = app[n];
		n++;
	}
	dest[i + n] = '\0';
	return (dest);
}
