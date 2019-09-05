/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:43:01 by aturuk            #+#    #+#             */
/*   Updated: 2019/08/22 10:43:03 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm/corewar_vm.h"

void		op_aff(t_car *c)
{
	int		arg[1];

	ft_bzero(arg, sizeof(int) * 1);
	ft_bzero(g_vm->arg_type, sizeof(uint8_t) * 3);
	arg[0] = get_arg(c, REG_CODE, c->pos + 1, 0);
	if (arg[0] > 0 && arg[0] < 17)
	{
		c->pos = (c->pos + 2) % MEM_SIZE;
		if (g_vm->flag->a && g_vm->flag->v == 0)
		{
			f_printf(c, 1, arg);
			ft_printf("Aff: %d  %C\n", (c->reg[arg[0]] % 256),
			(c->reg[arg[0]] % 256));
		}
	}
	else
		c->pos = (c->pos + 4) % MEM_SIZE;
}
