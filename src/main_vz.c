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

//функция печати каретки
static void	car_position_vz(WINDOW *map)
{
	t_car	*tmp;

	tmp = g_vm->car;
	while(tmp)
	{
		wattron(map, COLOR_PAIR(tmp->bot_num + 4));
		mvwprintw(map, tmp->pos / 64, (tmp->pos % 64) *3, "%02x", g_vm->map[tmp->pos]);
		//mvwprintw(win, y, x, "%s", string); - на координаты x,y ставит указаную короткую строку из карты в 16ричной системе
		//типо принтф только местный
		wattroff(map, COLOR_PAIR(tmp->bot_num + 4));
		tmp=tmp->next;
	}
}

/////////////////////////////////////////////////////////////////////////////////////
void	init_color_pairs(void)
{
	start_color();
//init_pair() нужна чтобы задать какой цифре какой цвет будет соответствовать от 1 до 
//COLOR_PAIRS-1 (0 зарезервирован для стандартного отображения). Для использования 
//цвета в символе нужно включить флажок COLOR_PAIR(номер из палитры).
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_BLACK,  COLOR_BLUE);
	init_pair(6, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(7, COLOR_BLACK, COLOR_YELLOW);
	init_pair(8, COLOR_BLACK, COLOR_CYAN);
}
//инициализация структуры на визуализацию

////////////////////////////////////////////////////////////////////////////////////

static void	map_position(WINDOW *map)
{
	int		index;
	int		count_bot;

	count_bot = 0;
	while (count_bot <= g_vm->num_bot)//виводим каждого бота на карту его цветом
	{
		index=0;
		wattron(map, COLOR_PAIR(count_bot));
		while (index < MEM_SIZE)
		{
			if (g_vm->map_color[index] == count_bot)
				mvwprintw(map, index/64, (index % 64)*3, "%02x",g_vm->map[index]);
			index++;
		}
		wattroff(map, COLOR_PAIR(count_bot));
		count_bot++;
	}
	index = -1;
	while (++index < MEM_SIZE)//выводим дефолтные значения (000000 и тд)
	{
		if (g_vm->map_color[index] == 0)
			mvwprintw(map, index/64, (index % 64)*3, "%02x",g_vm->map[index]);
	}
}

static void	time_funct(void)
{
	int 	key;

	key = getch();/* Wait for user input */
	if (key == 27)// - это ASCII код ESC
		end_exit();
	if (key == 32)
		g_vm->vz->keycode = (g_vm->vz->keycode == 32) ? 0 : 32;
	else if (key == 43 || key == 45)
	{
		g_vm->vz->speed -= key == 43 ? 1 : 0;
		g_vm->vz->speed += key == 45 ? 1 : 0;
		g_vm->vz->speed = g_vm->vz->speed < 0 ? 0 : g_vm->vz->speed;
		g_vm->vz->speed = g_vm->vz->speed > 100 ? 100 : g_vm->vz->speed;
	}
	if (g_vm->vz->keycode == 32) ////////////////////////////////PAUSE
	{
		system("afplay sound/pause.mp3&");
		mvwprintw(g_vm->vz->menu, 20, 5, "** PAUSE **");
		timeout(999999999);
	}
	else if (g_vm->vz->keycode == 0)///////////////////fight
	{
//		system("afplay sound/hit.mp3&");
		mvwprintw(g_vm->vz->menu, 20, 5, "** FIGHT **");
		timeout(g_vm->vz->speed * 10);
	}
}

static void	print_players(void)
{
	int i;

	i = -1;
	mvwprintw(g_vm->vz->menu, 4, 5, "FIGHTING PLAYERS :");
	while (++i < g_vm->num_bot)
	{
		mvwprintw(g_vm->vz->menu, 5 + i * 3, 5, "* Player %d, \"%s\"",
				  g_vm->bot[i].num,  g_vm->bot[i].name);
		mvwprintw(g_vm->vz->menu, 5 + i * 3 + 1, 5, "        Comment : %s   ", g_vm->bot[i].comment);
		mvwprintw(g_vm->vz->menu, 5 + i * 3 + 2, 5, "        Size : %d  ", g_vm->bot[i].size_exec_code);

	}
}


void	main_vz(void)
{
	initscr();// инициализация (должна быть выполнена перед использованием ncurses)
	time_funct();
	keypad(stdscr, TRUE);	// Получаем F1, F2 etс
	curs_set(0);// Делаем курсор невидимым
//		refresh();
	wattron(g_vm->vz->menu, A_STANDOUT);//рамочка
	wattron(g_vm->vz->map, A_STANDOUT);
	box(g_vm->vz->menu,1,1);
	wattroff(g_vm->vz->menu, A_STANDOUT);
	wattroff(g_vm->vz->map, A_STANDOUT);
	map_position(g_vm->vz->map);//печать карты
	car_position_vz(g_vm->vz->map);//печать каретки
	mvwprintw(g_vm->vz->menu, 21, 5, "SPEED _\\|/_ : %d%%  ", 100 - g_vm->vz->speed);
	mvwprintw(g_vm->vz->menu, 22, 5, "Total cycle : %d  ", g_vm->cycles_total);
	mvwprintw(g_vm->vz->menu, 23, 5, "Last say LIVE : %-58s", g_vm->bot[g_vm->last_say_live - 1].name);
	mvwprintw(g_vm->vz->menu, 24, 5, "Processes : %d     ", g_vm->num_car);
	mvwprintw(g_vm->vz->menu, 25, 5, "Cycles to die : %d     ", g_vm->cycles_to_die);
	mvwprintw(g_vm->vz->menu, 26, 5, "Cycles after check : %d    ", g_vm->cycles_after_check);
	print_players();
	wrefresh(g_vm->vz->menu);
	wrefresh(g_vm->vz->map);

	////getch() - Эта функция считывает только один символ с терминала
//	endwin(); // завершение работы с ncurses
}