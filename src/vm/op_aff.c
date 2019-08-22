/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:36:31 by okherson          #+#    #+#             */
/*   Updated: 2019/08/22 10:36:32 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm/corewar_vm.h"

void		op_aff(t_car *c)
{
	int arg[1];

	ft_bzero(arg, sizeof(int) * 1);
	ft_bzero(g_vm->arg_type, sizeof(uint8_t) * 3);
	arg[0] = get_arg(c, REG_CODE, c->pos + 1, 0);
	if (arg[0] > 0 && arg[0] < 17)//if flag -a is on!!
    {
        c->pos = (c->pos + 2) % MEM_SIZE;//hz
//		ft_printf("%c\n", c->reg[arg[0]] % 256);
//	    f_printf(c, 1, arg);
    }
	else
    	c->pos = (c->pos + 4) % MEM_SIZE;//hz
}
