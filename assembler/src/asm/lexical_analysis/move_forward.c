/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:39:46 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/13 11:22:35 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm/asm.h"
#include "../../../inc/asm/fsm_lexical_analysis.h"

void			move_forward(t_fsm *fsm)
{
	fsm->curr_char_in_line_num++;
	fsm->curr_position++;
}
