//
// Created by Oleksii KHERSONIUK on 2019-08-13.
//

#include "../../includes/vm/corewar_vm.h"

void 		op_sti(t_car *c)
{
	int		arg[3];
	int		i;
	int		arg_size;
	int		pos;

    arg_size = 4;
	i = -1;
	ft_bzero(arg, sizeof(int) * 3);
	get_arg_type(c);
    if (g_vm->arg_type[0] == REG_CODE && g_vm->arg_type[1] && (g_vm->arg_type[2]
	== REG_CODE || g_vm->arg_type[2] == DIR_CODE))
	{
		get_all_arg(arg, 3, c);
        if ((arg[0] > 0 && arg[0] < 17) && ((g_vm->arg_type[1] != REG_CODE || (g_vm->arg_type[1] == REG_CODE &&
		arg[1] > 0 && arg[1] < 17)) && (g_vm->arg_type[2] != REG_CODE ||
		(g_vm->arg_type[2] == REG_CODE && arg[2] > 0 && arg[2] < 17))))
		{
            f_printf(c, 3, arg);
			while (++i < 3)
			{
				if (g_vm->arg_type[i] == REG_CODE)
					arg[i] = c->reg[arg[i]];
				else if (g_vm->arg_type[i] == IND_CODE)
				{
					pos = arg[i];
					arg[i] = 0;
					while (arg_size > 0)
						arg[i] += (g_vm->map[pos++ % MEM_SIZE] << (8 * --arg_size));
				}
			}
            pos = (c->pos + ((arg[1] + arg[2]) % IDX_MOD)) % MEM_SIZE;
			ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
			arg[1], arg[2], arg[1] + arg[2], c->pos + ((arg[1] + arg[2]) % IDX_MOD));
			arg_size = 4;
			while (arg_size > 0)
			{
				g_vm->map_color[pos % MEM_SIZE] = c->bot_num;
				g_vm->map[(pos++) % MEM_SIZE] = arg[0] >> (8 * --arg_size);
			}

        }
	}
    step_for_not_valid_arg_types(c, 3);
}
