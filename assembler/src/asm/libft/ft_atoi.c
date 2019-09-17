/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:07:46 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/04 17:31:49 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int			nbr;
	int			sign;
	size_t		i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]))
		if (str[i++] == '-')
			sign = -1;
	while (ft_isdigit(str[i]))
		nbr = (str[i++] - '0') * sign + nbr * 10;
	return (nbr);
}
