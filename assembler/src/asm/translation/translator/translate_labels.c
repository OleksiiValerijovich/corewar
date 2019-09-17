/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_labels.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 23:57:34 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 12:52:00 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/syntax_analysis.h"
#include "../../../../inc/asm/translation.h"

static int32_t	try_to_find_forward(char *label, t_dllist *lines,
									u_int32_t *translation)
{
	t_line		*line;
	u_int32_t	size;

	size = 0;
	line = lines->content;
	while (lines)
	{
		line = lines->content;
		if (line->label_first_char)
		{
			if (!ft_memcmp(label, line->label_first_char,
				GREATEST(ft_strlen(label), line->label_len)))
			{
				*translation = size;
				return (1);
			}
		}
		lines = lines->next;
		size = size + line->size;
	}
	return (0);
}

static int32_t	try_to_find_backward(char *label, t_dllist *lines,
									u_int32_t *translation)
{
	t_line		*line;
	u_int32_t	size;

	size = 0;
	lines = lines->prev;
	line = lines->content;
	while (lines)
	{
		line = lines->content;
		if (line->label_first_char)
		{
			if (!ft_memcmp(label, line->label_first_char,
				GREATEST(ft_strlen(label), line->label_len)))
			{
				size = size - line->size;
				*translation = size;
				return (1);
			}
		}
		lines = lines->prev;
		size = size - line->size;
	}
	return (0);
}

static void		translate_label(t_lexem *lexem, t_dllist *lines)
{
	char		*label;
	u_int32_t	translation;

	translation = 0;
	label = get_label_src(lexem);
	translation = try_to_find_backward(label, lines, &translation);
	if (!try_to_find_backward(label, lines, &translation))
		if (!try_to_find_forward(label, lines, &translation))
			nonexistent_label(lexem, label);
	lexem->translation = translation;
	free(label);
}

static void		check_line(t_dllist *lines, t_line *line)
{
	t_dllist	*lexems;
	t_lexem		*lexem;

	lexems = line->first_lexem;
	while (!is_endline(get_lexem(lexems)))
	{
		lexem = lexems->content;
		if (lexem->type == DIRECT_LABEL || lexem->type == INDIRECT_LABEL)
			translate_label(get_lexem(lexems), lines);
		lexems = lexems->next;
	}
}

void			translate_labels(void)
{
	t_dllist	*lines;

	lines = g_data.lines;
	while (lines)
	{
		check_line(lines, lines->content);
		lines = lines->next;
	}
}
