/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_registry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:01:55 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/14 12:52:22 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/fsm_lexical_analysis.h"

void		create_registry(t_fsm *fsm)
{
	t_lexem	*lexem;

	lexem = ft_smalloc(sizeof(t_lexem));
	lexem->first_char = fsm->begin_position;
	lexem->last_char = fsm->curr_position - 2;
	lexem->len = fsm->curr_position - fsm->begin_position - 1;
	lexem->line_num = fsm->curr_line_num;
	lexem->char_in_line_num = fsm->curr_char_in_line_num;
	lexem->type = REGISTRY;
	move_back(fsm);
	fsm->begin_position = fsm->curr_position;
	add_new_lexem(lexem);
}
