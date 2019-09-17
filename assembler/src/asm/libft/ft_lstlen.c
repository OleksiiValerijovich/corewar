/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:47:52 by ishyian           #+#    #+#             */
/*   Updated: 2018/12/03 16:04:19 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_lstlen(t_list const *list)
{
	size_t	len;

	len = 0;
	while (list != NULL)
	{
		list = list->next;
		len++;
	}
	return (len);
}
