/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_error_move_back.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:12:02 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/13 17:44:31 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/fsm_lexical_analysis.h"

void		lexical_error_move_back(t_fsm *fsm)
{
	lexical_error(fsm);
	move_back(fsm);
	set_begin_equal_to_current(fsm);
}
