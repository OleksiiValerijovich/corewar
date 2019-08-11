//
// Created by Oleksii KHERSONIUK on 2019-08-07.
//

#include "../../includes/vm/corewar_vm.h"



static void	car_position(t_car *c)
{
	if (c->op_id == 0 || c->op_id < 0x01 || c->op_id > 0x10)
		get_op(c);
	else
	{
		if (c->op_id == 1)
		op_live(c);
//		op_ld(c);
//		print_map();
//		op_st(c);
//		finish();
		//-> зчитування та перевірка типів аргументів, зчитування та перевірка значень аргументів,
		// якщо є регістри - перевірити коректність номера регістру. пересунути каретку на наступну позицію.
		// якщо код операції - вірний, але не вірні типи аргументів або регістри - пропустити їх та переміститись на позицію після коду операції, коду типів аргументів та аргументів, вказатих в коді типів)
		get_op(c);
	}
}

static void 	kill_them_all(void)
{
	t_car	*c;
	t_car	*tmp;

	c = g_vm->car;
	if (g_vm->cycles_to_die <= 0)
		finish();
	while (c)
	{
		if ((g_vm->cycles_total - g_vm->car->last_live) >= g_vm->cycles_to_die)
		{
			tmp = c->next;
			c->prev != NULL ? c->prev->next = c->next : 0;
			c->next != NULL ? c->next->prev = c->prev : 0;
			free(c);
			c = tmp;
			g_vm->num_car--;
		}
		else
			c = c->next;
	}
}

static void	check(void)
{
	g_vm->cycles_after_check = 0;
	if (g_vm->live_for_check >= NBR_LIVE)
		g_vm->cycles_to_die = g_vm->cycles_to_die - CYCLE_DELTA;
	else if (g_vm->check_count++ >= MAX_CHECKS)
		g_vm->cycles_to_die = g_vm->cycles_to_die - CYCLE_DELTA;
	kill_them_all();
	g_vm->check_count = 0;
}

void 		war(void)
{
	t_car	*c;

	g_vm->cycles_to_die = CYCLE_TO_DIE;
	g_vm->cycles_to_die_prev = CYCLE_TO_DIE;
	while(g_vm->num_car > 0)
	{
		c = g_vm->car;
		while(c)
		{
			if (c->cycles_to_wait-- < 1)
				car_position(c);
			c = c->next;
		}
		g_vm->cycles_total++;
		if (++(g_vm->cycles_after_check) >= g_vm->cycles_to_die)
			check();
		if (g_vm->flag->dump > 0 && g_vm->cycles_total == g_vm->flag->dump)
			show_winner();
	}
	if (g_vm->num_car == 0)
		finish();
}
