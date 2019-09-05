/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:39:01 by okherson          #+#    #+#             */
/*   Updated: 2019/08/22 10:39:04 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm/corewar_vm.h"

void	op_zjmp(t_car *c)
{
	int	arg[1];

	ft_bzero(arg, sizeof(int) * 1);
	ft_bzero(g_vm->arg_type, sizeof(uint8_t) * 3);
	arg[0] = (short)get_arg(c, DIR_CODE, c->pos + 1, g_op[c->op_id].dir_size);
	if (g_vm->flag->i == 4 && g_vm->flag->v == 0)
		f_printf(c, 1, arg);
	if (c->carry == 1)
		c->pos = (c->pos + arg[0] % IDX_MOD) % MEM_SIZE;
	else
		c->pos = (c->pos + 3) % MEM_SIZE;
}
