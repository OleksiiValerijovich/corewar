/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort_swap_items.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:03:47 by ishyian           #+#    #+#             */
/*   Updated: 2019/06/17 12:53:57 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static void	ft_qs_swap_items_a(t_quicksort *t_sort, t_quicksort_f_l *t_f_l)
{
	ft_dllstswap(&t_sort->to_swap_low, &t_sort->to_swap_high);
	if (*t_f_l->first == t_sort->to_swap_high)
		*t_f_l->first = t_sort->to_swap_low;
	if (*t_f_l->last == t_sort->to_swap_low)
		*t_f_l->last = t_sort->to_swap_high;
	if (t_sort->low == t_sort->to_swap_high)
		t_sort->low = t_sort->to_swap_low;
	if (t_sort->high == t_sort->to_swap_low)
		t_sort->high = t_sort->to_swap_high;
}

static void	ft_qs_swap_items_b(t_quicksort *t_sort, t_quicksort_f_l *t_f_l)
{
	ft_dllstswap(&t_sort->to_swap_high, &t_sort->pivot);
	if (*t_f_l->first == t_sort->pivot)
		*t_f_l->first = t_sort->to_swap_high;
	if (*t_f_l->last == t_sort->to_swap_high)
		*t_f_l->last = t_sort->pivot;
	if (t_sort->low == t_sort->pivot)
		t_sort->low = t_sort->to_swap_high;
	t_sort->high = t_sort->pivot;
	t_sort->pivot = t_sort->to_swap_high;
}

int			ft_quicksort_swap_items(t_quicksort *t_sort, t_quicksort_f_l *t_f_l)
{
	if (t_sort->to_swap_low != t_sort->to_swap_high)
	{
		ft_qs_swap_items_a(t_sort, t_f_l);
		return (0);
	}
	else
	{
		if (!t_sort->f(t_sort->to_swap_high, t_sort->pivot) &&
			t_sort->to_swap_high != t_sort->pivot)
			ft_qs_swap_items_b(t_sort, t_f_l);
		return (1);
	}
}
