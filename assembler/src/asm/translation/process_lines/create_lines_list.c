/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lines_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:59:20 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 14:35:32 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"

/*
** new 'lines' creates after ENDLINE lexems
** (except first new 'line', which creates with the first non-EOL lexem)
*/

static void		add_line_to_list(t_line *line)
{
	t_dllist	*list;

	list = ft_smalloc(sizeof(t_dllist));
	list->content = line;
	list->content_size = sizeof(t_dllist);
	ft_dllstaddend(&g_data.last_line, list);
	if (!g_data.lines)
		g_data.lines = g_data.last_line;
}

static void		add_new_line(t_dllist *lexem_item, t_lexem *lexem)
{
	t_line		*line;

	line = ft_smalloc(sizeof(t_line));
	line->first_char = lexem->first_char;
	line->line_num = lexem->line_num;
	line->first_lexem = lexem_item;
	add_line_to_list(line);
}

static int		lexem_is_eol(t_lexem *lexem)
{
	return (lexem->type == ENDLINE);
}

void			create_lines_list(void)
{
	t_dllist	*lexems;

	lexems = g_data.lexems;
	while (lexems)
	{
		while (lexems && lexem_is_eol(lexems->content))
			lexems = lexems->next;
		if (lexems)
			add_new_line(lexems, lexems->content);
		while (lexems && !lexem_is_eol(lexems->content))
			lexems = lexems->next;
	}
}
