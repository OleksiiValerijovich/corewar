/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_separator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:31:47 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/13 22:21:31 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/fsm_lexical_analysis.h"

int		is_separator(char c)
{
	if (c == SEPARATOR_CHAR)
		return (separator_char);
	return (-1);
}
