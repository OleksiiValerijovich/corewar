/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:40:09 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 17:04:58 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/asm/asm.h"
#include "../../../../../inc/asm/operations.h"

int		is_fork(t_lexem *lexem)
{
	if (!lexem->translation)
	{
		if (!ft_memcmp(lexem->first_char, "fork", lexem->len))
		{
			lexem->translation = OPERATION_FORK;
			return (1);
		}
	}
	else if (lexem->translation == OPERATION_FORK)
		return (1);
	return (0);
}
