/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:39:49 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 17:07:36 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/asm/asm.h"
#include "../../../../../inc/asm/operations.h"

int		is_zjmp(t_lexem *lexem)
{
	if (!lexem->translation)
	{
		if (!ft_memcmp(lexem->first_char, "zjmp", lexem->len))
		{
			lexem->translation = OPERATION_ZJMP;
			return (1);
		}
	}
	else if (lexem->translation == OPERATION_ZJMP)
		return (1);
	return (0);
}
