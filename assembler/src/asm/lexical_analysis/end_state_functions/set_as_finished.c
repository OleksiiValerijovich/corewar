/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_as_finished.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:26:45 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/13 11:20:50 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/fsm_lexical_analysis.h"

void		set_as_finished(t_fsm *fsm)
{
	fsm->finished = 1;
}
