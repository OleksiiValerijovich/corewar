/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:46:40 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/14 19:37:56 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm/asm.h"

void	display_error_count(void)
{
	if (g_data.lexical_errors)
		ft_printf("Total lexical errors: %zu\n", g_data.lexical_errors);
	if (g_data.syntax_errors)
		ft_printf("Total syntax errors: %zu\n", g_data.syntax_errors);
}
