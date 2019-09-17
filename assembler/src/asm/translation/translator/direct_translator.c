/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_translator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:51:18 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 02:12:05 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/syntax_analysis.h"
#include "../../../../inc/asm/translation.h"

void		direct_translator(t_lexem *lexem)
{
	char	*src;

	src = ft_smalloc(lexem->len);
	src[lexem->len - 1] = '\0';
	ft_memmove(src, lexem->first_char + 1, lexem->len - 1);
	check_size_src(lexem, src);
	lexem->translation = ft_atol(src);
	free(src);
}
