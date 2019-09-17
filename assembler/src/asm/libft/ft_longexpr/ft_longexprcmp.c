/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longexprcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:49:30 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/25 14:49:32 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./ft_longexpr.h"

int			ft_longexprcmp(char *arg_a, char op, char *arg_b)
{
	char	*tofree;
	int		res;

	tofree = ft_longexpr(arg_a, op, arg_b);
	res = ft_atoi(tofree);
	free(tofree);
	return (res);
}
