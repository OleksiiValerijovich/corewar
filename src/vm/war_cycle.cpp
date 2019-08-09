//
// Created by Oleksii KHERSONIUK on 2019-08-07.
//

battle_operations_cycyle(t_vm *vm)
{
	t_kar	*kar;

	kar = vm->kar;
	while (kar)
	{
		if (kar->cicles_to_wait == 0)
		{
			if (kar->op_id >= 0x01 && kar->op_id <= 0x10)
				(*g_opers[kar->op_id])(vm, kar);
			else
				kar->pos = (kar->pos + 1) % MEM_SIZE;
			kar->pos = kar->pos % MEM_SIZE;
		}
		if (vm->ncurs)
			visualisation(vm);
		kar = kar->next;
	}
}

int			take_arg(t_vm *vm, int pos, int size_arg)
{
	int		arg;

	arg = 0;
	while (size_arg)
		arg += (vm->map[pos++ % MEM_SIZE] << (8 * --size_arg));
	return (arg);
}

static int	reg_add(uint8_t reg, uint32_t *args, int i, int n)
{
	if ((int)reg > 0 && (int)reg < 17)
		args[n] = reg;
	else
		args[n] = -1;
	i += REG;
	return (i);
}



void		read_args(t_vm *vm, t_kar *kar, uint32_t *args, uint8_t *cod_arg)
{
	int			i;
	int			n;
	uint16_t	ind;

	i = 0;
	n = -1;
	while (++n < 3)
	{
		if (cod_arg[n] == REG_CODE)
			i = reg_add(vm->map[(kar->pos + 2 + i) % MEM_SIZE], args, i, n);
		else if (cod_arg[n] == DIR_CODE)
		{
			args[n] = (g_op[kar->op_id].dir_size == 4 ?
					   take_arg(vm, (kar->pos + 2 + i), 4) :
					   (short)take_arg(vm, (kar->pos + 2 + i), 2));
			i += g_op[kar->op_id].dir_size;
		}
		else if (cod_arg[n] == IND_CODE)
		{
			ind = kar->pos +
				  (short)take_arg(vm, (kar->pos + 2 + i), 2) % IDX_MOD;
			args[n] = take_arg(vm, (ind % MEM_SIZE), 4);
			i += IND;
		}
	}
}



void		give_reg_to_map(t_vm *vm, int pos, t_kar *kar, uint32_t src)
{
int	size_arg;

size_arg = 4;
while (size_arg)
{
vm->map[pos % MEM_SIZE] = src >> (8 * --size_arg) & 0xff;
vm->inf_vis[pos++ % MEM_SIZE] = kar->bot_id;
}
}

int			step_for_not_valid(uint8_t *arg, t_kar *kar, int num_arg)
{
	int i;

	i = 0;
	while (--num_arg != -1)
	{
		if (arg[num_arg] == REG_CODE)
			i += REG;
		else if (arg[num_arg] == DIR_CODE)
			i += g_op[kar->op_id].dir_size;
		else if (arg[num_arg] == IND_CODE)
			i += IND;
	}
	i += (g_op[kar->op_id].is_args_types + 1);
	return (i);
}

void		op_recognize(t_vm *vm, t_kar *kar)
{
	kar->op_id = vm->map[kar->pos];
	if (vm->map[kar->pos] >= 0x01 && vm->map[kar->pos] <= 0x10)
		kar->cicles_to_wait = g_op[kar->op_id].wait;
}



////////////////////////////////life
void	vm_live(t_vm *vm, t_kar *kar)
{
	int		arg;

	arg = take_arg(vm, (kar->pos + 1), 4);
	if (arg < 0 && (int)kar->bot_id == ABS(arg))
		vm->last_say_live = kar->bot_id;
	kar->live = vm->cycles_from_start;
	vm->num_of_life++;
	if (vm->v_fl == 4 || vm->v_fl == 30)
		ft_printf("P% 5d | live %d\n", kar->id, arg);
	print_adv(vm, kar->pos, kar->pos += g_op[kar->op_id].dir_size + 1);
}


int			take_arg(t_vm *vm, int pos, int size_arg)
{
int		arg;

arg = 0;
while (size_arg)
arg += (vm->map[pos++ % MEM_SIZE] << (8 * --size_arg));
return (arg);
}

static int	reg_add(uint8_t reg, uint32_t *args, int i, int n)
{
	if ((int)reg > 0 && (int)reg < 17)
		args[n] = reg;
	else
		args[n] = -1;
	i += REG;
	return (i);
}

void		read_args(t_vm *vm, t_kar *kar, uint32_t *args, uint8_t *cod_arg)
{
	int			i;
	int			n;
	uint16_t	ind;

	i = 0;
	n = -1;
	while (++n < 3)
	{
		if (cod_arg[n] == REG_CODE)
			i = reg_add(vm->map[(kar->pos + 2 + i) % MEM_SIZE], args, i, n);
		else if (cod_arg[n] == DIR_CODE)
		{
			args[n] = (g_op[kar->op_id].dir_size == 4 ?
					   take_arg(vm, (kar->pos + 2 + i), 4) :
					   (short)take_arg(vm, (kar->pos + 2 + i), 2));
			i += g_op[kar->op_id].dir_size;
		}
		else if (cod_arg[n] == IND_CODE)
		{
			ind = kar->pos +
				  (short)take_arg(vm, (kar->pos + 2 + i), 2) % IDX_MOD;
			args[n] = take_arg(vm, (ind % MEM_SIZE), 4);
			i += IND;
		}
	}
}