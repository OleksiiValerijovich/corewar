/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:01:56 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/08 21:42:45 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./ft_longexpr.h"

static void		add_point(size_t len_aft, char *res_end)
{
	ft_memmove(res_end - len_aft + 1, res_end - len_aft, len_aft + 1);
	*(res_end - len_aft + 1) = '.';
}

static int		skip(t_longexpr *x)
{
	if (x->len_aft && (x->start + x->len - 1 <= x->point))
		return (1);
	return (0);
}

static int		get_value(t_longexpr *x)
{
	if (x->len - skip(x))
		return (*(x->start + x->len - (1 + skip(x))) - '0');
	return (0);
}

static void		get_solution(t_longexpr *a, t_longexpr *b, char *res)
{
	int			tmp_a;
	int			tmp_b;
	int			sum;

	sum = 0;
	while (a->start + a->len > a->start + skip(a))
	{
		tmp_a = get_value(a);
		while ((b->start + b->len > b->start + skip(b)) || sum)
		{
			tmp_b = get_value(b);
			sum = tmp_a * tmp_b + (res[a->len + b->len + 1] - '0') + sum;
			res[a->len + b->len + 1] = sum % 10 + '0';
			sum = sum / 10;
			ft_decrement(&b->len, 1);
		}
		b->len = b->end + 1 - b->start;
		ft_decrement(&a->len, 1);
	}
}

void			mult(t_longexpr *a, t_longexpr *b, char *res)
{
	size_t		res_end;

	res_end = a->len + b->len + 1;
	get_solution(a, b, res);
	if (a->len_aft || b->len_aft)
	{
		add_point(a->len_aft + b->len_aft, res + res_end);
		res_end++;
	}
	*(res + res_end + 1) = '\0';
}
