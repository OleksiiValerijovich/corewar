/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string_lens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 03:16:08 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 14:46:58 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm/asm.h"
#include "../../../inc/asm/syntax_analysis.h"
#include "../../../inc/asm/write_code_to_file.h"

static void	too_big_lenght_string(void)
{
	g_data.error = 1;
	g_data.syntax_errors++;
	ft_printf("String .name or .comment has too big lenght\n");
}

void		check_string_lens(void)
{
	if (ft_strlen(g_data.champ_name) - 2 > PROG_NAME_LENGTH)
		too_big_lenght_string();
	if (ft_strlen(g_data.comment) - 2 > COMMENT_LENGTH)
		too_big_lenght_string();
}
