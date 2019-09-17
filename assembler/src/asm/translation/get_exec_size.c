/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exec_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 00:00:59 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 02:05:21 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm/asm.h"

static void		add_size(t_line *line)
{
	g_data.exec_size = g_data.exec_size + line->size;
}

void			get_exec_size(void)
{
	t_dllist	*lines;

	lines = g_data.lines;
	while (lines)
	{
		add_size(lines->content);
		lines = lines->next;
	}
}
