/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indirect_translator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:06:40 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 22:26:37 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/syntax_analysis.h"
#include "../../../../inc/asm/translation.h"

void	indirect_translator(t_lexem *lexem)
{
	char	*src;

	src = ft_smalloc(lexem->len + 1);
	src[lexem->len] = '\0';
	ft_memmove(src, lexem->first_char, lexem->len);
	check_size_src(lexem, src);
	lexem->translation = ft_atol(src);
	free(src);
}
