/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:01:13 by ishyian           #+#    #+#             */
/*   Updated: 2019/06/21 11:48:20 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft.h"

static void	find_low(t_quicksort *t_sort)
{
	while (t_sort->to_swap_low != t_sort->to_swap_high)
	{
		if (!t_sort->f(t_sort->to_swap_low, t_sort->pivot))
			break ;
		else
			t_sort->to_swap_low = t_sort->to_swap_low->next;
	}
}

static void	find_high(t_quicksort *t_sort)
{
	while (t_sort->to_swap_low != t_sort->to_swap_high)
	{
		if (t_sort->f(t_sort->to_swap_high, t_sort->pivot))
			break ;
		else
			t_sort->to_swap_high = t_sort->to_swap_high->prev;
	}
}

static void	quicksort(t_quicksort t_sort, t_quicksort_f_l *t_f_l,
						t_dllist *newlow, t_dllist *newhigh)
{
	t_sort.low = newlow;
	t_sort.to_swap_low = t_sort.low;
	t_sort.pivot = newhigh;
	t_sort.high = newhigh;
	t_sort.to_swap_high = t_sort.high->prev;
	while (1)
	{
		find_low(&t_sort);
		find_high(&t_sort);
		if (ft_quicksort_swap_items(&t_sort, t_f_l))
			break ;
		if (t_sort.pivot == t_sort.low)
			break ;
	}
	if (t_sort.low != t_sort.pivot && t_sort.low != t_sort.pivot->prev)
		quicksort(t_sort, t_f_l, t_sort.low, t_sort.pivot->prev);
	if (t_sort.high != t_sort.pivot && t_sort.high != t_sort.pivot->next)
		quicksort(t_sort, t_f_l, t_sort.pivot->next, t_sort.high);
}

/*
** For ascending sorting function int (*f)() should return 1 if the first
** argument is less, then the second argument. Else, returns 0.
** For descending sorting function int (*f)() should return 0 if the first
** argument is less, then the second argument. Else, returns 1.
*/

void		ft_quicksort(t_dllist **list, t_dllist **last, int (*f)())
{
	t_quicksort			t_sort;
	t_quicksort_f_l		t_f_l;

	if (!*list || !(*list)->next)
		return ;
	t_f_l.first = list;
	t_f_l.last = last;
	t_sort.f = f;
	t_sort.low = *list;
	if (last)
	{
		t_sort.high = *last;
		t_f_l.last = last;
	}
	else if ((*list)->prev != NULL)
		t_sort.high = (*list)->prev;
	else if ((*list)->prev == NULL)
	{
		t_sort.high = *list;
		while (t_sort.high->next != NULL)
			t_sort.high = t_sort.high->next;
	}
	t_f_l.last = &t_sort.high;
	quicksort(t_sort, &t_f_l, t_sort.low, t_sort.high);
}
