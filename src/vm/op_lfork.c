//
// Created by Oleksii KHERSONIUK on 2019-08-13.
//

#include "../../includes/vm/corewar_vm.h"

void 			op_lfork(t_car *c)
{
	int		arg[1];
	t_car	*new;
	int 	reg_num;
	int     ll;

	ft_bzero(arg, sizeof(int) * 1);
	ft_bzero(g_vm->arg_type, sizeof(uint8_t) * 3);
	arg[0] = (short)get_arg(c, DIR_CODE, (c->pos + 1) % MEM_SIZE, g_op[c->op_id].dir_size);
	f_printf(c, 1, arg);
//	ft_printf("HELLO");
//	ft_printf("op_lfork    c->pos%d\n", (c->pos + arg[0]) % MEM_SIZE);
	arg[0] = (c->pos + arg[0]) % MEM_SIZE;
	reg_num = REG_NUMBER + 1;
	new = (t_car *)ft_memalloc(sizeof(t_car));
	new->next = g_vm->car;
	g_vm->car->prev = new;
	g_vm->car = new;
	new->num = ++g_vm->car_process;
	new->bot_num = c->bot_num;
	new->pos = arg[0];
	ll = c->last_live;
	new->last_live = ll;
	new->carry = c->carry;
	while (--reg_num > 0)
		new->reg[reg_num] = c->reg[reg_num];
	g_vm->num_car++;
	c->pos = (c->pos + 3) % MEM_SIZE;
}
