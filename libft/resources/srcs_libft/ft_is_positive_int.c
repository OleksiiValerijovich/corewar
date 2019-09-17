/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_positive_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:10:28 by aturuk            #+#    #+#             */
/*   Updated: 2019/08/06 12:10:30 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_positive_int(char *line)
{
	int		len;

	len = 0;
	if (line[0] == '0' && line[1] != '\0')
		return (0);
	while (line[len] != '\0')
		if (!(ft_isdigit(line[len])) || ++len > 10)
			return (0);
	if (len == 10 && ft_strcmp(line, "2147483647") > 0)
		return (0);
	return (len);
}
