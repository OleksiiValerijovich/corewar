/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonexistent_label.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 00:35:08 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 00:49:32 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"

void		nonexistent_label(t_lexem *lexem, char *src)
{
	g_data.error = 1;
	g_data.syntax_errors++;
	ft_printf("Syntax error: line %d contains nonexistent %s [%s]\n",
	lexem->line_num, get_lexem_type_name(lexem->type), src);
}
