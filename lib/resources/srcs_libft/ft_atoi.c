/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:12:32 by aturuk            #+#    #+#             */
/*   Updated: 2018/11/10 17:58:24 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	unsigned long long	result;
	int					negative;
	int					i;

	negative = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	if (result > 9223372036854775807)
	{
		if (negative == -1)
			return (0);
		return (-1);
	}
	return (negative * result);
}
