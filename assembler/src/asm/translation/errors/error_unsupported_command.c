/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_unsupported_command.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:56:09 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 15:37:05 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"

void		error_unsupported_command(t_line *line)
{
	g_data.syntax_errors++;
	g_data.error = 1;
	ft_printf("Syntax error: line %d contains unsupported command\n",
	line->line_num);
}
