/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:39:58 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 17:06:33 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/asm/asm.h"
#include "../../../../../inc/asm/operations.h"

int		is_or(t_lexem *lexem)
{
	if (!lexem->translation)
	{
		if (!ft_memcmp(lexem->first_char, "or", lexem->len))
		{
			lexem->translation = OPERATION_OR;
			return (1);
		}
	}
	else if (lexem->translation == OPERATION_OR)
		return (1);
	return (0);
}
