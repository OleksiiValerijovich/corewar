/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:12:02 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/13 11:20:47 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/fsm_lexical_analysis.h"

void		lexical_error(t_fsm *fsm)
{
	fsm->errors++;
	ft_printf("Lexical error at: %d:%d\n",
	fsm->curr_line_num, fsm->curr_char_in_line_num);
	set_begin_equal_to_current(fsm);
}
