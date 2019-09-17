/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstmiddle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:56:10 by ishyian           #+#    #+#             */
/*   Updated: 2019/06/19 20:22:09 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dllist		*ft_dllstmiddle(t_dllist *list, t_dllist *last)
{
	size_t		len;
	t_dllist	*first;

	len = ft_dllstlen(list, last);
	if (len == 1 || len == 2)
		return (list);
	first = list;
	len = len / 2 + len % 2 - 1;
	while (len)
	{
		list = list->next;
		len--;
	}
	return (list);
}
