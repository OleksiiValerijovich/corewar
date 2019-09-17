/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:32:02 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/13 22:21:12 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/fsm_lexical_analysis.h"

int		is_dir_char(char c)
{
	if (c == DIRECT_CHAR)
		return (direct_char);
	return (-1);
}
