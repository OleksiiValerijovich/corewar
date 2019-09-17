/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis_fsm_table.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:51:20 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 18:11:36 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_ANALYSIS_FSM_TABLE_H
# define SYNTAX_ANALYSIS_FSM_TABLE_H
# include "./asm.h"
# include "./syntax_analysis.h"

struct s_transition_fsm_	fsm_table_syn[4][7] =
{
	[0][null] = {0, set_as_finished_syn},
	[0][command] = {1, NULL},
	[0][operation] = {0, check_instruction},
	[0][label] = {3, NULL},
	[0][string] = {0, error_line_starts_with_wrong_lexem},
	[0][eol] = {0, NULL},
	[0][other] = {0, error_line_starts_with_wrong_lexem},
	[1][null] = {0, error_unexpected_end},
	[1][command] = {0, error_wrong_command_syntax_to_eol},
	[1][operation] = {0, error_wrong_command_syntax_to_eol},
	[1][label] = {0, error_wrong_command_syntax_to_eol},
	[1][string] = {2, NULL},
	[1][eol] = {0, error_wrong_command_syntax},
	[1][other] = {0, error_wrong_command_syntax_to_eol},
	[2][null] = {0, error_unexpected_end},
	[2][command] = {0, error_wrong_command_syntax_to_eol},
	[2][operation] = {0, error_wrong_command_syntax_to_eol},
	[2][label] = {0, error_wrong_command_syntax_to_eol},
	[2][string] = {0, error_wrong_command_syntax_to_eol},
	[2][eol] = {0, NULL},
	[2][other] = {0, error_wrong_command_syntax_to_eol},
	[3][null] = {0, error_unexpected_end},
	[3][command] = {0, error_wrong_lexem_after_label_to_eol},
	[3][operation] = {0, check_instruction},
	[3][label] = {0, error_wrong_lexem_after_label_to_eol},
	[3][string] = {0, error_wrong_lexem_after_label_to_eol},
	[3][eol] = {0, NULL},
	[3][other] = {0, error_wrong_lexem_after_label_to_eol},
};

#endif
