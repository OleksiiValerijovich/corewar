//
// Created by Oleksii KHERSONIUK on 2019-08-09.
//
#include "../../includes/vm/corewar_vm.h"

void	get_arg_type(t_car *c)
{
	ft_bzero(g_vm->arg_type, sizeof(uint8_t) * 3);
	g_vm->arg_type[0] = g_vm->map[c->pos + 1 % MEM_SIZE] >> 6 & 0x03;
	g_vm->arg_type[1] = g_vm->map[c->pos + 1 % MEM_SIZE] >> 4 & 0x03;
	g_vm->arg_type[2] = g_vm->map[c->pos + 1 % MEM_SIZE] >> 2 & 0x03;
}

void	get_op(t_car *c)
{
	c->op_id = g_vm->map[c->pos];//передаємо значення карти на якому нараз перебуває каретка
	if (c->op_id >= 0x01 && c->op_id <= 0x10)
		c->cycles_to_wait = g_op[c->op_id].wait;
	else//або цикл перевірки з пошуком валідної операції???????????????????
		c->pos = (c->pos + 1) % MEM_SIZE;
}

void 			step_for_not_valid_arg_types(t_car *c, int arg_num)
{
	int 	step;

	step = 0;
	while (--arg_num >= 0)
	{
		if (g_vm->arg_type[arg_num] == REG_CODE)
			step += 1;
		if (g_vm->arg_type[arg_num] == DIR_CODE)
			step += g_op[c->op_id].dir_size;
		if (g_vm->arg_type[arg_num] == IND_CODE)
			step += 2;
	}
	c->pos =+ step + 2;
}
