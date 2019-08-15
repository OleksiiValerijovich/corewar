//
// Created by Oleksii KHERSONIUK on 2019-08-13.
//

#include "../../includes/vm/corewar_vm.h"

void 			op_zjmp(t_car *c)
{
	int		arg[1];
//	ft_printf("c->pos0%d\n", c->pos);
	arg[0] = 0;

	arg[0] = (short)get_arg(DIR_CODE, c->pos + 1, g_op[c->op_id].dir_size);
//	ft_printf("ZJMP arg_0 %d\n", arg);
	f_printf(c, 1, arg);
	if (c->carry == 1)
		c->pos = (c->pos + arg[0] % IDX_MOD) % MEM_SIZE;
	else
		c->pos = (c->pos + 3) % MEM_SIZE;
//	ft_printf("arg%d, c->pos%d\n", arg, c->pos);
}
