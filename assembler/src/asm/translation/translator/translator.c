/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:16:14 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 03:43:23 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/syntax_analysis.h"
#include "../../../../inc/asm/translation.h"

static void		translate_registry(t_dllist *lexems, t_translation *translate,
									t_line *line, int *i)
{
	get_lexem(lexems)->size = REG_SIZE;
	line->size = line->size + REG_SIZE;
	lexem_translator_reg_dir_ind(get_lexem(lexems));
	update_args_code(translate, REG_CODE, *i);
	(*i)++;
}

static void		translate_direct(t_dllist *lexems, t_translation *translate,
									t_line *line, int *i)
{
	get_lexem(lexems)->size = translate->dir_size;
	line->size = line->size + translate->dir_size;
	lexem_translator_reg_dir_ind(get_lexem(lexems));
	update_args_code(translate, DIR_CODE, *i);
	(*i)++;
}

static void		translate_indirect(t_dllist *lexems, t_translation *translate,
									t_line *line, int *i)
{
	get_lexem(lexems)->size = IND_SIZE;
	line->size = line->size + IND_SIZE;
	lexem_translator_reg_dir_ind(get_lexem(lexems));
	update_args_code(translate, IND_CODE, *i);
	(*i)++;
}

static void		translate_it(t_dllist *lexems, t_translation *translate,
									t_line *line)
{
	int			i;

	i = 0;
	while (!is_endline(get_lexem(lexems)))
	{
		if (is_reg(get_lexem(lexems)))
			translate_registry(lexems, translate, line, &i);
		else if (is_dir(get_lexem(lexems)))
			translate_direct(lexems, translate, line, &i);
		else if (is_ind(get_lexem(lexems)))
			translate_indirect(lexems, translate, line, &i);
		lexems = lexems->next;
	}
}

void			translator(t_translation *translate, t_line *line)
{
	t_dllist	*lexems;

	line->size = line->size + 1;
	line->is_args_code = translate->is_arg_code;
	if (line->is_args_code)
		line->size++;
	lexems = line->first_lexem;
	get_lexem(lexems)->size = 1;
	lexems = lexems->next;
	translate_it(lexems, translate, line);
	line->args_code = translate->args_code;
}
