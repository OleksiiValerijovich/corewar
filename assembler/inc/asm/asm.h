/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:57:17 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 03:33:10 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "../../src/asm/libft/libft.h"
# include "./lexems.h"
# include "./operations.h"

/*
** flags:
** -w or --warning:
** display warnings and fixable errors as warnings and fix fixable errors
** -t or --translation:
** display source code and it's translation code (VM code) in HEX
*/

typedef struct		s_flags
{
	_Bool			exec_size:1;
	_Bool			translation:1;
}					t_flags;

typedef struct		s_lexem
{
	char			*first_char;
	char			*last_char;
	size_t			len;
	int32_t			line_num;
	int32_t			char_in_line_num;
	enum e_lexems	type;
	size_t			size;
	u_int32_t		translation;
}					t_lexem;

typedef	struct		s_line
{
	char			*label_first_char;
	size_t			label_len;
	char			*first_char;
	t_dllist		*first_lexem;
	int32_t			line_num;
	size_t			size;
	_Bool			is_args_code:1;
	u_int8_t		args_code;
}					t_line;

/*
** t_data struct contains all data related to the current processing file
*/

typedef struct		s_data
{
	char			*filename;
	char			*champ_name;
	char			*comment;
	size_t			src_lines_num;
	size_t			src_total_size;
	t_list			*src_buff_list;
	char			*src_file;
	t_dllist		*lexems;
	t_dllist		*lines;
	t_dllist		*last_line;
	size_t			lexical_errors;
	size_t			syntax_errors;
	size_t			exec_size;
	_Bool			error:1;
}					t_data;

int					g_state;
t_flags				g_flags;
t_data				g_data;

void				usage(void);
int					process_flag(char *flag);
void				process_file(char *filename);
void				display_error_count(void);
void				display_exec_code(void);
void				fsm_lexical_analysis(void);
void				add_new_lexem(t_lexem *lexem);
char				*get_lexem_type_name(enum e_lexems signal);
void				fsm_syntax_analysis(void);
t_lexem				*get_lexem(t_dllist *lexem_list_item);
void				translation(void);
void				write_code_to_file(void);
void				options(void);
void				print_lines(t_dllist *lines);
void				error_processor(int *state, char *str);
void				free_data(void);
void				print_lines(t_dllist *lines);

#endif
