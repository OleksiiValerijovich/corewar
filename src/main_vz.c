/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 11:47:42 by itishche          #+#    #+#             */
/*   Updated: 2019/08/18 11:47:44 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm/corewar_vm.h"

static void	car_position_vz(WINDOW *map)
{
	t_car	*tmp;

	tmp = g_vm->car;
	while (tmp)
	{
		wattron(map, COLOR_PAIR(tmp->bot_num + 4));
		mvwprintw(map, tmp->pos / 64, (tmp->pos % 64) * 3, "%02x",
		g_vm->map[tmp->pos]);
		wattroff(map, COLOR_PAIR(tmp->bot_num + 4));
		tmp = tmp->next;
	}
}

static void	map_position(WINDOW *map)
{
	int		index;
	int		count_bot;

	count_bot = 0;
	while (count_bot <= g_vm->num_bot)
	{
		index = 0;
		wattron(map, COLOR_PAIR(count_bot));
		while (index < MEM_SIZE)
		{
			if (g_vm->map_color[index] == count_bot)
				mvwprintw(map, index / 64, (index % 64) * 3, "%02x",
				g_vm->map[index]);
			index++;
		}
		wattroff(map, COLOR_PAIR(count_bot));
		count_bot++;
	}
	index = -1;
	while (++index < MEM_SIZE)
	{
		if (g_vm->map_color[index] == 0)
			mvwprintw(map, index / 64, (index % 64) * 3, "%02x",
			g_vm->map[index]);
	}
}

static void	time_funct(int key)
{
	key = getch();
	key == 27 ? end_exit() : 0;
	if (key == 32)
		g_vm->vz->keycode = (g_vm->vz->keycode == 32) ? 0 : 32;
	else if (key == 43 || key == 45)
	{
		g_vm->vz->speed -= key == 43 ? 1 : 0;
		g_vm->vz->speed += key == 45 ? 1 : 0;
		g_vm->vz->speed = g_vm->vz->speed < 0 ? 0 : g_vm->vz->speed;
		g_vm->vz->speed = g_vm->vz->speed > 100 ? 100 : g_vm->vz->speed;
	}
	if (g_vm->vz->keycode == 32)
	{
		system("afplay sound/pause.mp3&");
		wattron(g_vm->vz->menu, COLOR_PAIR(9));
		mvwprintw(g_vm->vz->menu, 20, 5, "** PAUSE **");
		wattroff(g_vm->vz->menu, COLOR_PAIR(9));
		timeout(999999999);
	}
	else if (g_vm->vz->keycode == 0)
	{
		mvwprintw(g_vm->vz->menu, 20, 5, "** FIGHT **");
		timeout(g_vm->vz->speed * 10);
	}
}

static void	main_vz2(void)
{
	mvwprintw(g_vm->vz->menu, 26, 5, "Cycles after check : %d    ",
	g_vm->cycles_after_check);
	print_players();
	wrefresh(g_vm->vz->menu);
	wrefresh(g_vm->vz->map);
}

void		main_vz(void)
{
	initscr();
	time_funct(0);
	keypad(stdscr, TRUE);
	curs_set(0);
	wattron(g_vm->vz->menu, A_STANDOUT);
	wattron(g_vm->vz->map, A_STANDOUT);
	box(g_vm->vz->menu, 1, 1);
	wattroff(g_vm->vz->menu, A_STANDOUT);
	wattroff(g_vm->vz->map, A_STANDOUT);
	map_position(g_vm->vz->map);
	car_position_vz(g_vm->vz->map);
	mvwprintw(g_vm->vz->menu, 21, 5, "SPEED _\\|/_ : %d%%  ",
	100 - g_vm->vz->speed);
	mvwprintw(g_vm->vz->menu, 22, 5, "Total cycle : %d  ", g_vm->cycles_total);
	mvwprintw(g_vm->vz->menu, 23, 5, "Last say LIVE :");
	wattron(g_vm->vz->menu, COLOR_PAIR(g_vm->last_say_live));
	mvwprintw(g_vm->vz->menu, 23, 21, "%-58s",
	g_vm->bot[g_vm->last_say_live - 1].name);
	wattroff(g_vm->vz->menu, COLOR_PAIR(g_vm->last_say_live));
	mvwprintw(g_vm->vz->menu, 24, 5, "Processes : %d     ", g_vm->num_car);
	mvwprintw(g_vm->vz->menu, 25, 5, "Cycles to die : %d     ",
	g_vm->cycles_to_die);
	main_vz2();
}
