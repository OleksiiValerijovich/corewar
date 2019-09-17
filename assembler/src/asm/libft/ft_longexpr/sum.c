/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:04:43 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/05 15:41:43 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./ft_longexpr.h"

static void		update_data(t_longexpr *a, t_longexpr *b)
{
	if (a->len_aft || b->len_aft)
	{
		if (a->len_aft == b->len_aft)
		{
			ft_decrement(&a->len_aft, 1);
			ft_decrement(&b->len_aft, 1);
		}
		if (a->len_aft > b->len_aft)
			ft_decrement(&a->len_aft, 1);
		if (b->len_aft > a->len_aft)
			ft_decrement(&b->len_aft, 1);
	}
	else
	{
		if (a->len_bef)
			ft_decrement(&a->len_bef, 1);
		if (b->len_bef)
			ft_decrement(&b->len_bef, 1);
	}
}

static int		get_value(t_longexpr *check, t_longexpr *cmp)
{
	if (check->len_aft || cmp->len_aft)
	{
		if (check->len_aft < cmp->len_aft || check->len_aft == 0)
			return (0);
		return (*check->end-- - '0');
	}
	else
	{
		if (check->len_bef == 0)
			return (0);
		return (*check->end-- - '0');
	}
}

static int		get_tmp(t_longexpr *a, t_longexpr *b)
{
	int			a_int;
	int			b_int;

	a_int = get_value(a, b);
	b_int = get_value(b, a);
	update_data(a, b);
	return (a_int + b_int);
}

static void		get_solution(t_longexpr *a, t_longexpr *b, char *res)
{
	int			tmp;

	tmp = 0;
	while (a->len_bef || b->len_bef || tmp)
	{
		if ((a->len_bef && *a->end == '.') || (b->len_bef && *b->end == '.'))
		{
			*res = '.';
			if (*a->end == '.')
				a->end--;
			if (*b->end == '.')
				b->end--;
		}
		else
		{
			tmp = tmp + get_tmp(a, b);
			*res = (tmp % 10) + '0';
			tmp = tmp / 10;
		}
		res--;
	}
}

void			sum(t_longexpr *a, t_longexpr *b, char *res)
{
	get_solution(a, b, ft_strchr(res, '\0') - 1);
}
