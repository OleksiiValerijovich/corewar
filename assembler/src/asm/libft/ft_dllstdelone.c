/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 19:21:19 by ishyian           #+#    #+#             */
/*   Updated: 2019/05/07 19:21:20 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_dllstdelone(t_dllist **alst, void (*del)(void *, size_t))
{
	if (alst != NULL && *alst != NULL)
	{
		if ((*alst)->prev)
			(*alst)->prev->next = (*alst)->next;
		if ((*alst)->next)
			(*alst)->next->prev = (*alst)->prev;
		if ((*alst)->content != NULL)
			del((*alst)->content, (*alst)->content_size);
		free(*alst);
		(*alst) = NULL;
	}
}
