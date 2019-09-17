/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:01:11 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/13 11:20:38 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/fsm_lexical_analysis.h"

void			eol(t_fsm *fsm)
{
	fsm->curr_char_in_line_num = 0;
	fsm->curr_line_num++;
}
