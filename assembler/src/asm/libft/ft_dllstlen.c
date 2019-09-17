/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:09:52 by ishyian           #+#    #+#             */
/*   Updated: 2019/06/21 12:31:08 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t		ft_dllstlen(t_dllist *list, t_dllist *last)
{
	t_dllist	*first;
	size_t		len;

	len = 0;
	first = list;
	while (list)
	{
		len++;
		if (list == last)
			break ;
		list = list->next;
		if (list == first)
			break ;
	}
	return (len);
}
