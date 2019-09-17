/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:51:37 by ishyian           #+#    #+#             */
/*   Updated: 2019/06/15 19:23:59 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstprint(t_list const *lst)
{
	size_t	i;

	i = 1;
	while (lst)
	{
		ft_putnbr(i++);
		ft_putstr(" item: ");
		if (lst->content != NULL)
			ft_printmem(lst->content, lst->content_size);
		else
			ft_putstr("null");
		lst = lst->next;
		ft_putchar('\n');
	}
}
