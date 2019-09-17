/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_no_name_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:30:28 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 15:38:07 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"

void		error_no_name_command(void)
{
	g_data.syntax_errors++;
	g_data.error = 1;
	ft_printf("Syntax error: no .name command\n");
}
