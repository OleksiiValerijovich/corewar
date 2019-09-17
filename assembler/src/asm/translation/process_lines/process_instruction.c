/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:54:38 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 23:55:29 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/syntax_analysis.h"
#include "../../../../inc/asm/operations.h"
#include "../../../../inc/asm/translation.h"

static void				set_arg_code(_Bool (*is_arg_code)[17])
{
	(*is_arg_code)[1] = 0;
	(*is_arg_code)[2] = 1;
	(*is_arg_code)[3] = 1;
	(*is_arg_code)[4] = 1;
	(*is_arg_code)[5] = 1;
	(*is_arg_code)[6] = 1;
	(*is_arg_code)[7] = 1;
	(*is_arg_code)[8] = 1;
	(*is_arg_code)[9] = 0;
	(*is_arg_code)[10] = 1;
	(*is_arg_code)[11] = 1;
	(*is_arg_code)[12] = 0;
	(*is_arg_code)[13] = 1;
	(*is_arg_code)[14] = 1;
	(*is_arg_code)[15] = 0;
	(*is_arg_code)[16] = 1;
}

static void				set_dir_size(int (*dir_size)[17])
{
	(*dir_size)[1] = 4;
	(*dir_size)[2] = 4;
	(*dir_size)[3] = 4;
	(*dir_size)[4] = 4;
	(*dir_size)[5] = 4;
	(*dir_size)[6] = 4;
	(*dir_size)[7] = 4;
	(*dir_size)[8] = 4;
	(*dir_size)[9] = 2;
	(*dir_size)[10] = 2;
	(*dir_size)[11] = 2;
	(*dir_size)[12] = 2;
	(*dir_size)[13] = 4;
	(*dir_size)[14] = 2;
	(*dir_size)[15] = 2;
	(*dir_size)[16] = 4;
}

void					process_instruction(t_line *line)
{
	static int			dir_size[17];
	static _Bool		is_arg_code[17];
	enum e_operations	opcode;
	t_translation		translate;

	ft_bzero(&translate, sizeof(t_translation));
	if (!*dir_size)
	{
		set_dir_size(&dir_size);
		set_arg_code(&is_arg_code);
	}
	opcode = get_signal_optype(line->first_lexem->content);
	translate.is_arg_code = is_arg_code[opcode];
	translate.dir_size = dir_size[opcode];
	translator(&translate, line);
}
