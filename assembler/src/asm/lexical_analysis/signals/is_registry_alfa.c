/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_registry_alfa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:32:10 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/13 22:21:28 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/fsm_lexical_analysis.h"

int		is_registry_alfa(char c)
{
	if (c == REGISTRY_ALPHA)
		return (reg_aplha);
	return (-1);
}
