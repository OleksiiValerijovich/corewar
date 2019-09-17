/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dodiv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:48:07 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/11 19:25:15 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./ft_longexpr.h"

static char		*get_res(char *integer, char *fraction)
{
	char		*res;
	char		*tofree;

	if (fraction)
	{
		tofree = fraction;
		fraction = ft_strjoin(".", fraction);
		free(tofree);
		res = ft_strjoin(integer, fraction);
		free(integer);
		free(fraction);
	}
	else
		res = integer;
	return (res);
}

static char		*get_integer(char *a, char *b)
{
	char		*res_integer;
	char		*part;
	size_t		part_len;

	part_len = ft_strlen(a);
	part = ft_smalloc(part_len + 1);
	part[part_len] = '\0';
	res_integer = ft_itoa(0);
	dodiv_rec_divider(a, b, &res_integer, part);
	free(part);
	return (res_integer);
}

static char		*get_solution(char *a, char *b)
{
	char		*res_integer;
	char		*res_fraction;
	char		*res;

	if (!compare_int(a, '<', b))
		res_integer = get_integer(a, b);
	else
		res_integer = ft_itoa(0);
	if (ft_strlen(a) && compare_int(a, '>', "0"))
		res_fraction = dodiv_get_fraction(ft_strdup(a), b);
	else
		res_fraction = NULL;
	free(a);
	free(b);
	res = get_res(res_integer, res_fraction);
	return (res);
}

static char		*get_multiplier(t_longexpr *a, t_longexpr *b)
{
	char		*multiplier;
	size_t		zeroes_count;

	zeroes_count = GREATEST(a->len_aft, b->len_aft);
	multiplier = ft_smalloc(zeroes_count + 2);
	multiplier[0] = '1';
	ft_memset((multiplier + 1), '0', zeroes_count);
	multiplier[zeroes_count + 1] = '\0';
	return (multiplier);
}

char			*dodiv(t_longexpr *a, t_longexpr *b)
{
	char		*multiplier;
	char		*int_a;
	char		*int_b;

	if (compare_int(a->start, '=', "0") || compare_int(b->start, '=', "0"))
		return (ft_itoa(0));
	else if (compare_int(a->start, '=', b->start))
		return (ft_itoa(1));
	else if (a->point || b->point)
	{
		multiplier = get_multiplier(a, b);
		int_a = ft_longexpr(a->start, '*', multiplier);
		int_b = ft_longexpr(b->start, '*', multiplier);
		free(multiplier);
		return (get_solution(int_a, int_b));
	}
	return (get_solution(ft_strdup(a->start), ft_strdup(b->start)));
}
