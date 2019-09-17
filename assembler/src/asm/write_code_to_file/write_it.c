/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 02:37:20 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 03:39:37 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../../inc/asm/asm.h"
#include "../../../inc/asm/syntax_analysis.h"
#include "../../../inc/asm/write_code_to_file.h"

static void		writecode_line(t_line *line, t_file_data *file_data)
{
	t_dllist	*lexems;

	lexems = line->first_lexem;
	if (is_operation(get_lexem(lexems)))
		write_big_endian(file_data->fd, &get_lexem(lexems)->translation,
		get_lexem(lexems)->size);
	if (line->is_args_code)
		write_big_endian(file_data->fd, &line->args_code, 1);
	lexems = lexems->next;
	while (!is_endline(get_lexem(lexems)))
	{
		if (is_reg_dir_ind(get_lexem(lexems)))
		{
			write_big_endian(file_data->fd, &get_lexem(lexems)->translation,
			get_lexem(lexems)->size);
		}
		lexems = lexems->next;
	}
}

static void		writecode(t_dllist *lines, t_file_data *file_data)
{
	while (lines)
	{
		writecode_line(lines->content, file_data);
		lines = lines->next;
	}
}

static void		writehead(t_file_data *file_data)
{
	write_big_endian(file_data->fd, &file_data->magic, 4);
	write(file_data->fd, file_data->prog_name, PROG_NAME_LENGTH);
	write(file_data->fd, "\0\0\0\0", 4);
	write_big_endian(file_data->fd, &file_data->prog_size, 4);
	write(file_data->fd, file_data->comment, COMMENT_LENGTH);
	write(file_data->fd, "\0\0\0\0", 4);
}

void			write_it(t_file_data *file_data)
{
	ft_printf("Writing data to file %s\n", file_data->filename);
	writehead(file_data);
	writecode(g_data.lines, file_data);
}
