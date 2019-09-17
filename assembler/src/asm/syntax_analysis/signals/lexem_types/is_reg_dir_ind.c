/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_reg_dir_ind.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:39:41 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/14 14:35:51 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/asm/asm.h"
#include "../../../../../inc/asm/syntax_analysis.h"

int		is_reg_dir_ind(t_lexem *lexem)
{
	return (is_reg(lexem) || is_dir(lexem) || is_ind(lexem));
}
