# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/04 12:06:50 by ishyian           #+#    #+#              #
#    Updated: 2019/09/17 12:15:02 by ishyian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =				gcc
NAME =				../asm
CFLAGS =			-Wall -Wextra -Werror
SRCS =				./src/asm/asm.c \
					./src/asm/usage.c \
					./src/asm/error_processor.c \
					./src/asm/display_exec_code.c \
					./src/asm/files/process_file.c \
					./src/asm/files/display_error_count.c \
					./src/asm/files/options.c \
					./src/asm/flags/process_flag.c \
					./src/asm/get_lexem.c \
					./src/asm/free_data.c \
					./src/asm/lexical_analysis/fsm_lexical_analysis.c \
					./src/asm/lexical_analysis/signals/get_signal.c \
					./src/asm/lexical_analysis/signals/is_alfa.c \
					./src/asm/lexical_analysis/signals/is_cmd_char.c \
					./src/asm/lexical_analysis/signals/is_comment_char.c \
					./src/asm/lexical_analysis/signals/is_digit.c \
					./src/asm/lexical_analysis/signals/is_dir_char.c \
					./src/asm/lexical_analysis/signals/is_eol.c \
					./src/asm/lexical_analysis/signals/is_label_char.c \
					./src/asm/lexical_analysis/signals/is_null.c \
					./src/asm/lexical_analysis/signals/is_quote.c \
					./src/asm/lexical_analysis/signals/is_registry_alfa.c \
					./src/asm/lexical_analysis/signals/is_separator.c \
					./src/asm/lexical_analysis/signals/is_sign.c \
					./src/asm/lexical_analysis/signals/is_space.c \
					./src/asm/lexical_analysis/signals/is_underline.c \
					./src/asm/lexical_analysis/add_new_lexem.c \
					./src/asm/lexical_analysis/move_forward.c \
					./src/asm/lexical_analysis/move_back.c \
					./src/asm/print_lexems/get_lexem_type_name.c \
					./src/asm/print_lexems/print_lines.c \
					./src/asm/lexical_analysis/end_state_functions/create_command.c \
					./src/asm/lexical_analysis/end_state_functions/create_direct_label.c \
					./src/asm/lexical_analysis/end_state_functions/create_direct.c \
					./src/asm/lexical_analysis/end_state_functions/create_endline.c \
					./src/asm/lexical_analysis/end_state_functions/create_indirect_label.c \
					./src/asm/lexical_analysis/end_state_functions/create_indirect.c \
					./src/asm/lexical_analysis/end_state_functions/create_operation.c \
					./src/asm/lexical_analysis/end_state_functions/create_label.c \
					./src/asm/lexical_analysis/end_state_functions/create_registry.c \
					./src/asm/lexical_analysis/end_state_functions/create_separator.c \
					./src/asm/lexical_analysis/end_state_functions/create_string.c \
					./src/asm/lexical_analysis/end_state_functions/lexical_error.c \
					./src/asm/lexical_analysis/end_state_functions/lexical_error_move_back.c \
					./src/asm/lexical_analysis/end_state_functions/set_as_finished.c \
					./src/asm/lexical_analysis/end_state_functions/set_begin_equal_to_current.c \
					./src/asm/lexical_analysis/end_state_functions/end_of_comment.c \
					./src/asm/lexical_analysis/end_state_functions/eol.c \
					./src/asm/syntax_analysis/fsm_syntax_analysis.c \
					./src/asm/syntax_analysis/go_to_next_lexem.c \
					./src/asm/syntax_analysis/go_to_next_eol.c \
					./src/asm/syntax_analysis/check_commands_sequence.c \
					./src/asm/syntax_analysis/signals/operation_types/is_add.c \
					./src/asm/syntax_analysis/signals/operation_types/is_aff.c \
					./src/asm/syntax_analysis/signals/operation_types/is_and.c \
					./src/asm/syntax_analysis/signals/operation_types/is_fork.c \
					./src/asm/syntax_analysis/signals/operation_types/is_ld.c \
					./src/asm/syntax_analysis/signals/operation_types/is_ldi.c \
					./src/asm/syntax_analysis/signals/operation_types/is_lfork.c \
					./src/asm/syntax_analysis/signals/operation_types/is_live.c \
					./src/asm/syntax_analysis/signals/operation_types/is_lld.c \
					./src/asm/syntax_analysis/signals/operation_types/is_lldi.c \
					./src/asm/syntax_analysis/signals/operation_types/is_or.c \
					./src/asm/syntax_analysis/signals/operation_types/is_st.c \
					./src/asm/syntax_analysis/signals/operation_types/is_sti.c \
					./src/asm/syntax_analysis/signals/operation_types/is_sub.c \
					./src/asm/syntax_analysis/signals/operation_types/is_xor.c \
					./src/asm/syntax_analysis/signals/operation_types/is_zjmp.c \
					./src/asm/syntax_analysis/signals/lexem_types/is_command.c \
					./src/asm/syntax_analysis/signals/lexem_types/is_dir.c \
					./src/asm/syntax_analysis/signals/lexem_types/is_dir_ind.c \
					./src/asm/syntax_analysis/signals/lexem_types/is_ind.c \
					./src/asm/syntax_analysis/signals/lexem_types/is_label.c \
					./src/asm/syntax_analysis/signals/lexem_types/is_operation.c \
					./src/asm/syntax_analysis/signals/lexem_types/is_reg.c \
					./src/asm/syntax_analysis/signals/lexem_types/is_reg_dir_ind.c \
					./src/asm/syntax_analysis/signals/lexem_types/is_string.c \
					./src/asm/syntax_analysis/signals/lexem_types/is_endline.c \
					./src/asm/syntax_analysis/signals/lexem_types/is_sep.c \
					./src/asm/syntax_analysis/signals/lexem_types/is_reg_ind.c \
					./src/asm/syntax_analysis/signals/lexem_types/is_reg_dir.c \
					./src/asm/syntax_analysis/signals/is_null_syn.c \
					./src/asm/syntax_analysis/signals/get_signal_fsm_syn.c \
					./src/asm/syntax_analysis/signals/get_signal_optype.c \
					./src/asm/syntax_analysis/end_states_functions/error_line_starts_with_wrong_lexem.c \
					./src/asm/syntax_analysis/end_states_functions/error_wrong_command_syntax.c \
					./src/asm/syntax_analysis/end_states_functions/error_wrong_lexem_after_label.c \
					./src/asm/syntax_analysis/end_states_functions/error_wrong_command_syntax_to_eol.c \
					./src/asm/syntax_analysis/end_states_functions/error_wrong_lexem_after_label_to_eol.c \
					./src/asm/syntax_analysis/end_states_functions/error_unexpected_end.c \
					./src/asm/syntax_analysis/end_states_functions/check_instruction.c \
					./src/asm/syntax_analysis/end_states_functions/set_as_finished_syn.c \
					./src/asm/translation/translation.c \
					./src/asm/translation/get_next_lexem.c \
					./src/asm/translation/get_exec_size.c \
					./src/asm/translation/process_lines/create_lines_list.c \
					./src/asm/translation/process_lines/process_lines.c \
					./src/asm/translation/process_lines/process_command.c \
					./src/asm/translation/process_lines/process_label_instruction.c \
					./src/asm/translation/process_lines/process_instruction.c \
					./src/asm/translation/signals/is_dir_not_label.c \
					./src/asm/translation/signals/is_ind_not_label.c \
					./src/asm/translation/signals/is_reg_not_label.c \
					./src/asm/translation/signals/is_reg_dir_ind_not_label.c \
					./src/asm/translation/translator/translator.c \
					./src/asm/translation/translator/lexem_translator_reg_dir_ind.c \
					./src/asm/translation/translator/registry_translator.c \
					./src/asm/translation/translator/direct_translator.c \
					./src/asm/translation/translator/indirect_translator.c \
					./src/asm/translation/translator/get_args_code.c \
					./src/asm/translation/translator/translate_labels.c \
					./src/asm/translation/translator/get_label_src.c \
					./src/asm/translation/validation/check_size.c \
					./src/asm/translation/errors/error_unsupported_command.c \
					./src/asm/translation/errors/error_no_comment_command.c \
					./src/asm/translation/errors/error_no_name_command.c \
					./src/asm/translation/errors/to_big_argument.c \
					./src/asm/translation/errors/to_low_argument.c \
					./src/asm/translation/errors/nonexistent_label.c \
					./src/asm/translation/errors/registry_invalid_num.c \
					./src/asm/write_code_to_file/write_code_to_file.c \
					./src/asm/write_code_to_file/write_big_endian.c \
					./src/asm/write_code_to_file/write_it.c \
					./src/asm/write_code_to_file/check_string_lens.c

OBJ =				$(SRCS:.c=.o)
LIBS = 				-lft
LIB_DIR =			./src/asm/libft/
LIB_FT =			./src/asm/libft/libft.a
INCLUDE_DIR	=		./inc/asm/
INCLUDES =			./inc/asm/asm.h \
					./inc/asm/fsm_lexical_analysis.h \
					./inc/asm/fsm_table_lexical.h \
					./inc/asm/lexems.h \
					./inc/asm/operations.h \
					./inc/asm/translation.h \
					./inc/asm/syntax_analysis_fsm_table.h \
					./inc/asm/syntax_analysis_table.h \
					./inc/asm/syntax_analysis.h \
					./inc/asm/write_code_to_file.h

.SILENT:

all: 				prerequisites $(NAME)

prerequisites:
					make -C $(LIB_DIR)

$(NAME):			$(LIB_FT) $(OBJ)
					$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS) -L $(LIB_DIR)

$(OBJ): 			%.o: %.c $(INCLUDES)
					$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -o $@ -c $<

clean:
					rm -f $(OBJ)
					make clean -C $(LIB_DIR)

fclean: 			clean
					rm -f $(NAME)
					make fclean -C $(LIB_DIR)

re: 				fclean all

.PHONY: 			all libft clean fclean re prerequisites
