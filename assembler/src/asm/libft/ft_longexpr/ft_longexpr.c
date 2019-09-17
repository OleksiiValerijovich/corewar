/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longexpr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 16:52:59 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/11 21:53:35 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./ft_longexpr.h"

static char		*get_res(t_longexpr *a, t_longexpr *b, char op)
{
	char		*res;
	size_t		max_bef;
	size_t		max_aft;
	size_t		max_res_len;

	max_res_len = 0;
	max_bef = GREATEST(a->len_bef, b->len_bef);
	max_aft = GREATEST(a->len_aft, b->len_aft);
	if (ft_strchr("+-", op))
		max_res_len = max_bef + max_aft + 4;
	if (op == '*')
		max_res_len = a->len + b->len + 5;
	if (op == '^')
		max_res_len = (a->len) * ft_atoi(b->start) + 4;
	res = ft_smalloc(max_res_len);
	ft_memset(res, '0', max_res_len - 1);
	res[max_res_len - 1] = '\0';
	return (res);
}

static void		arg_processing(const char *arg, t_longexpr *x)
{
	x->neg = 0;
	if (ft_issign(*arg))
		if (*(arg++) == '-' && !compare_int(arg, '=', "0"))
			x->neg = 1;
	while (arg[0] == '0' && arg[1] != '\0' && arg[1] != '.')
		arg++;
	x->start = arg;
	x->point = ft_strchr(arg, '.');
	x->end = ft_strchr(arg, '\0');
	if (!x->point)
	{
		x->len_bef = x->end - x->start;
		x->len_aft = 0;
	}
	else
	{
		x->len_bef = x->point - x->start;
		x->len_aft = x->end - x->point - 1;
	}
	x->len = x->end - x->start;
	x->end--;
}

static void		sum_sub_mod(t_longexpr *a, t_longexpr *b, char op, char **res)
{
	char			*tofree;

	if (op == '+')
	{
		if ((a->neg && b->neg) || (!a->neg && !b->neg))
			sum(a, b, *res);
		else if ((a->neg && !b->neg) || (!a->neg && b->neg))
			subtraction(a, b, *res);
	}
	else if (op == '-')
	{
		if ((a->neg && b->neg) || (!a->neg && !b->neg))
			subtraction(a, b, *res);
		else if ((a->neg && !b->neg) || (!a->neg && b->neg))
			sum(a, b, *res);
	}
	else if (op == '%' && !a->neg)
		*res = modulo(a, b);
	else if (op == '%' && a->neg)
	{
		tofree = modulo(a, b);
		*res = ft_longexpr(b->start, '-', tofree);
		free(tofree);
	}
}

static char		*processing(const char *a_arg, char op, const char *b_arg)
{
	t_longexpr		a;
	t_longexpr		b;
	char			*res;

	arg_processing(a_arg, &a);
	arg_processing(b_arg, &b);
	if (!ft_strchr(">=</%", op))
		res = get_res(&a, &b, op);
	if (ft_strchr("+-%", op))
		sum_sub_mod(&a, &b, op, &res);
	if (op == '*')
		mult(&a, &b, res);
	if (op == '^')
		topow(&a, &b, res);
	if (op == '/')
		res = dodiv(&a, &b);
	if (ft_strchr(">=<", op))
		return (ft_itoa(compare(&a, op, &b)));
	res_postprocessor(&res);
	set_sign(&a, &b, op, &res);
	return (res);
}

char			*ft_longexpr(const char *a_arg, char op, const char *b_arg)
{
	if (is_valid(a_arg, op, b_arg))
		return (processing(a_arg, op, b_arg));
	else
		return (NULL);
}
