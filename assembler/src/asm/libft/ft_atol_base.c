/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:49:37 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/04 17:51:35 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_value(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	else
		return (10 + c - 'a');
}

static int	is_valid(char c, int base)
{
	if (ft_isdigit(c))
		return (1);
	if (ft_isupper(c))
		c = ft_tolower(c);
	else if (base > 10 && (c >= 'a' && c <= ('a' + base - 11)))
		return (1);
	return (0);
}

long		ft_atol_base(const char *str, int base)
{
	long		nbr;
	int			sign;
	size_t		i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]))
		if (str[i++] == '-' && base == 10)
			sign = -1;
	while (is_valid(str[i], base))
		nbr = get_value(str[i++]) * sign + nbr * base;
	return (nbr);
}
