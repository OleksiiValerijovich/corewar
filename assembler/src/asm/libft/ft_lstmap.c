/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:24:28 by ishyian           #+#    #+#             */
/*   Updated: 2018/12/02 22:30:44 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*tmp[3];

	tmp[2] = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst != NULL)
	{
		tmp[0] = f(lst);
		tmp[1] = ft_lstnew(tmp[0]->content, tmp[0]->content_size);
		if (tmp[1] == NULL)
		{
			ft_lstdel(&tmp[2], ft_memsdel);
			return (NULL);
		}
		else
		{
			if (tmp[2] == NULL)
				tmp[2] = tmp[1];
			else
				ft_lstaddend(&tmp[2], tmp[1]);
		}
		lst = lst->next;
	}
	return (tmp[2]);
}
