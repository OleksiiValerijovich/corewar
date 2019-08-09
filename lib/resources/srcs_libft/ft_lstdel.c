/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:43:31 by aturuk            #+#    #+#             */
/*   Updated: 2018/11/13 10:31:00 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *l_del;

	if (alst && del)
	{
		if (*alst)
		{
			while (*alst)
			{
				l_del = (*alst)->next;
				del((*alst)->content, (*alst)->content_size);
				free(*alst);
				(*alst) = l_del;
			}
			*alst = NULL;
		}
	}
}
