/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_signal_fsm_syn.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:06:47 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 14:11:38 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/syntax_analysis.h"

static void			set_signals(int (*signals[7])(t_lexem *lexem))
{
	signals[0] = is_null_syn;
	signals[1] = is_command;
	signals[2] = is_operation;
	signals[3] = is_label;
	signals[4] = is_string;
	signals[5] = is_endline;
	signals[6] = NULL;
}

enum e_signals_syn	get_signal_fsm_syn(t_lexem *lexem)
{
	static int		(*signals[7])(t_lexem *);
	int				i;

	if (!*signals)
		set_signals(signals);
	i = 0;
	while (signals[i])
	{
		if ((signals[i])(lexem))
		{
			return (i);
		}
		i++;
	}
	return (other);
}
