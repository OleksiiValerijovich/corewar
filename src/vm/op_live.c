//
// Created by Oleksii KHERSONIUK on 2019-08-08.
//

#include "../../includes/vm/corewar_vm.h"

void		op_live(t_car *c)
{
	int arg[1];

	arg[0] = 0;
	c->last_live = g_vm->cycles_total;
	arg[0] = get_arg(DIR_CODE, c->pos + 1, g_op[c->op_id].dir_size);
//	ft_printf("LIVE arg_0 %d\n", arg);
	f_printf(c, 1, arg);

	if (arg[0] > 0 && arg[0] <= g_vm->num_bot)
		g_vm->last_say_live = arg[0];
	c->pos = (c->pos + 5) % MEM_SIZE;
}
