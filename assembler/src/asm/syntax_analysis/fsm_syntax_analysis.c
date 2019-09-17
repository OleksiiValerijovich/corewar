/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsm_syntax_analysis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:36:41 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 18:17:28 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm/asm.h"
#include "../../../inc/asm/syntax_analysis.h"
#include "../../../inc/asm/syntax_analysis_fsm_table.h"

/*
** the lexical analysis is implemented using finite state machine
** the fsm table is written to header file syntax_analysis_fsm_table.h
** An addition table for check_instruction saved in file syntax_analysis_table.h
*/

static void					do_fsm_syntax(t_fsm_syn *fsm_syn)
{
	t_transition_fsm		worker;
	int						curr_state;
	int						new_state;
	enum e_signals_syn		curr_signal;

	curr_state = 0;
	while (!fsm_syn->finished)
	{
		curr_signal = get_signal_fsm_syn(get_lexem(fsm_syn->lexems));
		go_to_next_lexem(fsm_syn);
		new_state = fsm_table_syn[curr_state][curr_signal].state;
		worker = fsm_table_syn[curr_state][curr_signal].worker;
		if (worker != NULL)
		{
			worker(fsm_syn);
		}
		curr_state = new_state;
	}
}

void						fsm_syntax_analysis(void)
{
	t_fsm_syn				fsm_syn;

	ft_bzero(&fsm_syn, sizeof(t_fsm_syn));
	fsm_syn.lexems = g_data.lexems;
	do_fsm_syntax(&fsm_syn);
	if (fsm_syn.errors)
	{
		g_data.error = 1;
		g_data.syntax_errors = fsm_syn.errors;
	}
	check_commands_sequence();
}
