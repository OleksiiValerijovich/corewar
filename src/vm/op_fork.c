//
// Created by Oleksii KHERSONIUK on 2019-08-13.
//

#include "../../includes/vm/corewar_vm.h"

void 			op_fork(t_car *c)
{
	int		arg[1];
	t_car	*new;
	int 	reg_num;

//	new = g_vm->car;
	arg[0] = 0;
	arg[0] = (short)get_arg(DIR_CODE, c->pos + 1, g_op[c->op_id].dir_size);
	f_printf(c, 1, arg);
//	ft_printf("FORK arg_0 %d", arg);
	arg[0] = (arg[0] % IDX_MOD + c->pos) % MEM_SIZE;
//	ft_printf("(%d)\n", arg);
	reg_num = REG_NUMBER + 1;
	new = (t_car *)ft_memalloc(sizeof(t_car));
	new->next = g_vm->car;
	g_vm->car->prev = new;
	g_vm->car = new;
	new->num = g_vm->num_car + 1;
	new->bot_num = c->bot_num;
	new->pos = arg[0];
	new->last_live  = c->last_live;
	new->carry = c->carry;
	while (--reg_num > 0)
		new->reg[reg_num] = c->reg[reg_num];
//	while (new->next)
//		new = new->next;
//	new->next = (t_car *)ft_memalloc(sizeof(t_car));
//	new->next->prev = new;
//	new = new->next;
//	new->num = g_vm->num_car + 1;
//	new->bot_num = c->bot_num;
//	new->pos = arg;
//	new->last_live  = c->last_live;
//	new->carry = c->carry;
//	while (--reg_num > 0)
//		new->reg[reg_num] = c->reg[reg_num];
	g_vm->num_car++;
//	car_position(new);
	c->pos = (c->pos + 3) % MEM_SIZE;
//	ft_printf("forkpos in the end %d\n", c->pos);
}
