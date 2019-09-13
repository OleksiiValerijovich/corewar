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

#include "../includes/vm/corewar_vm.h"

void		op_sub(t_car *c)
{
	int		arg[3];

	ft_bzero(arg, sizeof(int) * 3);
	get_arg_type(c);
	if (g_vm->arg_type[0] == REG_CODE && g_vm->arg_type[1] == REG_CODE &&
	g_vm->arg_type[2] == REG_CODE)
	{
		get_all_arg(arg, 3, c);
		if (arg[0] > 0 && arg[0] < 17 && arg[1] > 0 && arg[1] < 17 && arg[2]
		> 0 && arg[2] < 17)
		{
			if (g_vm->flag->i == 4 && g_vm->flag->v == 0)
				f_printf(c, 3, arg);
			c->reg[arg[2]] = c->reg[arg[0]] - c->reg[arg[1]];
			c->carry = c->reg[arg[2]] == 0 ? 1 : 0;
		}
	}
	step_for_not_valid_arg_types(c, 3);
}
