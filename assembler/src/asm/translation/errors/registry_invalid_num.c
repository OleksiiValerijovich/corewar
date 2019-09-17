/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registry_invalid_num.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 01:30:07 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 01:30:42 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"

void		registry_invalid_num(t_lexem *lexem)
{
	g_data.error = 1;
	g_data.syntax_errors++;
	ft_printf("Syntax error: line %d contains invalid registry\n",
	lexem->line_num);
}
