/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstswap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:37:42 by ishyian           #+#    #+#             */
/*   Updated: 2019/06/19 14:45:50 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static void		swap_only_two(t_dllist **a, t_dllist **b)
{
	if ((!(*a)->prev && !(*b)->next) || (!(*a)->next && !(*b)->prev))
	{
		ft_pswap((void**)&((*a)->next), (void**)&((*b)->next));
		ft_pswap((void**)&((*a)->prev), (void**)&((*b)->prev));
	}
	ft_pswap((void**)a, (void**)b);
}

static void		swap_separated(t_dllist **a, t_dllist **b)
{
	ft_pswap((void**)&((*a)->next), (void**)&((*b)->next));
	ft_pswap((void**)&((*a)->prev), (void**)&((*b)->prev));
	if ((*a)->prev)
		(*a)->prev->next = *a;
	if ((*a)->next)
		(*a)->next->prev = *a;
	if ((*b)->prev)
		(*b)->prev->next = *b;
	if ((*b)->next)
		(*b)->next->prev = *b;
	ft_pswap((void**)a, (void**)b);
}

static void		swap_neighbors(t_dllist **a, t_dllist **b)
{
	(*a)->next = (*b)->next;
	(*b)->next = *a;
	(*b)->prev = (*a)->prev;
	(*a)->prev = *b;
	if ((*a)->next)
		(*a)->next->prev = *a;
	if ((*b)->prev)
		(*b)->prev->next = *b;
	ft_pswap((void**)a, (void**)b);
}

void			ft_dllstswap(t_dllist **a, t_dllist **b)
{
	if ((*a)->next == *b && (*a)->prev != *b)
		swap_neighbors(a, b);
	else if ((*a)->next != *b && (*a)->prev == *b)
		swap_neighbors(b, a);
	else if ((*a)->next != *b && (*a)->prev != *b)
		swap_separated(a, b);
	else if ((*a)->next == *b && (*a)->prev == *b)
		swap_only_two(a, b);
}
