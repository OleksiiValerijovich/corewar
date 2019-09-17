/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsm_lexical_analysis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 14:36:33 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 13:23:19 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm/asm.h"
#include "../../../inc/asm/fsm_table_lexical.h"
#include "../../../inc/asm/fsm_lexical_analysis.h"

/*
** the lexical analysis is implemented using finite state machine
** the fsm table is written to header file fsm_table_lexical.h
*/

static void					do_fsm(t_fsm *fsm)
{
	t_transition_callback	worker;
	int						curr_state;
	int						new_state;
	enum e_signals			curr_signal;

	curr_state = 0;
	fsm->curr_line_num = 1;
	fsm->curr_char_in_line_num = 0;
	while (!fsm->finished)
	{
		curr_signal = get_signal(*fsm->curr_position);
		move_forward(fsm);
		new_state = fsm_table[curr_state][curr_signal].new_state;
		worker = fsm_table[curr_state][curr_signal].worker;
		if (worker != NULL)
		{
			worker(fsm);
		}
		curr_state = new_state;
	}
}

void						fsm_lexical_analysis(void)
{
	t_fsm					fsm;

	ft_bzero(&fsm, sizeof(t_fsm));
	fsm.curr_position = g_data.src_file;
	fsm.begin_position = g_data.src_file;
	do_fsm(&fsm);
	if (fsm.errors)
	{
		g_data.error = 1;
		g_data.lexical_errors = fsm.errors;
	}
}
