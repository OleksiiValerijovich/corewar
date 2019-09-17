/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands_sequence.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:25:50 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 15:29:16 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm/asm.h"
#include "../../../inc/asm/syntax_analysis.h"

static void		error(t_lexem *lexem)
{
	g_data.syntax_errors++;
	g_data.error = 1;
	ft_printf("Syntax error: line %d contains command after \
instructions began\n", lexem->line_num);
}

static int		check(t_lexem *lexem)
{
	return (is_command(lexem) || is_endline(lexem) || is_string(lexem));
}

static void		goer(t_dllist *lexems)
{
	_Bool		instructions_began;

	instructions_began = 0;
	while (lexems)
	{
		if (!check(get_lexem(lexems)))
			instructions_began = 1;
		else if (instructions_began && is_command(get_lexem(lexems)))
			error(get_lexem(lexems));
		lexems = lexems->next;
	}
}

void			check_commands_sequence(void)
{
	t_dllist	*lexems;

	lexems = g_data.lexems;
	goer(lexems);
}
