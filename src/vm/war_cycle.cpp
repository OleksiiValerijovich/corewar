//
// Created by Oleksii KHERSONIUK on 2019-08-07.
//

////////////////op make args

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

///////////////////////op make and ad function

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

void		check_argv_for_op(uint8_t *arg, t_vm *vm, t_kar *kar)
{
	arg[0] = (vm->map[(kar->pos + 1) % MEM_SIZE] >> 6 & 0x3);
	arg[1] = (vm->map[(kar->pos + 1) % MEM_SIZE] >> 4 & 0x3);
	arg[2] = (vm->map[(kar->pos + 1) % MEM_SIZE] >> 2 & 0x3);
	arg[3] = (vm->map[(kar->pos + 1) % MEM_SIZE] & 0x3);
}

void		op_recognize(t_vm *vm, t_kar *kar)
{
	kar->op_id = vm->map[kar->pos];
	if (vm->map[kar->pos] >= 0x01 && vm->map[kar->pos] <= 0x10)
		kar->cicles_to_wait = g_op[kar->op_id].wait;
}


////////////////////////////////battle


#include "vm.h"

//void static inline	ft_kar_del(t_vm *vm, t_kar *kar)
//{
//	if (!kar->back && !kar->next)
//		vm->kar = NULL;
//	else if (!kar->back)
//	{
//		vm->kar = kar->next;
//		vm->kar->back = NULL;
//	}
//	else if (!kar->next)
//		kar->back->next = NULL;
//	else
//	{
//		kar->next->back = kar->back;
//		kar->back->next = kar->next;
//	}
//}
//
//void static inline	killing_kars(t_vm *vm)
//{
//	t_kar	*kar;
//	t_kar	*tmp;
//
//	kar = vm->kar;
//	while (kar)
//	{
//		tmp = kar->next;
//		if (vm->cycles_from_start - kar->live >= vm->cycles_to_die)
//		{
//			ft_kar_del(vm, kar);
//			if (vm->v_fl == 8 || vm->v_fl == 30)
//				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
//						  kar->id, vm->cycles_from_start - kar->live, vm->cycles_to_die);
//			free(kar);
//		}
//		kar = tmp;
//	}
//}
//
//void static inline	battle_proverka(t_vm *vm)
//{
//	if (vm->cycles_to_die <= 0 || (vm->cycles_after_check == vm->cycles_to_die))
//	{
//		killing_kars(vm);
//		vm->check_count++;
//		vm->cycles_to_die_prev = vm->cycles_to_die;
//		if (vm->check_count == MAX_CHECKS || vm->num_of_life >= NBR_LIVE)
//		{
//			vm->cycles_to_die -= CYCLE_DELTA;
//			vm->check_count = 0;
//		}
//		vm->num_of_life = 0;
//		vm->cycles_after_check = 0;
//		if ((vm->v_fl == 2 || vm->v_fl == 30)
//			&& vm->cycles_to_die != vm->cycles_to_die_prev)
//			ft_printf("Cycle to die is now %d\n", vm->cycles_to_die);
//	}
//}

//void static inline	battle_operations_cycyle(t_vm *vm)
//{
//	t_kar	*kar;
//
//	kar = vm->kar;
//	while (kar)
//	{
//		if (kar->cicles_to_wait == 0)
//			op_recognize(vm, kar);
//		if (kar->cicles_to_wait > 0)
//			kar->cicles_to_wait--;
//		if (kar->cicles_to_wait == 0)
//		{
//			if (kar->op_id >= 0x01 && kar->op_id <= 0x10)
//				(*g_opers[kar->op_id])(vm, kar);
//			else
//				kar->pos = (kar->pos + 1) % MEM_SIZE;
//			kar->pos = kar->pos % MEM_SIZE;
//		}
//		if (vm->ncurs)
//			visualisation(vm);
//		kar = kar->next;
//	}
//}

void				battle(t_vm *vm)
{
	vm->cycles_to_die_prev = CYCLE_TO_DIE;
	while (vm->kar)
	{
		if ((vm->nbr_cycles > -1 && vm->cycles_from_start >= vm->nbr_cycles))
		{
			print_map(vm);
			break ;
		}
		vm->cycles_from_start++;
		vm->cycles_after_check++;
		if (vm->v_fl == 2 || vm->v_fl == 30)
			ft_printf("It is now cycle %d\n", vm->cycles_from_start);
		battle_operations_cycyle(vm);
		battle_proverka(vm);
	}
	if ((vm->nbr_cycles == -1 || vm->cycles_from_start < vm->nbr_cycles)
		&& !vm->ncurs)
		show_winner(vm);
	if (vm->ncurs)
	{
		show_winner_vis(vm);
		getch();
		endwin();
	}
}
