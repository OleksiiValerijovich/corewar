/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:36:48 by aturuk            #+#    #+#             */
/*   Updated: 2018/11/13 10:26:34 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **alst, t_list *newend)
{
	t_list *list;

	if (alst && newend)
	{
		if (*alst)
		{
			list = *alst;
			while (list->next != NULL)
				list = list->next;
			list->next = newend;
		}
	}
}
