/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 09:52:58 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 03:15:42 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSLATION_H
# define TRANSLATION_H
# define REG_CODE 1
# define DIR_CODE 2
# define IND_CODE 3
# define REG_SIZE 1
# define IND_SIZE 2

# include "./asm.h"

typedef struct			s_translation
{
	u_int8_t			operation;
	u_int8_t			args_code;
	_Bool				is_arg_code:1;
	u_int32_t			dir_size;
}						t_translation;

void					create_lines_list(void);
void					process_lines(void);
void					process_command(t_line *line);
void					process_label_instruction(t_line *line);
void					process_instruction(t_line *line);
t_lexem					*get_next_lexem(t_dllist **lexems);
void					translator(t_translation *translate, t_line *line);
int						is_reg_not_label(t_lexem *lexem);
int						is_dir_not_label(t_lexem *lexem);
int						is_ind_not_label(t_lexem *lexem);
int						is_reg_dir_ind_not_label(t_lexem *lexem);
void					lexem_translator_reg_dir_ind(t_lexem *lexem);
void					registry_translator(t_lexem *lexem);
void					indirect_translator(t_lexem *lexem);
void					direct_translator(t_lexem *lexem);
void					check_size_src(t_lexem *lexem, char *src);
void					update_args_code(t_translation *translate,
											u_int8_t arg_code, int i);
void					get_exec_size(void);
void					translate_labels(void);
char					*get_label_src(t_lexem *lexem);
void					error_unsupported_command(t_line *line);
void					error_no_name_command(void);
void					error_no_comment_command(void);
void					registry_invalid_num(t_lexem *lexem);
void					nonexistent_label(t_lexem *lexem, char *src);
void					to_big_argument(t_lexem *lexem, char *src);
void					to_low_argument(t_lexem *lexem, char *src);

#endif
