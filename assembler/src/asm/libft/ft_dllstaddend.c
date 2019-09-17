/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstaddend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:19:51 by ishyian           #+#    #+#             */
/*   Updated: 2019/05/27 11:55:13 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_dllstaddend(t_dllist **alst, t_dllist *new)
{
	if (alst != NULL && new != NULL)
	{
		if (*alst != NULL)
		{
			while ((*alst)->next != NULL)
				alst = &(*alst)->next;
			(*alst)->next = new;
			new->prev = *alst;
		}
		else
		{
			new->prev = NULL;
			*alst = new;
		}
	}
}
