/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   war.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:39:30 by okherson          #+#    #+#             */
/*   Updated: 2019/08/22 10:39:33 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm/corewar_vm.h"

void		car_position(t_car *c)
{
	if (c->op_id < 0x01 || c->op_id > 0x10)
		get_op(c);
	else
	{
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
		c->op_id = 0;
	}
}

static void	kill_them_all(void)
{
	t_car	*c;
	t_car	*tmp;

	c = g_vm->car;
	while (c)
	{
		if ((g_vm->cycles_total - c->last_live) >= g_vm->cycles_to_die)
		{
			g_vm->flag->i == 3 && g_vm->flag->v == 0 ?
			ft_printf("Process %d hasn't lived for %d "
			"cycles (CTD %d)\n", c->num, g_vm->cycles_total - c->last_live,
			g_vm->cycles_to_die) : 0;
			if (c->prev == NULL)
				g_vm->car = c->next;
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
	g_vm->num_car == 0 ? finish() : 0;
}

static void	check(void)
{
	g_vm->cycles_after_check = 0;
	kill_them_all();
	if (g_vm->live_for_check >= NBR_LIVE)
	{
		g_vm->cycles_to_die = g_vm->cycles_to_die - CYCLE_DELTA;
		g_vm->flag->i == 1 ?
		ft_printf("Cycle to die is now %d\n", g_vm->cycles_to_die) : 0;
		g_vm->check_count = 0;
	}
	else if (g_vm->check_count >= MAX_CHECKS)
	{
		g_vm->cycles_to_die = g_vm->cycles_to_die - CYCLE_DELTA;
		g_vm->flag->i == 1 ?
		ft_printf("Cycle to die is now %d\n", g_vm->cycles_to_die) : 0;
		g_vm->check_count = 0;
	}
	g_vm->live_for_check = 0;
	g_vm->check_count++;
}

void		war(void)
{
	t_car	*c;

	g_vm->cycles_to_die = CYCLE_TO_DIE;
	g_vm->cycles_to_die_prev = CYCLE_TO_DIE;
	while (g_vm->num_car > 0)
	{
		g_vm->cycles_total++;
		if (g_vm->flag->i == 1 && g_vm->flag->v == 0)
			ft_printf("It is now cycle %d\n", g_vm->cycles_total);
		c = g_vm->car;
		while (c)
		{
			if (--c->cycles_to_wait < 1 || (int)c->op_id < 1
			|| (int)c->op_id > 16)
				car_position(c);
			c = c->next;
		}
		if (++(g_vm->cycles_after_check) >= g_vm->cycles_to_die)
			check();
		if (g_vm->flag->dump > 0 && g_vm->cycles_total == g_vm->flag->dump)
			finish();
		g_vm->flag->v > 0 ? main_vz() : 0;
	}
	if (g_vm->num_car == 0)
		finish();
}
