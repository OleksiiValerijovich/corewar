//
// Created by Oleksii KHERSONIUK on 2019-08-11.
//

#include "../../includes/vm/corewar_vm.h"

void		op_st(t_car *c)
{
	int arg_0;
	int arg_1;
	int arg_size;
	int pos_0;

	arg_1 = 0;
	arg_0 = 0;
	arg_size = 2;
	pos_0 = c->pos + 3;
	get_arg_type(c);
	if (g_vm->arg_type[0] == REG_CODE && (g_vm->arg_type[1] == REG_CODE ||
	g_vm->arg_type[1] == IND_CODE))
	{
		arg_0 = (g_vm->map[(c->pos + 2) % MEM_SIZE]);
		if (g_vm->arg_type[1] == REG_CODE)
		{
			arg_1 = (g_vm->map[(c->pos + 3) % MEM_SIZE]);
			c->reg[arg_1] = c->reg[arg_0];
		}
		else if (g_vm->arg_type[1] == IND_CODE)
		{
			while (arg_size > 0)
			{
				arg_1 += (g_vm->map[pos_0++ % MEM_SIZE] << (8 * --arg_size));
			}
			pos_0 = c->pos + arg_1 % IDX_MOD;
			arg_size = 4;
			while (arg_size > 0)
			{
				g_vm->map[pos_0++] = c->reg[arg_0] >> (8 * --arg_size);
			}
		}
		c->pos = (c->pos + 7) % MEM_SIZE;
	}
	else
		step_for_not_valid_arg_types(c, 2);
}