/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_label_instruction.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:54:25 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 19:12:36 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/syntax_analysis.h"
#include "../../../../inc/asm/translation.h"

static void			process_label_(t_lexem *lexem, t_line *line)
{
	line->label_first_char = lexem->first_char;
	line->label_len = lexem->len - 1;
}

void				process_label_instruction(t_line *line)
{
	t_dllist		*lexems;
	t_lexem			*lexem;

	lexems = line->first_lexem;
	lexem = get_next_lexem(&lexems);
	process_label_(lexem, line);
	lexem = get_next_lexem(&lexems);
	if (is_endline(lexem))
		return ;
	else if (is_operation(lexem))
	{
		line->first_lexem = line->first_lexem->next;
		process_instruction(line);
	}
}
