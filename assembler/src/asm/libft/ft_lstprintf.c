/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:51:37 by ishyian           #+#    #+#             */
/*   Updated: 2019/06/15 19:23:55 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstprintf(t_list const *lst, void *(f)())
{
	size_t	i;

	i = 1;
	while (lst)
	{
		ft_putnbr(i++);
		ft_putstr(" item: ");
		if (lst->content != NULL)
			f(lst);
		else
			ft_putstr("null");
		lst = lst->next;
		ft_putchar('\n');
	}
}
