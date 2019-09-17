/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_underline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:32:12 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/13 22:21:41 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/fsm_lexical_analysis.h"

int		is_underline(char c)
{
	if (c == UNDERLINE_CHAR)
		return (underline_char);
	return (-1);
}
