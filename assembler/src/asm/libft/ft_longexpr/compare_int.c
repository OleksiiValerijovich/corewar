/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:44:03 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/11 16:55:26 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./ft_longexpr.h"

int		compare_int(const char *a, char op, const char *b)
{
	char		*res_str;
	int			res_int;

	res_str = ft_longexpr(a, op, b);
	res_int = ft_atoi(res_str);
	free(res_str);
	return (res_int);
}
