/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsm_lexical_analysis.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:30:37 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 13:10:10 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FSM_LEXICAL_ANALYSIS_H
# define FSM_LEXICAL_ANALYSIS_H
# define EOL_CHAR			'\n'
# define CMD_CHAR			'.'
# define NAME_CMD_STRING	"name"
# define COMMENT_CMD_STRING	"comment"
# define QUOTE				'"'
# define COMMENT_CHAR		'#'
# define COMMENT_CHAR_ALT	';'
# define LABEL_CHAR			':'
# define DIRECT_CHAR		'%'
# define SIGN				'-'
# define SEPARATOR_CHAR		','
# define ALPHA				"abcdefghijklmnopqstuvwxyz"
# define REGISTRY_ALPHA		'r'
# define DIGITS				"0123456789"
# define UNDERLINE_CHAR		'_'

# include <string.h>
# include "./lexems.h"

/*
** here are the incoming signals for lexical analysis
*/

enum						e_signals
{
	null,
	eol_char,
	cmd_char,
	comment_char,
	label_char,
	direct_char,
	sign,
	separator_char,
	underline_char,
	alpha,
	reg_aplha,
	digits,
	space_char,
	quote,
	other
};

typedef struct				s_fsm
{
	char					*curr_position;
	char					*begin_position;
	size_t					errors;
	size_t					curr_line_num;
	size_t					curr_char_in_line_num;
	enum e_lexems			type;
	unsigned char			finished;
}							t_fsm;

typedef void				(*t_transition_callback)(t_fsm *fsm);

struct						s_transition
{
	int						new_state;
	t_transition_callback	worker;
}							t_transition;

typedef struct				s_signal_functions
{
	int (*array[15])(char c);
}							t_signal_functions;

enum e_signals				get_signal(char c);
void						move_forward(t_fsm *fsm);
void						move_back(t_fsm *fsm);
void						create_command(t_fsm *fsm);
void						create_endline(t_fsm *fsm);
void						create_separator(t_fsm *fsm);
void						create_string(t_fsm *fsm);
void						create_direct_label(t_fsm *fsm);
void						create_direct(t_fsm *fsm);
void						create_indirect(t_fsm *fsm);
void						create_indirect_label(t_fsm *fsm);
void						create_registry(t_fsm *fsm);
void						create_label(t_fsm *fsm);
void						create_operation(t_fsm *fsm);
void						end_of_comment(t_fsm *fsm);
void						eol(t_fsm *fsm);
void						lexical_error(t_fsm *fsm);
void						lexical_error_move_back(t_fsm *fsm);
void						set_as_finished(t_fsm *fsm);
void						set_begin_equal_to_current(t_fsm *fsm);
int							is_alfa(char c);
int							is_cmd_char(char c);
int							is_comment_char(char c);
int							is_digit(char c);
int							is_dir_char(char c);
int							is_eol(char c);
int							is_label_char(char c);
int							is_null(char c);
int							is_quote(char c);
int							is_registry_alfa(char c);
int							is_separator(char c);
int							is_sign(char c);
int							is_space(char c);
int							is_underline(char c);

#endif
