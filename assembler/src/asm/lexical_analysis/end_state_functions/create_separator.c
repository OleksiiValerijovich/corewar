/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_separator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:02:08 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/14 12:53:30 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/fsm_lexical_analysis.h"

void		create_separator(t_fsm *fsm)
{
	t_lexem	*lexem;

	lexem = ft_smalloc(sizeof(t_lexem));
	lexem->first_char = fsm->begin_position;
	lexem->last_char = fsm->curr_position - 1;
	lexem->len = fsm->curr_position - fsm->begin_position;
	lexem->line_num = fsm->curr_line_num;
	lexem->char_in_line_num = fsm->curr_char_in_line_num;
	lexem->type = SEPARATOR;
	fsm->begin_position = fsm->curr_position;
	add_new_lexem(lexem);
}
