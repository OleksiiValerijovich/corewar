/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:40:14 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 17:08:32 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/asm/asm.h"
#include "../../../../../inc/asm/operations.h"

int		is_add(t_lexem *lexem)
{
	if (!lexem->translation)
	{
		if (!ft_memcmp(lexem->first_char, "add", lexem->len))
		{
			lexem->translation = OPERATION_ADD;
			return (1);
		}
	}
	else if (lexem->translation == OPERATION_ADD)
		return (1);
	return (0);
}
