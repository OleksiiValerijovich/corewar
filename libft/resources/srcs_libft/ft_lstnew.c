/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:42:36 by aturuk            #+#    #+#             */
/*   Updated: 2018/11/10 14:30:27 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_list;

	if ((new_list = (t_list *)malloc(sizeof(*new_list))) == 0)
		return (NULL);
	if (content == 0)
	{
		new_list->content = NULL;
		new_list->content_size = 0;
	}
	else
	{
		new_list->content = malloc(sizeof(*(new_list->content)) * content_size);
		if (new_list->content == 0)
			return (NULL);
		ft_memcpy(new_list->content, content, content_size);
		new_list->content_size = content_size;
	}
	new_list->next = NULL;
	return (new_list);
}
