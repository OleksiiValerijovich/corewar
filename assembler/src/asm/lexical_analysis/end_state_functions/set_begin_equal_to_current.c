/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_begin_equal_to_current.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:40:58 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/13 11:20:54 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/fsm_lexical_analysis.h"

void		set_begin_equal_to_current(t_fsm *fsm)
{
	fsm->begin_position = fsm->curr_position;
}
