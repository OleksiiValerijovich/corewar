/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_no_comment_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:30:26 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 15:38:48 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"

void		error_no_comment_command(void)
{
	g_data.syntax_errors++;
	g_data.error = 1;
	ft_printf("Syntax error: no .comment command\n");
}
