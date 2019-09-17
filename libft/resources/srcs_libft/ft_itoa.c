/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 12:59:22 by aturuk            #+#    #+#             */
/*   Updated: 2018/11/08 11:40:50 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len = 1;
	}
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*intmin(void)
{
	char *s;

	s = ft_strnew(11);
	ft_strcpy(s, "-2147483648");
	return (s);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		str = intmin();
	else
	{
		len = numlen(n);
		if ((str = (char *)malloc(sizeof(*str) * (len + 1))) == 0)
			return (NULL);
		str[len] = '\0';
		len = len - 1;
		if (n < 0)
		{
			str[0] = '-';
			n = n * -1;
		}
		while (n > 0 || (len > -1 && str[len] != '-'))
		{
			str[len] = (n % 10) + '0';
			n = n / 10;
			len--;
		}
	}
	return (str);
}
