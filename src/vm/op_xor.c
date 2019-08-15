//
// Created by Oleksii KHERSONIUK on 2019-08-13.
//

#include "../../includes/vm/corewar_vm.h"

void 		op_xor(t_car *c)
{
	int 	arg[3];
	int		i;
	int		arg_size;
	int		pos;

	arg_size = 4;
	i = -1;
	ft_bzero(arg, sizeof(int) * 3);
	get_arg_type(c);
	if (g_vm->arg_type[0] && g_vm->arg_type[1] && g_vm->arg_type[2] == REG_CODE)
	{
		get_all_arg(arg, 3, c);
		f_printf(c, 3, arg);
//		ft_printf("XOR arg_0 %d, arg[1] %d, arg[2] %d\n", arg[0], arg[1], arg[2]);
		if (((g_vm->arg_type[0] != REG_CODE || (g_vm->arg_type[0] == REG_CODE &&
		(arg[0] > 0 && arg[0] < 17))) && (g_vm->arg_type[1] != REG_CODE ||
		(g_vm->arg_type[1] == REG_CODE && (arg[1] > 0 || arg[1] < 17)))) &&
		(arg[2] > 0 && arg[2] < 17))
		{
			while (++i < 2)
			{
				if (g_vm->arg_type[i] == REG_CODE)
					arg[i] = c->reg[arg[i]];
				else if (g_vm->arg_type[i] == IND_CODE)
				{
					pos = arg[i];
					while (arg_size > 0)
						arg[i] += (g_vm->map[pos++ % MEM_SIZE] << (8 * --arg_size));
				}
			}
			c->reg[arg[2]] = arg[0] ^ arg[1];
			c->carry = (c->reg[arg[2]] == 0) ? 1 : 0;
		}
	}
	step_for_not_valid_arg_types(c, 3);
}