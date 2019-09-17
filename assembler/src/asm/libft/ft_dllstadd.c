/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:19:42 by ishyian           #+#    #+#             */
/*   Updated: 2019/06/21 15:52:29 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_dllstadd(t_dllist **alst, t_dllist *new)
{
	if (alst != NULL && new != NULL)
	{
		new->next = *alst;
		if (*alst)
			(*alst)->prev = new;
		*alst = new;
	}
}
