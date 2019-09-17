/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexem_translator_reg_dir_ind.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:43:16 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 21:57:57 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/syntax_analysis.h"
#include "../../../../inc/asm/translation.h"

static void				set_functions(void (*functions[4])(t_lexem *lexem))
{
	functions[0] = registry_translator;
	functions[1] = direct_translator;
	functions[2] = indirect_translator;
	functions[3] = NULL;
}

static void				set_signals(int (*signals[4])(t_lexem *lexem))
{
	signals[0] = is_reg_not_label;
	signals[1] = is_dir_not_label;
	signals[2] = is_ind_not_label;
	signals[3] = NULL;
}

void					lexem_translator_reg_dir_ind(t_lexem *lexem)
{
	static int			(*signals[4])(t_lexem *lexem);
	static void			(*functions[4])(t_lexem *lexem);
	int					i;

	set_signals(signals);
	set_functions(functions);
	i = 0;
	while (signals[i])
	{
		if (signals[i](lexem))
		{
			functions[i](lexem);
			break ;
		}
		i++;
	}
}
