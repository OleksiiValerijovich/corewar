/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_functions_help.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:37:08 by okherson          #+#    #+#             */
/*   Updated: 2019/08/22 10:37:09 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm/corewar_vm.h"

void	get_op(t_car *c)
{
	c->op_id = g_vm->map[c->pos % MEM_SIZE];
	if (c->op_id >= 0x01 && c->op_id <= 0x10)
		c->cycles_to_wait = g_op[c->op_id].wait - 1;
	else
		c->pos = (c->pos + 1) % MEM_SIZE;
}

void	get_arg_type(t_car *c)
{
	ft_bzero(g_vm->arg_type, sizeof(uint8_t) * 3);
	g_vm->arg_type[0] = g_vm->map[(c->pos + 1) % MEM_SIZE] >> 6 & 0x03;
	g_vm->arg_type[1] = g_vm->map[(c->pos + 1) % MEM_SIZE] >> 4 & 0x03;
	g_vm->arg_type[2] = g_vm->map[(c->pos + 1) % MEM_SIZE] >> 2 & 0x03;
}

int		get_arg(t_car *c, int type_code, int pos, int arg_size)
{
	int	arg;
	int	i;

	arg = 0;
	i = arg_size;
	if (type_code == REG_CODE)
		arg = (g_vm->map[pos % MEM_SIZE]);
	else if (type_code == DIR_CODE)
	{
        while (arg_size > 0)
            arg += (g_vm->map[(pos++) % MEM_SIZE] << (8 * --arg_size));
        if (i == 2)
            arg = (short)arg;
    }
	else if (type_code == IND_CODE)
	{
		while (arg_size > 0)
			arg += (g_vm->map[(pos++) % MEM_SIZE] << (8 * --arg_size));
		arg = (short)arg;
		arg = (c->pos + (arg % IDX_MOD)) % MEM_SIZE;
	}
	return (arg);
}

void	step_for_not_valid_arg_types(t_car *c, int arg_num)
{
	int	step;

	step = 0;
	while (--arg_num >= 0)
	{
		if (g_vm->arg_type[arg_num] == REG_CODE)
			step += 1;
		if (g_vm->arg_type[arg_num] == DIR_CODE)
			step += g_op[c->op_id].dir_size;
		if (g_vm->arg_type[arg_num] == IND_CODE)
			step += 2;
	}
	c->pos = (c->pos + step + 2) % MEM_SIZE;
}

void	get_all_arg(int *arg, int num_arg, t_car *c)
{
	int step;
	int a;

	step = 2;
	a = -1;
	while (++a < num_arg)
	{
		if (g_vm->arg_type[a] == REG_CODE)
		{
			arg[a] = get_arg(c, REG_CODE, (c->pos + step) % MEM_SIZE, 0);
			step += 1;
		}
		if (g_vm->arg_type[a] == DIR_CODE)
		{
			arg[a] = (g_op[c->op_id].dir_size == 2) ?
			(short)get_arg(c, DIR_CODE, (c->pos + step) % MEM_SIZE, g_op[c->op_id].dir_size) :
			get_arg(c, DIR_CODE, (c->pos + step) % MEM_SIZE, g_op[c->op_id].dir_size);
			step += g_op[c->op_id].dir_size;
		}
		if (g_vm->arg_type[a] == IND_CODE)
		{
			arg[a] = get_arg(c, IND_CODE, (c->pos + step) % MEM_SIZE, 2);
			step += 2;
		}
	}
}

void	f_printf(t_car *c, int n_arg, int *arg)
{
	int i;

	i = -1;
	ft_printf("P %4d | %s ", c->num, g_op[c->op_id].name);
	while (++i < n_arg)
	{
		if (g_vm->arg_type[i] == REG_CODE)
		{
			if (g_op[c->op_id].args_types[i] == T_REG &&
			g_op[c->op_id].args_types[i] != T_DIR &&
			g_op[c->op_id].args_types[i] != T_IND)
				ft_printf("r%d", arg[i]);
			else
			    c->op_id == 3 ? ft_printf("%d", arg[i]) :
			    ft_printf("%d", c->reg[arg[i]]);
		}
		else
			ft_printf("%d", arg[i]);
		i + 1 != n_arg ? ft_printf(" ") : 0;
	}
	c->op_id == 12 ? ft_printf(" (%d)",
	        (arg[0] + c->pos)) : 0;
    c->op_id == 15 ? ft_printf(" (%d)", (arg[0] + c->pos)) : 0;
	if (c->op_id == 9)
		c->carry == 1 ? ft_printf(" OK") : ft_printf(" FAILED");
	ft_printf("\n");
}
