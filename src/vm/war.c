//
// Created by Oleksii KHERSONIUK on 2019-08-07.
//

#include "../../includes/vm/corewar_vm.h"



static void	car_position(t_car *c)
{
//	ft_printf("cycle #%d, car#%d, cycles to wait%d\n",g_vm->cycles_total, c->bot_num, c->cycles_to_wait);
	if (c->op_id == 0 || c->op_id < 0x01 || c->op_id > 0x10)
		get_op(c);
	else if (c->cycles_to_wait <= 0)
	{
//		write(1, "HELLO car_position\n", 19);
//		ft_printf("car#%d, c->op_id%d", c->bot_num, c->op_id);
		c->op_id == 1 ? op_live(c) : 0;
		c->op_id == 2 ? op_ld(c) : 0;
		c->op_id == 3 ? op_st(c) : 0;
		c->op_id == 4 ? op_add(c) : 0;
		c->op_id == 5 ? op_sub(c) : 0;
		c->op_id == 6 ? op_and(c) : 0;
		c->op_id == 7 ? op_or(c) : 0;
		c->op_id == 8 ? op_xor(c) : 0;
		c->op_id == 9 ? op_zjmp(c) : 0;
		c->op_id == 10 ? op_ldi(c) : 0;
		c->op_id == 11 ? op_sti(c) : 0;
		c->op_id == 12 ? op_fork(c) : 0;
		c->op_id == 13 ? op_lld(c) : 0;
		c->op_id == 14 ? op_lldi(c) : 0;
		c->op_id == 15 ? op_lfork(c) : 0;
		c->op_id == 16 ? op_aff(c) : 0;
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
	if (g_vm->num_car == 0)
		show_winner();
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
		g_vm->cycles_total++;
		c = g_vm->car;
		while(c)
		{
//			ft_printf("cycle tot %d vs cycle to wait%d \n", g_vm->cycles_total, c->cycles_to_wait);
			if (--c->cycles_to_wait < 1 || c->op_id < 1 || c->op_id > 16)
				car_position(c);
			c = c->next;
		}
		if (++(g_vm->cycles_after_check) >= g_vm->cycles_to_die)
			check();
		if (g_vm->flag->dump > 0 && g_vm->cycles_total == g_vm->flag->dump)
			show_winner();
	}
	if (g_vm->num_car == 0)
		finish();
}
