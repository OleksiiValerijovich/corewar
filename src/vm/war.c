//
// Created by Oleksii KHERSONIUK on 2019-08-07.
//

#include "../../includes/vm/corewar_vm.h"

static void	get_op(t_car *c)
{
		c->op_id = vm->map[c->pos];
		if (c->op_id >= 0x01 && c->op_id <= 0x10)
			c->cycles_to_wait = g_op[c->op_id].wait;
		else
			c->pos = (c->pos + 1) % MEM_SIZE;
}

static void	car_position(t_car *c)
{
	if (c->op_id == 0 || c->op_id < 0x01 || c->op_id > 0x10)
		get_op();
	else
	{
		get_arg_type(c);
		//-> зчитування та перевірка типів аргументів, зчитування та перевірка значень аргументів,
		// якщо є регістри - перевірити коректність номера регістру. пересунути каретку на наступну позицію.
		// якщо код операції - вірний, але не вірні типи аргументів або регістри - пропустити їх та переміститись на позицію після коду операції, коду типів аргументів та аргументів, вказатих в коді типів)
		get_op();
	}
}

static void 	kill_them_all(void)
{
	t_car	*c;
	t_car	*tmp;

	c = vm->car;
	if (vm->cycles_to_die <= 0)
		finish();
	while (c)
	{
		if ((vm->cycles_total - vm->car->last_live) >= vm->cycles_to_die)
		{
			tmp = c->next;
			c->prev != NULL ? c->prev->next = c->next : 0;
			c->next != NULL ? c->next->prev = c->prev : 0;
			free(c);
			c = tmp;
			vm->num_car--;
		}
		else
			c = c->next;
	}
}

static void	check(void)
{
	vm->cycles_after_check = 0;
	if (vm->live_for_check >= NBR_LIVE)
		vm->cycles_to_die = vm->cycles_to_die - CYCLE_DELTA;
	else if (vm->check_count++ >= MAX_CHECKS)
		vm->cycles_to_die = vm->cycles_to_die - CYCLE_DELTA;
	kill_them_all();
	vm->check_count = 0;
}

void 		war(void)
{
	t_car	*c;

	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->cycles_to_die_prev = CYCLE_TO_DIE;
	while(vm->num_car > 0)
	{
		c = vm->car;
		while(c)
		{
			if (c->cycles_to_wait-- < 1)
				car_position();
			c = c->next;
		}
		vm->cycles_total++;
		if (++(vm->cycles_after_check) >= vm->cycles_to_die)
			check();
		if (vm->flag->dump > 0 && vm->cycles_total == vm->flag->dump)
		show_winer()
	}
}
