//
// Created by Oleksii KHERSONIUK on 2019-08-08.
//

#include "../../includes/vm/corewar_vm.h"

void		op_live(t_car *c)
{
	int arg[1];
//	int     cycle_tot;
//	int     prev;           //delll

//    cycle_tot = g_vm->cycles_total;
    g_vm->live_for_check++;
	ft_bzero(arg, sizeof(int) * 1);
	ft_bzero(g_vm->arg_type, sizeof(uint8_t) * 3);
//	prev = c->last_live;
	c->last_live = g_vm->cycles_total;
//	ft_printf("op_live    car:%d, last live:%d, new_live:%d, cycle tot%d\n", c->num, prev, c->last_live, g_vm->cycles_total);
	arg[0] = get_arg(DIR_CODE, c->pos + 1, g_op[c->op_id].dir_size);
	f_printf(c, 1, arg);
	if (arg[0] < 0 && arg[0] >= -g_vm->num_bot)
		g_vm->last_say_live = -arg[0];
	c->pos = (c->pos + 5) % MEM_SIZE;
}
