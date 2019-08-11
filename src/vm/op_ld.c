//
// Created by Oleksii KHERSONIUK on 2019-08-10.
//
#include "../../includes/vm/corewar_vm.h"

void 	op_ld(t_car *c)
{
	int arg_0;
	int arg_1;
	int arg_size;
	int pos_0;

	arg_1 = 0;
	arg_0 = 0;
	arg_size = 4;
	get_arg_type(c);
	if (g_vm->arg_type[1] == REG_CODE && (g_vm->arg_type[0] == DIR_CODE ||
	g_vm->arg_type[0] == IND_CODE))
	{
		arg_1 = (g_vm->map[(c->pos + 6) % MEM_SIZE]);
		pos_0 = c->pos + 2;
		if (g_vm->arg_type[0] == DIR_CODE)
		{
			while (arg_size > 0)
			{
				arg_0 += (g_vm->map[pos_0++ % MEM_SIZE] << (8 * --arg_size));
			}
			c->reg[arg_1] = arg_0;
		}
		else if (g_vm->arg_type[0] == IND_CODE)
		{
			while (arg_size > 0)
			{
				arg_0 += (g_vm->map[pos_0++ % MEM_SIZE] << (8 * --arg_size));
			}
			pos_0 = c->pos + (arg_0 % IDX_MOD);
			arg_size = 4;
			arg_0 = 0;
			while (arg_size > 0)
			{
				arg_0 += (g_vm->map[pos_0++ % MEM_SIZE] << (8 * --arg_size));
			}
		}
		c->carry = arg_0 == 0 ? 1 : 0;
		c->pos = (c->pos + 7) % MEM_SIZE;
	}
	else
		step_for_not_valid_arg_types(c, 2);
//	printf("arg_1-%d\n", arg_1);
}