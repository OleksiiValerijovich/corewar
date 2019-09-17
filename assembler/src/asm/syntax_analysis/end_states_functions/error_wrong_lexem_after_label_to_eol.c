/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_wrong_lexem_after_label_to_eol.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:22:57 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 12:13:35 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/syntax_analysis.h"

void		error_wrong_lexem_after_label_to_eol(t_fsm_syn *fsm_syn)
{
	g_data.syntax_errors++;
	g_data.error = 1;
	ft_printf("Syntax error: line %d contains wrong lexem after label\n",
	fsm_syn->line_num);
	go_to_next_eol(fsm_syn);
}
