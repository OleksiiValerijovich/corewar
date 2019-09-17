/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:58:33 by ishyian           #+#    #+#             */
/*   Updated: 2019/05/06 12:58:37 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_dllstins(t_dllist *prev, t_dllist *new, t_dllist *next)
{
	if (prev && new && next)
	{
		prev->next = new;
		new->prev = prev;
		next->prev = new;
		new->next = next;
	}
}
