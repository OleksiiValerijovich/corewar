/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:01:15 by aturuk            #+#    #+#             */
/*   Updated: 2018/11/10 09:34:36 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh_list;
	t_list *new_list;
	t_list *next_list;

	if (lst == 0 || !(f))
		return (0);
	if ((fresh_list = (t_list *)malloc(sizeof(lst))) == 0)
		return (NULL);
	fresh_list = (f)(lst);
	new_list = fresh_list;
	lst = lst->next;
	while (lst)
	{
		if ((next_list = (t_list*)malloc(sizeof(lst))) == 0)
			return (NULL);
		next_list = f(lst);
		fresh_list->next = next_list;
		fresh_list = fresh_list->next;
		next_list = NULL;
		lst = lst->next;
	}
	return (new_list);
}
