/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 21:38:25 by ishyian           #+#    #+#             */
/*   Updated: 2019/06/24 12:06:37 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int			ft_getint(char *str)
{
	int		integer;

	if (str[0] && str[0] == '0' && str[1] && str[1] == 'b')
		integer = ft_atoi_base(str + 2, 2);
	else if (str[0] && str[0] == '0' && str[1] && str[1] == 'x')
		integer = ft_atoi_base(str + 2, 16);
	else if (str[0] && str[0] == '0')
		integer = ft_atoi_base(str + 1, 8);
	else
		integer = ft_atoi(str);
	return (integer);
}
