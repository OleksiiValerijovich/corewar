//
// Created by Oleksii KHERSONIUK on 2019-08-14.
//

#include "../../includes/vm/corewar_vm.h"

void		op_aff(t_car *c)
{
	int arg[1];

	ft_bzero(arg, sizeof(int) * 1);
	ft_bzero(g_vm->arg_type, sizeof(uint8_t) * 3);
	arg[0] = get_arg(REG_CODE, c->pos + 1, 0);
	f_printf(c, 1, arg);
//	if (arg[0] > 0 && arg < 17)//if flag -a is on!!
//		ft_printf("%c\n", c->reg[arg[0]] % 256);
	c->pos = (c->pos + 2) % MEM_SIZE;
}
