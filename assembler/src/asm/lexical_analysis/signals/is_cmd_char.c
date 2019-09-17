/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:31:51 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/13 22:21:03 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/fsm_lexical_analysis.h"

int		is_cmd_char(char c)
{
	if (c == CMD_CHAR)
		return (cmd_char);
	return (-1);
}
