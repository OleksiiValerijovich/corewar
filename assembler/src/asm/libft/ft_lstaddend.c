/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:06:45 by ishyian           #+#    #+#             */
/*   Updated: 2019/06/17 13:00:51 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	if (alst != NULL && new != NULL)
	{
		if (*alst != NULL)
		{
			while ((*alst)->next != NULL)
				alst = &(*alst)->next;
			(*alst)->next = new;
		}
		else
			*alst = new;
	}
}
