/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_wrong_command_syntax.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:58:02 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 17:56:07 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/syntax_analysis.h"

void			error_wrong_command_syntax(t_fsm_syn *fsm_syn)
{
	g_data.syntax_errors++;
	g_data.error = 1;
	ft_printf("Syntax error: line %d contains wrong command syntax\n",
	fsm_syn->line_num);
	go_to_next_eol(fsm_syn);
}
