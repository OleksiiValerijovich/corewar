/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 11:16:59 by aturuk            #+#    #+#             */
/*   Updated: 2019/08/22 11:17:00 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm/corewar_vm.h"

void		op_live(t_car *c)
{
	int		arg[1];

	g_vm->live_for_check++;
	ft_bzero(arg, sizeof(int) * 1);
	ft_bzero(g_vm->arg_type, sizeof(uint8_t) * 3);
	c->last_live = g_vm->cycles_total;
	arg[0] = get_arg(c, DIR_CODE, c->pos + 1, g_op[c->op_id].dir_size);
	g_vm->flag->i == 4 && g_vm->flag->v == 0 ? f_printf(c, 1, arg) : 0;
	if (arg[0] < 0 && arg[0] >= -g_vm->num_bot)
	{
		g_vm->last_say_live = -arg[0];
		if (g_vm->flag->i == -1)
		{
			g_vm->flag->v == 0 ?
			ft_printf("A process shows that player %d (%s) is alive\n",
			g_vm->last_say_live, g_vm->bot[g_vm->last_say_live - 1].name) : 0;
		}
	}
	c->pos = (c->pos + 5) % MEM_SIZE;
}
