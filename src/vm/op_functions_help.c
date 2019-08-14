//
// Created by Oleksii KHERSONIUK on 2019-08-09.
//
#include "../../includes/vm/corewar_vm.h"

void	get_op(t_car *c)
{
	c->op_id = g_vm->map[c->pos];//передаємо значення карти на якому нараз перебуває каретка
	if (c->op_id >= 0x01 && c->op_id <= 0x10)
	{
		c->cycles_to_wait = g_op[c->op_id].wait - 1;
//		ft_printf("cycle_get_op%d on tot cycle %d\n", c->cycles_to_wait, g_vm->cycles_total);

	}
	else if (c->op_id < 0x01 || c->op_id > 0x10)//або цикл перевірки з пошуком валідної операції???????????????????
	{
		c->pos = (c->pos + 1) % MEM_SIZE;
		get_op(c);
	}
}

void	get_arg_type(t_car *c)
{
	ft_bzero(g_vm->arg_type, sizeof(uint8_t) * 3);
	g_vm->arg_type[0] = g_vm->map[c->pos + 1 % MEM_SIZE] >> 6 & 0x03;
	g_vm->arg_type[1] = g_vm->map[c->pos + 1 % MEM_SIZE] >> 4 & 0x03;
	g_vm->arg_type[2] = g_vm->map[c->pos + 1 % MEM_SIZE] >> 2 & 0x03;
}

int 	get_arg(int type_code, int pos, int arg_size)
{
	int arg;
	int step;

	arg = 0;
	step = 0;
	if (type_code == REG_CODE)
		arg = (g_vm->map[pos % MEM_SIZE]);
	else if (type_code == DIR_CODE)
	{
		while (arg_size > 0)
			arg += (g_vm->map[pos++ % MEM_SIZE] << (8 * --arg_size));
	}
	else if (type_code == IND_CODE)
	{
		while (arg_size > 0)
			arg += (g_vm->map[pos++ % MEM_SIZE] << (8 * --arg_size));
		arg = (pos + (arg % IDX_MOD)) % MEM_SIZE;
	}
	return (arg);
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
//	ft_printf("step %d\n", step);
	c->pos += step + 2;
}

void		get_all_arg(int *arg, int num_arg, t_car *c)
{
	int step;
	int a;

	a = 0;
	step = 2;
	while (a < num_arg)
	{
		if (g_vm->arg_type[a] == REG_CODE)
		{
			arg[a] = get_arg(REG_CODE, c->pos + step, 0);
			step += 1;
		}
		if (g_vm->arg_type[a] == DIR_CODE)
		{
			arg[a] = get_arg(DIR_CODE, c->pos + step, g_op[c->op_id].dir_size);
			step += g_op[c->op_id].dir_size;
			if (g_op[c->op_id].dir_size == 2)
				arg[a] = (short)arg[a];
		}
		if (g_vm->arg_type[a] == IND_CODE)
		{
			arg[a] = get_arg(IND_CODE, c->pos + step, 2);
			step += 2;
		}
		a++;
	}
}
