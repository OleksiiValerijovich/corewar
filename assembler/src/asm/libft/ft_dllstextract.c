/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstextract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:25:02 by ishyian           #+#    #+#             */
/*   Updated: 2019/08/01 13:30:41 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void		ft_dllstextract(t_dllist *item)
{
	if (item != NULL)
	{
		if (item->prev)
			item->prev->next = item->next;
		if (item->next)
			item->next->prev = item->prev;
	}
}
