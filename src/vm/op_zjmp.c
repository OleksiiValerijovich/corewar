//
// Created by Oleksii KHERSONIUK on 2019-08-13.
//

#include "../../includes/vm/corewar_vm.h"

void 			op_zjmp(t_car *c)
{
	int		arg;

	arg = (short)get_arg(DIR_CODE, c->pos + 1, g_op[c->op_id].dir_size)
	if (c->carry == 1)
		c->pos = (c->pos + arg % IDX_MOD) % MEM_SIZE;
	else
		c->pos = (c->pos + 3) % MEM_SIZE;
}
