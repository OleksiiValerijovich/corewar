/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registry_translator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:06:44 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 01:31:48 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/syntax_analysis.h"
#include "../../../../inc/asm/translation.h"

static void	check_registry(t_lexem *lexem, char *src)
{
	if (ft_longexprcmp(src, '<', "1"))
		registry_invalid_num(lexem);
	else if (ft_longexprcmp(src, '>', "99"))
		registry_invalid_num(lexem);
}

void		registry_translator(t_lexem *lexem)
{
	char	*src;

	src = ft_smalloc(lexem->len);
	src[lexem->len - 1] = '\0';
	ft_memmove(src, lexem->first_char + 1, lexem->len - 1);
	check_size_src(lexem, src);
	check_registry(lexem, src);
	lexem->translation = ft_atol(src);
	free(src);
}
