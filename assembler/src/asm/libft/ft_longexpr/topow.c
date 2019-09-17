/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 22:43:43 by ishyian           #+#    #+#             */
/*   Updated: 2019/08/09 19:41:45 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./ft_longexpr.h"

static char		*get_interim_result(char *curr, char *a_arg, short is_mod)
{
	char		*result;
	char		*tofree;

	result = ft_longexpr(curr, '*', curr);
	if (is_mod)
	{
		tofree = result;
		result = ft_longexpr(result, '*', a_arg);
		free(tofree);
	}
	free(curr);
	return (result);
}

static char		*get_solution(char *a_arg, long long pow)
{
	char		*result;
	char		*curr;
	short		pow_mod;

	if (pow == 1)
		return (ft_strdup(a_arg));
	pow_mod = pow % 2;
	pow_mod ? (pow = pow - 1) : 0;
	pow = pow / 2;
	curr = get_solution(a_arg, pow);
	result = get_interim_result(curr, a_arg, (pow_mod ? 1 : 0));
	return (result);
}

static int		exceptions(t_longexpr *a, t_longexpr *b, char *res)
{
	if (compare_int(a->start, '=', "0"))
	{
		res[0] = '0';
		res[1] = '\0';
	}
	else if (compare_int(b->start, '=', "0"))
	{
		res[0] = '1';
		res[1] = '\0';
	}
	else
		return (0);
	return (1);
}

void			topow(t_longexpr *a, t_longexpr *b, char *res)
{
	char		*result;
	char		*a_arg;

	if (exceptions(a, b, res))
		return ;
	if (!b->neg)
		a_arg = ft_strdup(a->start);
	else
		a_arg = ft_longexpr("1", '/', a->start);
	result = get_solution(a_arg, ft_atoll(b->start));
	ft_strcpy(res, result);
	free(result);
	free(a_arg);
}
