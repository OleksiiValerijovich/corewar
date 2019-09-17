/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:50:23 by ishyian           #+#    #+#             */
/*   Updated: 2019/06/17 14:18:28 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_dllist		*ft_dllstdup(t_dllist *list, t_dllist *last)
{
	t_dllist	*new;
	t_dllist	*first;

	new = NULL;
	first = list;
	while (list)
	{
		ft_dllstaddend(&new, ft_dllstnew(list->content, list->content_size));
		if (list == last)
			break ;
		list = list->next;
		if (list == first)
			break ;
	}
	return (new);
}
