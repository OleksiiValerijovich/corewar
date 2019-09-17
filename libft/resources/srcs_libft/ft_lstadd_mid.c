/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_mid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:11:44 by aturuk            #+#    #+#             */
/*   Updated: 2018/11/13 10:27:08 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_mid(t_list **alst, t_list *mid_list)
{
	t_list *list;
	t_list *next;

	if (alst && mid_list)
	{
		if (*alst)
		{
			list = *alst;
			next = list->next;
			list->next = mid_list;
			while (mid_list->next != NULL)
				mid_list = mid_list->next;
			mid_list->next = next;
		}
	}
}
