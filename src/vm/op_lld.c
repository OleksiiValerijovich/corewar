//
// Created by Oleksii KHERSONIUK on 2019-08-13.
//

#include "../../includes/vm/corewar_vm.h"

void 	op_lld(t_car *c)
{
	int arg[2];
	int arg_size;
	int pos;

	ft_bzero(arg, sizeof(int) * 2);
	arg_size = 2;// or 4 if it is wright variant IMPORTANT!!!!!!!!!!!!!!!!!!!!!!!!
	get_arg_type(c);
	pos = c->pos + 2;
	if (g_vm->arg_type[1] == REG_CODE && (g_vm->arg_type[0] == DIR_CODE ||
	g_vm->arg_type[0] == IND_CODE))
	{
		get_all_arg(arg, 2, c);
		f_printf(c, 2, arg);

//		ft_printf("LLD arg_0 %d, arg[1] %d\n", arg[0], arg[1]);
		if (arg[1] < 17 && arg[1] > 0)
		{
			if (g_vm->arg_type[0] == DIR_CODE)
				c->reg[arg[1]] = arg[0];
			else if (g_vm->arg_type[0] == IND_CODE)
			{
				while (arg_size > 0)
					arg[0] += (g_vm->map[pos++ % MEM_SIZE] << (8 * --arg_size));
				arg[0] = (c->pos + arg[0]) % MEM_SIZE;
				arg_size = 4;
				while (arg_size > 0)
					c->reg[arg[1]] += (g_vm->map[arg[0]++ % MEM_SIZE] << (8 * --arg_size));
			}
			c->carry = c->reg[arg[1]] == 0 ? 1 : 0;
		}
	}
	step_for_not_valid_arg_types(c, 2);
}
