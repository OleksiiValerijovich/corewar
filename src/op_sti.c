/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:38:41 by okherson          #+#    #+#             */
/*   Updated: 2019/08/22 10:38:42 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm/corewar_vm.h"

static void	op_sti3(t_car *c, int *arg, int arg_size, int pos)
{
	if (g_vm->flag->i == 4 && g_vm->flag->v == 0)
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
	arg[1], arg[2], arg[1] + arg[2], c->pos + ((arg[1] + arg[2]) % IDX_MOD));
	arg_size = 4;
	while (arg_size > 0)
	{
		g_vm->map_color[pos % MEM_SIZE] = c->bot_num;
		g_vm->map[(pos++) % MEM_SIZE] = c->reg[arg[0]] >> (8 * --arg_size);
	}
}

static void	op_sti2(t_car *c, int *arg, int arg_size, int i)
{
	int		pos;

	while (++i < 3)
	{
		if (g_vm->arg_type[i] == IND_CODE)
		{
			pos = arg[i];
			arg[i] = 0;
			while (arg_size > 0)
				arg[i] += (g_vm->map[pos++ % MEM_SIZE] << (8 * --arg_size));
		}
	}
	g_vm->flag->i == 4 && g_vm->flag->v == 0 ? f_printf(c, 3, arg) : 0;
	i = 0;
	while (++i < 3)
		arg[i] = g_vm->arg_type[i] == REG_CODE ? c->reg[arg[i]] : arg[i];
	pos = (c->pos + ((arg[1] + arg[2]) % IDX_MOD)) % MEM_SIZE;
	op_sti3(c, arg, arg_size, pos);
}

void		op_sti(t_car *c)
{
	int		arg[3];
	int		arg_size;

	arg_size = 4;
	ft_bzero(arg, sizeof(int) * 3);
	get_arg_type(c);
	if (g_vm->arg_type[0] == REG_CODE && g_vm->arg_type[1] && (g_vm->arg_type[2]
	== REG_CODE || g_vm->arg_type[2] == DIR_CODE))
	{
		get_all_arg(arg, 3, c);
		if ((arg[0] > 0 && arg[0] < 17) && ((g_vm->arg_type[1] != REG_CODE ||
		(g_vm->arg_type[1] == REG_CODE && arg[1] > 0 && arg[1] < 17)) &&
		(g_vm->arg_type[2] != REG_CODE || (g_vm->arg_type[2] == REG_CODE
		&& arg[2] > 0 && arg[2] < 17))))
		{
			op_sti2(c, arg, arg_size, 0);
		}
	}
	step_for_not_valid_arg_types(c, 3);
}
