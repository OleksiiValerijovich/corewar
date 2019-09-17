/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 23:08:34 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 15:25:35 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm/asm.h"
#include "../../../inc/asm/syntax_analysis.h"

static void		print_lexem_(t_lexem *lexem)
{
	if (*lexem->first_char != '\n')
		ft_printf("[%{red}y%:*s%{normal}y]; ",
		lexem->len, lexem->first_char);
	ft_printf("type %{green}y%s%{normal}y; ", get_lexem_type_name(lexem->type));
	if (is_reg_dir_ind(lexem) || is_operation(lexem))
	{
		ft_printf("size %{green}y%zu%{normal}y; ", lexem->size);
		if (lexem->size == 1)
			ft_printf("translation %{green}y%hh#x%{normal}y; ",
			lexem->translation);
		else if (lexem->size == 2)
			ft_printf("translation %{green}y%h#x%{normal}y; ",
			lexem->translation);
		else if (lexem->size == 4)
			ft_printf("translation %{green}y%#x%{normal}y; ",
			lexem->translation);
	}
	ft_putchar('\n');
}

static void		print_lexems_(t_dllist *lexems)
{
	while (!is_endline(get_lexem(lexems)))
	{
		print_lexem_(lexems->content);
		lexems = lexems->next;
	}
}

static void		print_line(char *src)
{
	char	*n;

	n = ft_strchr(src, '\n');
	if (n)
	{
		ft_printf("%:*s%{normal}y\n", n - src, src);
	}
}

void			print_lines(t_dllist *lines)
{
	t_line		*line;

	while (lines)
	{
		line = lines->content;
		ft_printf("%{WHITE, black}y%d: ", line->line_num);
		print_line(line->first_char);
		if (line->label_first_char && is_operation(line->first_lexem->content))
			print_lexem_(get_lexem(line->first_lexem->prev));
		print_lexems_(line->first_lexem);
		if (line->is_args_code)
			ft_printf("args_code %{green}y%#x%{normal}y; \
size %{green}y%d%{normal}y;\n", line->args_code, 1);
		if (line->size)
			ft_printf("instruction_size %{green}y%x%{normal}y;\n", line->size);
		lines = lines->next;
		if (lines)
			ft_putchar('\n');
	}
}
