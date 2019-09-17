/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:27:42 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 03:40:43 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/translation.h"

static void			save_comment(t_lexem *lexem)
{
	g_data.comment = ft_memalloc(lexem->len + 1);
	ft_memmove(g_data.comment, lexem->first_char, lexem->len);
	g_data.comment[lexem->len] = '\0';
}

static void			save_name(t_lexem *lexem)
{
	g_data.champ_name = ft_memalloc(lexem->len + 1);
	ft_memmove(g_data.champ_name, lexem->first_char, lexem->len);
	g_data.champ_name[lexem->len] = '\0';
}

static void			process_command_(t_dllist *lexems, t_line *line)
{
	t_lexem		*lexem;

	lexem = get_next_lexem(&lexems);
	if (!ft_memcmp(lexem->first_char, ".name", lexem->len) &&
		!g_data.champ_name)
	{
		save_name(get_next_lexem(&lexems));
	}
	else if (!ft_memcmp(lexem->first_char, ".comment", lexem->len) &&
			!g_data.comment)
		save_comment(get_next_lexem(&lexems));
	else
		error_unsupported_command(line);
}

void				process_command(t_line *line)
{
	t_dllist		*lexems;

	lexems = line->first_lexem;
	process_command_(lexems, line);
}
