/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 09:38:17 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 15:15:46 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/syntax_analysis.h"
#include "../../../../inc/asm/syntax_analysis_table.h"

static void				print_error(t_fsm_syn *fsm_syn)
{
	t_lexem				*lexem;

	lexem = fsm_syn->lexems->content;
	if (lexem->type != ENDLINE)
		ft_printf("Syntax error: line %d contains wrong instruction syntax \
(lexem [%:*s], type [%s])\n", fsm_syn->line_num, lexem->len,
	lexem->first_char, get_lexem_type_name(lexem->type));
	else
		ft_printf("Syntax error: line %d contains wrong instruction syntax \
(lexem [EOL], type [%s])\n",
	fsm_syn->line_num, get_lexem_type_name(lexem->type));
}

static void				error(t_fsm_syn *fsm_syn)
{
	g_data.error = 1;
	g_data.syntax_errors++;
	if (fsm_syn->lexems)
	{
		print_error(fsm_syn);
		if (!is_endline(get_lexem(fsm_syn->lexems->content)))
			go_to_next_eol(fsm_syn);
	}
	else
		ft_printf("Syntax error: line %d ends unexpectedly\n",
		fsm_syn->line_num);
}

void					check_instruction(t_fsm_syn *fsm_syn)
{
	enum e_operations	optype;
	int					i;

	i = 0;
	optype = get_signal_optype(fsm_syn->lexems->prev->content);
	while (instruction_table[optype][i].worker)
	{
		if (fsm_syn->lexems &&
			instruction_table[optype][i].worker(fsm_syn->lexems->content))
		{
			go_to_next_lexem(fsm_syn);
			i++;
		}
		else
		{
			error(fsm_syn);
			break ;
		}
	}
}
