//
// Created by Oleksii KHERSONIUK on 2019-08-11.
//

#include "../../includes/vm/corewar_vm.h"

void		op_st(t_car *c)
{
	int arg[2];
	int arg_size;
	int pos;

	ft_bzero(arg, sizeof(int) * 2);
	get_arg_type(c);
	if (g_vm->arg_type[0] == REG_CODE && (g_vm->arg_type[1] == REG_CODE ||
	g_vm->arg_type[1] == IND_CODE))
	{
		arg[0] = get_arg(REG_CODE, c->pos + 2, 0);
		if (g_vm->arg_type[1] == REG_CODE)
		{
			arg[1] = get_arg(REG_CODE, c->pos + 3, 0);
			c->reg[arg[1]] = c->reg[arg[0]];
		}
		else if (g_vm->arg_type[1] == IND_CODE)
		{
			arg[1] = get_arg(IND_CODE, c->pos + 3, 2);
			arg_size = 4;
			while (arg_size > 0)
			{
				g_vm->map_color[arg[1]] = c->bot_num;
				g_vm->map[arg[1]++] = c->reg[arg[0]] >> (8 * --arg_size);
			}
		}
		c->pos = (c->pos + 7) % MEM_SIZE;
	}
	else
		step_for_not_valid_arg_types(c, 2);
}
