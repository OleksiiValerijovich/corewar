/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:12:53 by ishyian           #+#    #+#             */
/*   Updated: 2019/05/27 11:52:35 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

t_dllist	*ft_dllstnew(void const *content, size_t content_size)
{
	t_dllist	*list;

	list = ft_smalloc(sizeof(t_dllist));
	ft_bzero(list, sizeof(t_dllist));
	if (content != NULL)
	{
		list->content = ft_memdup(content, content_size);
		if (list->content == NULL)
		{
			free(list);
			return (NULL);
		}
		list->content_size = content_size;
	}
	return (list);
}
