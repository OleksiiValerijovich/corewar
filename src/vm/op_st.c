//
// Created by Oleksii KHERSONIUK on 2019-08-11.
//

#include "../../includes/vm/corewar_vm.h"

void		op_st(t_car *c)
{
	int arg[2];
	int arg_size;
	int pos;

	arg_size = 4;
	pos = c->pos + 3;
	ft_bzero(arg, sizeof(int) * 2);
	get_arg_type(c);
	if (g_vm->arg_type[0] == REG_CODE && (g_vm->arg_type[1] == REG_CODE ||
	g_vm->arg_type[1] == IND_CODE))
	{
		get_all_arg(arg, 2, c);
		if (arg[0] > 0 && arg[0] < 17)
		{
			if (g_vm->arg_type[1] == REG_CODE && arg[1] > 0 && arg[1] < 17)
				c->reg[arg[1]] = c->reg[arg[0]];
			else if (g_vm->arg_type[1] == IND_CODE)
			{
				arg[1] = 0;
				arg_size = 2;
				while (arg_size > 0)
					arg[1] += (g_vm->map[(pos++) % MEM_SIZE] << (8 * --arg_size));
				arg[1] = (short)arg[1];
				pos = (c->pos + (arg[1] % IDX_MOD)) % MEM_SIZE;
				arg_size = 4;
				while (arg_size > 0)
				{
					g_vm->map_color[pos % MEM_SIZE] = c->bot_num;
					g_vm->map[(pos++) % MEM_SIZE] = c->reg[arg[0]] >> (8 * --arg_size);
				}
			}
			f_printf(c, 2, arg);
		}
	}
	step_for_not_valid_arg_types(c, 2);
}
