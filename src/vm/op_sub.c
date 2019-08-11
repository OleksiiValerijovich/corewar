/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:50:07 by aturuk            #+#    #+#             */
/*   Updated: 2019/08/11 11:50:08 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm/corewar_vm.h"

void		op_sub(t_car *c)
{
	int		arg_0;
	int		arg_1;
	int		arg_2;

	arg_0 = 0;
	arg_1 = 0;
	arg_2 = 0;
	get_arg_type(c);
	if (g_vm->arg_type[0] == REG_CODE && g_vm->arg_type[1] == REG_CODE &&
		g_vm->arg_type[2] == REG_CODE)
	{
		arg_0 = (g_vm->map[(c->pos + 2) % MEM_SIZE]);
		arg_1 = (g_vm->map[(c->pos + 3) % MEM_SIZE]);
		arg_2 = (g_vm->map[(c->pos + 4) % MEM_SIZE]);
		if (arg_0 > 1 && arg_0 < 17 && arg_1 > 1 && arg_1 < 17 && arg_2 > 1 && arg_2 < 17)
		{
			c->reg[arg_2] = c->reg[arg_0] - c->reg[arg_1];
			c->carry = c->reg[arg_2] == 0 ? 1 : 0;
		}
		c->pos += 5;
	}
	else
		step_for_not_valid_arg_types(c, 2);
}
