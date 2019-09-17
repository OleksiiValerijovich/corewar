/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:40:06 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 17:05:28 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/asm/asm.h"
#include "../../../../../inc/asm/operations.h"

int		is_ldi(t_lexem *lexem)
{
	if (!lexem->translation)
	{
		if (!ft_memcmp(lexem->first_char, "ldi", lexem->len))
		{
			lexem->translation = OPERATION_LDI;
			return (1);
		}
	}
	else if (lexem->translation == OPERATION_LDI)
		return (1);
	return (0);
}
