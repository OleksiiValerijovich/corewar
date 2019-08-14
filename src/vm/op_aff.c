//
// Created by Oleksii KHERSONIUK on 2019-08-14.
//

#include "../../includes/vm/corewar_vm.h"

void		op_aff(t_car *c)
{
	int arg;

	arg = get_arg(REG_CODE, c->pos + 1, 0);
	if (arg > 0 && arg < 17)
		ft_printf("%c\n", c->reg[arg] % 256);
	c->pos = (c->pos + 2) % MEM_SIZE;
}
