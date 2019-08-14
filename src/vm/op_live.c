//
// Created by Oleksii KHERSONIUK on 2019-08-08.
//

#include "../../includes/vm/corewar_vm.h"

void		op_live(t_car *c)
{
	int arg;

	c->last_live = g_vm->cycles_total;
	arg = get_arg(DIR_CODE, c->pos + 1, g_op[c->op_id].dir_size);
	if (arg > 0 && arg <= g_vm->num_bot)
		g_vm->last_say_live = arg;
	c->pos = (c->pos + 5) % MEM_SIZE;
}
