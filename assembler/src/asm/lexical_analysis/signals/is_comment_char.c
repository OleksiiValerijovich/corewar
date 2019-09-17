/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_comment_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:31:58 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/13 22:21:05 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/fsm_lexical_analysis.h"

int		is_comment_char(char c)
{
	if (c == COMMENT_CHAR || c == COMMENT_CHAR_ALT)
		return (comment_char);
	return (-1);
}
