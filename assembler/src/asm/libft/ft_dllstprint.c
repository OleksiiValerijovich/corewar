/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:19:25 by ishyian           #+#    #+#             */
/*   Updated: 2019/06/21 12:31:28 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void		ft_dllstprint(t_dllist *list, t_dllist *last)
{
	t_dllist	*first;

	first = list;
	while (list != NULL)
	{
		ft_printf("content: %s\n", list->content);
		if (list == last)
			break ;
		list = list->next;
		if (list == first)
			break ;
	}
}
