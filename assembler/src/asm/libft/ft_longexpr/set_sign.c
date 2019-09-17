/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:30:45 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/14 19:30:46 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./ft_longexpr.h"

static void		add_neg_sign(char **res)
{
	char		*tofree;

	tofree = *res;
	*res = ft_strjoin("-", *res);
	free(tofree);
}

static void		if_sum(t_longexpr *a, t_longexpr *b, char **res)
{
	if (a->neg && b->neg)
		add_neg_sign(res);
	else if (a->neg && !b->neg && compare_int(a->start, '>', b->start))
		add_neg_sign(res);
	else if (!a->neg && b->neg && compare_int(a->start, '<', b->start))
		add_neg_sign(res);
}

static void		if_sub(t_longexpr *a, t_longexpr *b, char **res)
{
	if (a->neg && b->neg && compare_int(a->start, '>', b->start))
		add_neg_sign(res);
	else if (a->neg && !b->neg)
		add_neg_sign(res);
	else if (!a->neg && !b->neg && compare_int(a->start, '<', b->start))
		add_neg_sign(res);
}

void			set_sign(t_longexpr *a, t_longexpr *b, char op, char **res)
{
	if (ft_strchr("*/", op))
	{
		if ((a->neg && !b->neg) || (!a->neg && b->neg))
			add_neg_sign(res);
	}
	else if (op == '^' && a->neg)
		add_neg_sign(res);
	else if (op == '+')
		if_sum(a, b, res);
	else if (op == '-')
		if_sub(a, b, res);
	else if (op == '%')
		if (compare_int(a->start, '<', "0"))
			add_neg_sign(res);
}
