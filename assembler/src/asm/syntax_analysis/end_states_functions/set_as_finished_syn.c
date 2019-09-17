/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_as_finished_syn.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:09:01 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 18:11:00 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/syntax_analysis.h"

void		set_as_finished_syn(t_fsm_syn *fsm_syn)
{
	fsm_syn->finished = 1;
}
