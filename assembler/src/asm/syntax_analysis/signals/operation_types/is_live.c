/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:02:58 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 17:05:54 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/asm/asm.h"
#include "../../../../../inc/asm/operations.h"

int		is_live(t_lexem *lexem)
{
	if (!lexem->translation)
	{
		if (!ft_memcmp(lexem->first_char, "live", lexem->len))
		{
			lexem->translation = OPERATION_LIVE;
			return (1);
		}
	}
	else if (lexem->translation == OPERATION_LIVE)
		return (1);
	return (0);
}
