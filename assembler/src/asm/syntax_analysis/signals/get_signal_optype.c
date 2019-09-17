/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_signal_optype.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 10:11:18 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 13:20:08 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/syntax_analysis.h"
#include "../../../../inc/asm/operations.h"

static void			set_signals(int (*signals[18])(t_lexem *lexem))
{
	signals[1] = is_live;
	signals[2] = is_ld;
	signals[3] = is_st;
	signals[4] = is_add;
	signals[5] = is_sub;
	signals[6] = is_and;
	signals[7] = is_or;
	signals[8] = is_xor;
	signals[9] = is_zjmp;
	signals[10] = is_ldi;
	signals[11] = is_sti;
	signals[12] = is_fork;
	signals[13] = is_lld;
	signals[14] = is_lldi;
	signals[15] = is_lfork;
	signals[16] = is_aff;
	signals[17] = NULL;
}

enum e_operations	get_signal_optype(t_lexem *lexem)
{
	static int		(*signals[18])(t_lexem *lexem);
	int				i;

	if (!*signals)
		set_signals(signals);
	i = 1;
	while (signals[i])
	{
		if ((signals[i])(lexem))
		{
			return (i);
		}
		i++;
	}
	return (0);
}
