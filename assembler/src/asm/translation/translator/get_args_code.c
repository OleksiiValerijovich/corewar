/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_code.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 22:52:53 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 23:55:44 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/syntax_analysis.h"
#include "../../../../inc/asm/translation.h"

void		update_args_code(t_translation *translate, u_int8_t arg_code, int i)
{
	if (i == 0)
		translate->args_code = translate->args_code | ((unsigned)arg_code << 6);
	else if (i == 1)
		translate->args_code = translate->args_code | ((unsigned)arg_code << 4);
	else if (i == 2)
		translate->args_code = translate->args_code | ((unsigned)arg_code << 2);
}
