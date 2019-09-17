/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_next_eol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 10:01:58 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 10:03:29 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm/asm.h"
#include "../../../inc/asm/syntax_analysis.h"

void		go_to_next_eol(t_fsm_syn *fsm_syn)
{
	while (fsm_syn->lexems && !is_endline(fsm_syn->lexems->content))
		fsm_syn->lexems = fsm_syn->lexems->next;
}
