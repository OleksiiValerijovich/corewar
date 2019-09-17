/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:08:18 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/11 15:32:24 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_longexpr.h"

static void	skipper(const char **a, const char **b, size_t *len_a,
																size_t *len_b)
{
	while (*len_a && *len_b && **a == **b)
	{
		ft_decrement(len_a, 1);
		ft_decrement(len_b, 1);
		(*a)++;
		(*b)++;
	}
}

static int	cmp_aft(t_longexpr *a, char op, t_longexpr *b, short neg)
{
	if (op == '=' && A_A_EQUAL_B_A)
		return (1);
	if (A_A_LESS_B_A)
	{
		if (op == '<' && !neg)
			return (1);
		if (op == '>' && neg)
			return (1);
	}
	if (A_A_GREATER_B_A)
	{
		if (op == '>' && !neg)
			return (1);
		if (op == '<' && neg)
			return (1);
	}
	return (0);
}

static int	cmp_bef(t_longexpr *a, char op, t_longexpr *b, short neg)
{
	if (!a->len_bef && !b->len_bef)
		return (2);
	if ((*a->start < *b->start && a->len_bef <= b->len_bef) ||
		(a->len_bef < b->len_bef))
	{
		if (op == '<' && !neg)
			return (1);
		if (op == '>' && neg)
			return (1);
	}
	if ((*a->start > *b->start && a->len_bef >= b->len_bef) ||
		(a->len_bef > b->len_bef))
	{
		if (op == '>' && !neg)
			return (1);
		if (op == '<' && neg)
			return (1);
	}
	return (0);
}

static int	goer(t_longexpr *a, char op, t_longexpr *b)
{
	int		ret;
	short	neg;

	neg = a->neg && b->neg ? 1 : 0;
	skipper(&a->start, &b->start, &a->len_bef, &b->len_bef);
	ret = cmp_bef(a, op, b, neg);
	if (ret == 1)
		return (1);
	else if (ret == 2)
	{
		if (a->point)
			a->point++;
		if (b->point)
			b->point++;
		skipper(&a->point, &b->point, &a->len_aft, &b->len_aft);
		if (cmp_aft(a, op, b, neg))
			return (1);
	}
	return (0);
}

int			compare(t_longexpr *a, char op, t_longexpr *b)
{
	if (op == '=')
		if ((a->neg && b->neg) || (!a->neg && !b->neg))
			return (goer(a, op, b));
	if (op == '<')
	{
		if ((a->neg && b->neg) || (!a->neg && !b->neg))
			return (goer(a, op, b));
		if (a->neg && !b->neg)
			return (1);
	}
	if (op == '>')
	{
		if ((a->neg && b->neg) || (!a->neg && !b->neg))
			return (goer(a, op, b));
		if (!a->neg && b->neg)
			return (1);
	}
	return (0);
}
