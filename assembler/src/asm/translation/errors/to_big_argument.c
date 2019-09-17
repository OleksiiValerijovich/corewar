/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_big_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 22:15:17 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 13:09:46 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"

void		to_big_argument(t_lexem *lexem, char *src)
{
	g_data.error = 1;
	g_data.syntax_errors++;
	ft_printf("Syntax error: line %d contains too big argument [%s]\n",
	lexem->line_num, src);
}
