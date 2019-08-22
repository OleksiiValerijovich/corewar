/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:36:53 by okherson          #+#    #+#             */
/*   Updated: 2019/08/22 10:36:54 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm/corewar_vm.h"

void		op_fork(t_car *c)
{
	int		arg[1];
	t_car	*new;
	int		reg_num;

	ft_bzero(arg, sizeof(int) * 1);
	ft_bzero(g_vm->arg_type, sizeof(uint8_t) * 3);
	arg[0] = (short)get_arg(c, DIR_CODE, c->pos + 1, g_op[c->op_id].dir_size);
	f_printf(c, 1, arg);
	arg[0] = (arg[0] % IDX_MOD + c->pos) % MEM_SIZE;
	reg_num = REG_NUMBER + 1;
	new = (t_car *)ft_memalloc(sizeof(t_car));
	new->next = g_vm->car;
	g_vm->car->prev = new;
	g_vm->car = new;
	new->num = ++g_vm->car_process;
	new->bot_num = c->bot_num;
	new->pos = arg[0];
	new->last_live = c->last_live;
	new->carry = c->carry;
	while (--reg_num > 0)
		new->reg[reg_num] = c->reg[reg_num];
	g_vm->num_car++;
	c->pos = (c->pos + 3) % MEM_SIZE;
}
