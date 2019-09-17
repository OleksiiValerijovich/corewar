/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lexem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:17:28 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 15:45:50 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm/asm.h"

t_lexem					*get_next_lexem(t_dllist **lexems)
{
	t_lexem				*lexem;

	if (*lexems)
	{
		lexem = (*lexems)->content;
		*lexems = (*lexems)->next;
		return (lexem);
	}
	return (NULL);
}
