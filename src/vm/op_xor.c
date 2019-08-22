/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:38:53 by okherson          #+#    #+#             */
/*   Updated: 2019/08/22 10:38:54 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm/corewar_vm.h"

static void	op_xor2(t_car *c, int *arg)
{
	int		arg_size;
	int		i;
	int		pos;

	i = -1;
	arg_size = 4;
	while (++i < 2)
	{
		if (g_vm->arg_type[i] == REG_CODE)
			arg[i] = c->reg[arg[i]];
		else if (g_vm->arg_type[i] == IND_CODE)
		{
			pos = arg[i];
			arg[i] = 0;
			while (arg_size > 0)
				arg[i] += (g_vm->map[pos++ % MEM_SIZE] << (8 * --arg_size));
		}
	}
	c->reg[arg[2]] = arg[0] ^ arg[1];
	c->carry = (c->reg[arg[2]] == 0) ? 1 : 0;
}

void		op_xor(t_car *c)
{
	int		arg[3];

	ft_bzero(arg, sizeof(int) * 3);
	get_arg_type(c);
	if (g_vm->arg_type[0] && g_vm->arg_type[1] && g_vm->arg_type[2] == REG_CODE)
	{
		if (g_vm->flag->i == 4)
			get_all_arg(arg, 3, c);
		if (((g_vm->arg_type[0] != REG_CODE || (g_vm->arg_type[0] == REG_CODE &&
		(arg[0] > 0 && arg[0] < 17))) && (g_vm->arg_type[1] != REG_CODE ||
		(g_vm->arg_type[1] == REG_CODE && arg[1] > 0 && arg[1] < 17))) &&
		(arg[2] > 0 && arg[2] < 17))
		{
			if (g_vm->flag->i == 4)
				f_printf(c, 3, arg);
			op_xor2(c, arg);
		}
	}
	step_for_not_valid_arg_types(c, 3);
}
