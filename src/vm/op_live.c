/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:37:57 by okherson          #+#    #+#             */
/*   Updated: 2019/08/22 10:37:58 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm/corewar_vm.h"

void		op_live(t_car *c)
{
	int arg[1];

    g_vm->live_for_check++;
	ft_bzero(arg, sizeof(int) * 1);
	ft_bzero(g_vm->arg_type, sizeof(uint8_t) * 3);
	c->last_live = g_vm->cycles_total;
	arg[0] = get_arg(c, DIR_CODE, c->pos + 1, g_op[c->op_id].dir_size);
	f_printf(c, 1, arg);
	if (arg[0] < 0 && arg[0] >= -g_vm->num_bot)
		g_vm->last_say_live = -arg[0];
	c->pos = (c->pos + 5) % MEM_SIZE;
//	if (c->num == 23)
//    	ft_printf("c->pos:%d, c_op_id:%d\n", c->pos, g_vm->map[c->pos]);
}
