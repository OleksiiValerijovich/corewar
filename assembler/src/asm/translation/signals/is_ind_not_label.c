/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ind_not_label.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:57:48 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 21:02:12 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/translation.h"
#include "../../../../inc/asm/operations.h"

int		is_ind_not_label(t_lexem *lexem)
{
	return (lexem->type == INDIRECT);
}
