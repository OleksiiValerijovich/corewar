/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 12:01:25 by aturuk            #+#    #+#             */
/*   Updated: 2018/11/12 14:29:07 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		len;

	len = (int)ft_strlen(str);
	if (ch < 0 || ch > 255)
		return (NULL);
	if (str != 0)
	{
		while (str[len] != ch && len != -1)
			len--;
		if (len == -1)
			return (NULL);
		return ((char *)(str + len));
	}
	return (NULL);
}
