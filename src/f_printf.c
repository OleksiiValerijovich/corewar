/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:03:25 by aturuk            #+#    #+#             */
/*   Updated: 2019/08/23 11:03:27 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm/corewar_vm.h"

void	f_printf2(t_car *c, int *arg)
{
	c->op_id == 12 ? ft_printf(" (%d)", (arg[0] % IDX_MOD + c->pos) % MEM_SIZE)
	: 0;
	c->op_id == 15 ? ft_printf(" (%d)", (arg[0] + c->pos)) : 0;
	if (c->op_id == 9)
		c->carry == 1 ? ft_printf(" OK") : ft_printf(" FAILED");
	ft_printf("\n");
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
	f_printf2(c, arg);
}
