/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_endline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:00:27 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/14 12:51:47 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/fsm_lexical_analysis.h"

void		create_endline(t_fsm *fsm)
{
	t_lexem	*lexem;

	lexem = ft_smalloc(sizeof(t_lexem));
	lexem->first_char = fsm->begin_position;
	lexem->last_char = fsm->curr_position - 1;
	lexem->len = fsm->curr_position - fsm->begin_position;
	lexem->line_num = fsm->curr_line_num;
	lexem->char_in_line_num = fsm->curr_char_in_line_num;
	lexem->type = ENDLINE;
	fsm->curr_line_num++;
	fsm->curr_char_in_line_num = 0;
	fsm->begin_position = fsm->curr_position;
	add_new_lexem(lexem);
}
