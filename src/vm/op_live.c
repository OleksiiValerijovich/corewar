//
// Created by Oleksii KHERSONIUK on 2019-08-08.
//

#include "../../includes/vm/corewar_vm.h"

void		op_live(t_car *c)
{
	int arg;
	int arg_size;
	int pos;

	arg = 0;
	c->last_live = g_vm->cycles_total;
	arg_size = g_op[c->op_id].dir_size;
	pos = c->pos + 1;
	while (arg_size > 0)
	{
		arg += (g_vm->map[pos++ % MEM_SIZE] << (8 * --arg_size));
	}
	if (arg > 0 && arg < g_vm->num_bot)
		g_vm->last_say_live = arg;
	c->pos = (c->pos + 5) % MEM_SIZE;
//	get_op(c);
}
