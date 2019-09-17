/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_line_starts_with_wrong_lexem.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:58:02 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 16:44:50 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/syntax_analysis.h"

void		error_line_starts_with_wrong_lexem(t_fsm_syn *fsm_syn)
{
	g_data.syntax_errors++;
	g_data.error = 1;
	ft_printf("Syntax error: line %d starts with wrong lexem\n",
	fsm_syn->line_num);
	go_to_next_eol(fsm_syn);
}
