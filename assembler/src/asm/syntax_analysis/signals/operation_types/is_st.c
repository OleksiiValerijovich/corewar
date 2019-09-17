/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:39:55 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 17:06:48 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/asm/asm.h"
#include "../../../../../inc/asm/operations.h"

int		is_st(t_lexem *lexem)
{
	if (!lexem->translation)
	{
		if (!ft_memcmp(lexem->first_char, "st", lexem->len))
		{
			lexem->translation = OPERATION_ST;
			return (1);
		}
	}
	else if (lexem->translation == OPERATION_ST)
		return (1);
	return (0);
}
