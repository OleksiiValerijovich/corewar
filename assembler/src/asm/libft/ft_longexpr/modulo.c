/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:06:48 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/14 22:06:49 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./ft_longexpr.h"

static char		*return_point(char *a, char *multiplier)
{
	char		*tofree;

	tofree = a;
	a = ft_longexpr(a, '/', multiplier);
	free(tofree);
	free(multiplier);
	return (a);
}

static void		get_modulo(char *a, char *b)
{
	char		*res_integer;
	char		*part;
	size_t		part_len;

	part_len = ft_strlen(a);
	part = ft_smalloc(part_len + 1);
	part[part_len] = '\0';
	res_integer = ft_itoa(0);
	dodiv_rec_divider(a, b, &res_integer, part);
	free(res_integer);
	free(part);
}

static char		*get_solution(char *a, char *b, char *multiplier)
{
	get_modulo(a, b);
	if (multiplier)
		a = return_point(a, multiplier);
	free(b);
	return (a);
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

char			*modulo(t_longexpr *a, t_longexpr *b)
{
	char		*multiplier;
	char		*int_a;
	char		*int_b;

	if (compare_int(a->start, '=', "0"))
		return (ft_itoa(0));
	else if (compare_int(a->start, '=', b->start))
		return (ft_itoa(0));
	else if (compare_int(a->start, '<', b->start))
		return (ft_strdup(a->start));
	else if (a->point || b->point)
	{
		multiplier = get_multiplier(a, b);
		int_a = ft_longexpr(a->start, '*', multiplier);
		int_b = ft_longexpr(b->start, '*', multiplier);
		return (get_solution(int_a, int_b, multiplier));
	}
	return (get_solution(ft_strdup(a->start), ft_strdup(b->start), NULL));
}
