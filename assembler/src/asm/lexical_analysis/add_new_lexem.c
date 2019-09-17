/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_lexem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:40:08 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/13 11:23:56 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm/asm.h"

void			add_new_lexem(t_lexem *lexem)
{
	t_dllist	*new_item;

	new_item = ft_smalloc(sizeof(t_dllist));
	new_item->content = lexem;
	new_item->content_size = sizeof(t_lexem);
	ft_dllstaddend(&g_data.lexems, new_item);
}
