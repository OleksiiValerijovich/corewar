/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_next_lexem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 08:59:28 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 12:11:25 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm/asm.h"
#include "../../../inc/asm/syntax_analysis.h"

void		go_to_next_lexem(t_fsm_syn *fsm_syn)
{
	if (fsm_syn->lexems)
	{
		fsm_syn->line_num = ((t_lexem *)fsm_syn->lexems->content)->line_num;
		fsm_syn->lexems = fsm_syn->lexems->next;
	}
}
