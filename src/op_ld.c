/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:57:07 by aturuk            #+#    #+#             */
/*   Updated: 2019/08/22 10:57:08 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm/corewar_vm.h"

static void	op_ld2(t_car *c, int *arg)
{
	int		pos;
	int		arg_size;

	pos = c->pos + 2;
	arg_size = 4;
	if (arg[1] < 17 && arg[1] > 0)
	{
		if (g_vm->arg_type[0] == DIR_CODE)
			c->reg[arg[1]] = arg[0];
		else if (g_vm->arg_type[0] == IND_CODE)
		{
			c->reg[arg[1]] = 0;
			while (arg_size > 0)
				c->reg[arg[1]] += (g_vm->map[arg[0]++ % MEM_SIZE]
										<< (8 * --arg_size));
			arg[0] = c->reg[arg[1]];
		}
		c->carry = c->reg[arg[1]] == 0 ? 1 : 0;
		g_vm->flag->i == 4 && g_vm->flag->v == 0 ? f_printf(c, 2, arg) : 0;
	}
}

void		op_ld(t_car *c)
{
	int		arg[2];

	ft_bzero(arg, sizeof(int) * 2);
	get_arg_type(c);
	if (g_vm->arg_type[1] == REG_CODE && (g_vm->arg_type[0] == DIR_CODE ||
	g_vm->arg_type[0] == IND_CODE))
	{
		get_all_arg(arg, 2, c);
		op_ld2(c, arg);
	}
	step_for_not_valid_arg_types(c, 2);
}
