/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_low_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 22:15:23 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 13:09:50 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"

void		to_low_argument(t_lexem *lexem, char *src)
{
	g_data.error = 1;
	g_data.syntax_errors++;
	ft_printf("Syntax error: line %d contains too low argument [%s]\n",
	lexem->line_num, src);
}
