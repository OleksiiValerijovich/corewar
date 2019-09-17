/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:53:45 by aturuk            #+#    #+#             */
/*   Updated: 2018/11/10 14:20:57 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_chr(const char *str, int ch)
{
	size_t len;

	len = 0;
	while (str[len] != ch)
	{
		if (str[len] == '\0')
			return (0);
		len++;
	}
	return (len);
}
