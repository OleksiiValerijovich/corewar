/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 22:04:34 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 13:27:57 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/syntax_analysis.h"
#include "../../../../inc/asm/translation.h"

static void		check_size_int_32(t_lexem *lexem, char *src)
{
	if (ft_longexprcmp(src, '<', INT_MIN_STR))
		to_low_argument(lexem, src);
	else if (ft_longexprcmp(src, '>', UINT_MAX_STR))
		to_big_argument(lexem, src);
}

static void		check_size_int_16(t_lexem *lexem, char *src)
{
	if (ft_longexprcmp(src, '<', SHRT_MIN_STR))
		to_low_argument(lexem, src);
	else if (ft_longexprcmp(src, '>', USHRT_MAX_STR))
		to_big_argument(lexem, src);
}

static void		check_size_int_8(t_lexem *lexem, char *src)
{
	if (ft_longexprcmp(src, '<', CHAR_MIN_STR))
		to_low_argument(lexem, src);
	else if (ft_longexprcmp(src, '>', UCHAR_MAX_STR))
		to_big_argument(lexem, src);
}

void			check_size_src(t_lexem *lexem, char *src)
{
	if (lexem->size == 1)
		check_size_int_8(lexem, src);
	else if (lexem->size == 2)
		check_size_int_16(lexem, src);
	else if (lexem->size == 4)
		check_size_int_32(lexem, src);
}
