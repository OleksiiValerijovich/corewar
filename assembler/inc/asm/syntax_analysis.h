/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:32:02 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 18:10:39 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_ANALYSIS_H
# define SYNTAX_ANALYSIS_H
# include "./asm.h"

enum					e_signals_syn
{
	null,
	command,
	operation,
	label,
	string,
	eol,
	other
};

typedef struct			s_fsm_syn
{
	t_dllist			*lexems;
	size_t				errors;
	size_t				line_num;
	_Bool				finished:1;
}						t_fsm_syn;

typedef void			(*t_transition_fsm)(t_fsm_syn *fsm_syn);

struct					s_transition_fsm_
{
	int					state;
	t_transition_fsm	worker;
}						t_transition_fsm_;

typedef int				(*t_transition_table)(t_lexem *lexem);

struct					s_transition_table_
{
	t_transition_table	worker;
}						t_transition_table_;

void					check_instruction(t_fsm_syn *fsm_syn);
void					set_as_finished_syn(t_fsm_syn *fsm_syn);
enum e_signals_syn		get_signal_fsm_syn(t_lexem *lexem);
enum e_operations		get_signal_optype(t_lexem *lexem);
void					go_to_next_lexem(t_fsm_syn *fsm_syn);
void					go_to_next_eol(t_fsm_syn *fsm_syn);
void					check_commands_sequence(void);
int						is_null_syn(t_lexem *lexem);
int						is_dir(t_lexem *lexem);
int						is_ind(t_lexem *lexem);
int						is_reg(t_lexem *lexem);
int						is_reg_dir_ind(t_lexem *lexem);
int						is_reg_ind(t_lexem *lexem);
int						is_dir_ind(t_lexem *lexem);
int						is_command(t_lexem *lexem);
int						is_label(t_lexem *lexem);
int						is_operation(t_lexem *lexem);
int						is_string(t_lexem *lexem);
int						is_endline(t_lexem *lexem);
int						is_sep(t_lexem *lexem);
int						is_reg_dir(t_lexem *lexem);
int						is_add(t_lexem *lexem);
int						is_aff(t_lexem *lexem);
int						is_and(t_lexem *lexem);
int						is_fork(t_lexem *lexem);
int						is_ld(t_lexem *lexem);
int						is_ldi(t_lexem *lexem);
int						is_lfork(t_lexem *lexem);
int						is_live(t_lexem *lexem);
int						is_lld(t_lexem *lexem);
int						is_lldi(t_lexem *lexem);
int						is_or(t_lexem *lexem);
int						is_st(t_lexem *lexem);
int						is_sti(t_lexem *lexem);
int						is_sub(t_lexem *lexem);
int						is_xor(t_lexem *lexem);
int						is_zjmp(t_lexem *lexem);
void					error_line_starts_with_wrong_lexem(t_fsm_syn *fsm_syn);
void					error_wrong_command_syntax(t_fsm_syn *fsm_syn);
void					error_wrong_command_syntax_to_eol(t_fsm_syn *fsm_syn);
void					error_wrong_lexem_after_label(t_fsm_syn *fsm_syn);
void					error_wrong_lexem_after_label_to_eol(t_fsm_syn
															*fsm_syn);
void					error_unexpected_end(t_fsm_syn *fsm_syn);

#endif
