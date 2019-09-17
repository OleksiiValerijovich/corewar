/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:33:17 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 00:16:17 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm/asm.h"
#include "../../../inc/asm/translation.h"

static void		final_check(void)
{
	if (!g_data.champ_name)
		error_no_name_command();
	if (!g_data.champ_name)
		error_no_comment_command();
}

void			translation(void)
{
	create_lines_list();
	process_lines();
	translate_labels();
	get_exec_size();
	final_check();
}
