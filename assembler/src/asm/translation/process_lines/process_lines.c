/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:31:39 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 03:40:28 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/syntax_analysis.h"
#include "../../../../inc/asm/translation.h"

static void				set_functions(void (*functions[4])(t_line *line))
{
	functions[0] = process_command;
	functions[1] = process_label_instruction;
	functions[2] = process_instruction;
	functions[3] = NULL;
}

static void				set_signals(int (*signals[4])(t_lexem *lexem))
{
	signals[0] = is_command;
	signals[1] = is_label;
	signals[2] = is_operation;
	signals[3] = NULL;
}

static void				process_line(t_line *line)
{
	static int			(*signals[4])(t_lexem *lexem);
	static void			(*functions[4])(t_line *line);
	t_dllist			*lexems;
	int					i;

	set_signals(signals);
	set_functions(functions);
	lexems = line->first_lexem;
	i = 0;
	while (signals[i])
	{
		if (signals[i](lexems->content))
		{
			functions[i](line);
			break ;
		}
		i++;
	}
}

void					process_lines(void)
{
	t_dllist			*lines;

	lines = g_data.lines;
	while (lines)
	{
		process_line(lines->content);
		lines = lines->next;
	}
}
