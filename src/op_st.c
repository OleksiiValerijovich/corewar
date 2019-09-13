/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:38:27 by okherson          #+#    #+#             */
/*   Updated: 2019/08/22 10:38:28 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm/corewar_vm.h"

static int	op_st2(t_car *c, int *arg, int arg_size, int pos)
{
	if (g_vm->arg_type[1] == REG_CODE && arg[1] > 0 && arg[1] < 17)
		c->reg[arg[1]] = c->reg[arg[0]];
	else if (g_vm->arg_type[1] == IND_CODE)
	{
		arg[1] = 0;
		arg_size = 2;
		while (arg_size > 0)
			arg[1] += (g_vm->map[(pos++) % MEM_SIZE] << (8 * --arg_size));
		arg[1] = (short)arg[1];
		pos = (c->pos + (arg[1] % IDX_MOD)) % MEM_SIZE;
		arg_size = 4;
		while (arg_size > 0)
		{
			g_vm->map_color[pos % MEM_SIZE] = c->bot_num;
			g_vm->map[(pos++) % MEM_SIZE] = c->reg[arg[0]] >> (8 * --arg_size);
		}
	}
	else
		return (1);
	return (0);
}

void		op_st(t_car *c)
{
	int arg[2];
	int arg_size;
	int pos;

	arg_size = 4;
	pos = c->pos + 3;
	ft_bzero(arg, sizeof(int) * 2);
	get_arg_type(c);
	if (g_vm->arg_type[0] == REG_CODE && (g_vm->arg_type[1] == REG_CODE ||
	g_vm->arg_type[1] == IND_CODE))
	{
		get_all_arg(arg, 2, c);
		if (arg[0] > 0 && arg[0] < 17)
		{
			if (op_st2(c, arg, arg_size, pos) == 0 && g_vm->flag->i == 4
			&& g_vm->flag->v == 0)
				f_printf(c, 2, arg);
		}
	}
	step_for_not_valid_arg_types(c, 2);
}
