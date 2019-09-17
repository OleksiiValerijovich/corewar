/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lexem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:03:55 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 14:05:25 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm/asm.h"

t_lexem		*get_lexem(t_dllist *lexem_list_item)
{
	if (lexem_list_item)
		return (lexem_list_item->content);
	return (NULL);
}
