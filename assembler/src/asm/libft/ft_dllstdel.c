/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:54:41 by ishyian           #+#    #+#             */
/*   Updated: 2019/05/28 17:11:05 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft.h"

void		ft_dllstdel(t_dllist **alst, void (*del)(void *, size_t))
{
	t_dllist		*tmp;
	t_dllist		*first;

	first = *alst;
	if (alst != NULL && *alst != NULL && del != NULL)
	{
		if ((*alst)->prev)
			if ((*alst)->prev->next == *alst)
				(*alst)->prev->next = NULL;
		while ((*alst)->next != NULL)
		{
			tmp = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = tmp;
		}
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
