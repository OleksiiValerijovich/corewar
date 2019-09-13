/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initialization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 09:50:48 by aturuk            #+#    #+#             */
/*   Updated: 2019/08/23 09:50:49 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm/corewar_vm.h"

static void	introducing(void)
{
	int		i;

	i = -1;
	ft_printf("Introducing contestants...\n");
	while (++i < g_vm->num_bot)
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		g_vm->bot[i].num, g_vm->bot[i].size_exec_code, g_vm->bot[i].name,
		g_vm->bot[i].comment);
}

void		car_initialization(int pos, int n_player)
{
	t_car	*new;

	new = (t_car *)ft_memalloc(sizeof(t_car));
	new->num = n_player + 1;
	new->bot_num = n_player + 1;
	new->pos = pos;
	new->reg[1] = 0 - (n_player + 1);
	g_vm->num_car++;
	g_vm->car_process++;
	if (!g_vm->car)
		g_vm->car = new;
	else
	{
		g_vm->car->prev = new;
		new->next = g_vm->car;
		g_vm->car = new;
	}
}

void		map_initialization(void)
{
	int		i;
	int		j;
	int		m;

	i = -1;
	g_vm->cycles_to_die = CYCLE_TO_DIE;
	g_vm->cycles_to_die_prev = CYCLE_TO_DIE;
	while (++i < g_vm->num_bot)
	{
		j = 2192;
		m = (MEM_SIZE / g_vm->num_bot * i);
		car_initialization(m, i);
		while (j < (int)g_vm->bot[i].file_size)
		{
			g_vm->map_color[m] = i + 1;
			g_vm->map[m++] = g_vm->bot[i].bot_file[j++];
		}
	}
	(g_vm->flag->i != 0 && g_vm->flag->v == 0) ? introducing() : 0;
	g_vm->last_say_live = g_vm->num_bot;
	g_vm->cycles_to_die = CYCLE_TO_DIE;
}

void		init_vz(void)
{
	g_vm->vz = (t_visualization *)ft_memalloc(sizeof(t_visualization));
	initscr();
	curs_set(0);
	g_vm->vz->map = newwin(64, 196, 0, 0);
	g_vm->vz->menu = newwin(64, 84, 0, 196);
	g_vm->vz->speed = 50;
	init_color_pairs();
	mvwprintw(g_vm->vz->menu, 30, 5, "HOT KEYS : ");
	mvwprintw(g_vm->vz->menu, 31, 5,
		"Press any key to run 1 cycle except following");
	mvwprintw(g_vm->vz->menu, 32, 5, "Press '+' to make faster speed");
	mvwprintw(g_vm->vz->menu, 33, 5, "Press '-' to make slowly speed");
	mvwprintw(g_vm->vz->menu, 34, 5, "Press ESC to exit");
	mvwprintw(g_vm->vz->menu, 35, 5, "Press SPACE to continue fight");
}

void		print_players(void)
{
	int		i;

	i = -1;
	mvwprintw(g_vm->vz->menu, 4, 5, "FIGHTING PLAYERS :");
	while (++i < g_vm->num_bot)
	{
		wattron(g_vm->vz->menu, COLOR_PAIR(i + 1));
		mvwprintw(g_vm->vz->menu, 5 + i * 3, 5, "* Player %d, \"%s\"",
		g_vm->bot[i].num, g_vm->bot[i].name);
		mvwprintw(g_vm->vz->menu, 5 + i * 3 + 1, 5, "        Comment : %s   ",
		g_vm->bot[i].comment);
		mvwprintw(g_vm->vz->menu, 5 + i * 3 + 2, 5, "        Size : %d  ",
		g_vm->bot[i].size_exec_code);
		wattroff(g_vm->vz->menu, COLOR_PAIR(i + 1));
	}
}
