/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label_src.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 00:25:06 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 15:39:39 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/syntax_analysis.h"

char		*get_label_src(t_lexem *lexem)
{
	char	*src;

	src = NULL;
	if (lexem->type == DIRECT_LABEL)
	{
		src = ft_smalloc(lexem->len - 1);
		src[lexem->len - 2] = '\0';
		ft_memcpy(src, lexem->first_char + 2, lexem->len - 2);
	}
	else if (lexem->type == INDIRECT_LABEL)
	{
		src = ft_smalloc(lexem->len);
		src[lexem->len] = '\0';
		ft_memcpy(src, lexem->first_char + 1, lexem->len - 1);
	}
	return (src);
}
