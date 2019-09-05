/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 11:18:46 by aturuk            #+#    #+#             */
/*   Updated: 2019/08/22 11:18:51 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm/corewar_vm.h"

static void	op_lld2(t_car *c, int *arg)
{
	int		arg_size;
	int		pos;

	arg_size = g_vm->flag->lld_size ? 2 : 4;
	pos = c->pos + 2;
	if (g_vm->arg_type[0] == DIR_CODE)
		c->reg[arg[1]] = arg[0];
	else if (g_vm->arg_type[0] == IND_CODE)
	{
		arg[0] = 0;
		while (arg_size > 0)
			arg[0] += (g_vm->map[(pos++) % MEM_SIZE] << (8 * --arg_size));
		arg[0] = (c->pos + arg[0]) % MEM_SIZE;
		arg_size = 4;
		c->reg[arg[1]] = 0;
		while (arg_size > 0)
			c->reg[arg[1]] += (g_vm->map[arg[0]++ % MEM_SIZE]
											<< (8 * --arg_size));
	}
	c->carry = c->reg[arg[1]] == 0 ? 1 : 0;
}

void		op_lld(t_car *c)
{
	int		arg[2];

	ft_bzero(arg, sizeof(int) * 2);
	get_arg_type(c);
	if (g_vm->arg_type[1] == REG_CODE && (g_vm->arg_type[0] == DIR_CODE ||
	g_vm->arg_type[0] == IND_CODE))
	{
		get_all_arg(arg, 2, c);
		if (arg[1] < 17 && arg[1] > 0)
		{
			g_vm->flag->i == 4 && g_vm->flag->v == 0 ? f_printf(c, 2, arg) : 0;
			op_lld2(c, arg);
		}
	}
	step_for_not_valid_arg_types(c, 2);
}
