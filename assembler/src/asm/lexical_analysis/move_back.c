/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:39:49 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/13 11:22:44 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm/asm.h"
#include "../../../inc/asm/fsm_lexical_analysis.h"

void			move_back(t_fsm *fsm)
{
	if (fsm->curr_position == fsm->begin_position)
	{
		fsm->curr_position--;
		fsm->begin_position--;
	}
	else
		fsm->curr_position--;
	fsm->curr_char_in_line_num--;
}
