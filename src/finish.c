/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 09:09:56 by aturuk            #+#    #+#             */
/*   Updated: 2019/08/23 09:09:57 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm/corewar_vm.h"

static void	ncurses_finish(void)
{
	int		key;

	key = 0;
	system("afplay sound/champion.mp3&");
	wattron(g_vm->vz->menu, COLOR_PAIR(9));
	mvwprintw(g_vm->vz->menu, 2, 5, "Player %d (%s) won !",
	g_vm->last_say_live, g_vm->bot[g_vm->last_say_live - 1].name);
	mvwprintw(g_vm->vz->menu, 40, 5, "PLEASE, PRESS ANY KEY TO QUIT ;-)");
	wattroff(g_vm->vz->menu, COLOR_PAIR(9));
	wrefresh(g_vm->vz->menu);
	timeout(9999999999999);
	key = getch();
	key != 0 ? end_exit() : 0;
}

void		finish(void)
{
	if (g_vm->num_car <= 0)
	{
		if (g_vm->flag->v == 0)
		{
			ft_printf("Player %d (%s) won !\n",
			g_vm->last_say_live, g_vm->bot[g_vm->last_say_live - 1].name);
			g_vm->flag->i == 2 ? print_map() : 0;
		}
		else
			ncurses_finish();
	}
	else
		g_vm->flag->v == 0 ? print_map() : 0;
	(g_vm->flag->l && g_vm->flag->v == 0) ? system("leaks -q corewar") : 0;
	exit(999);
}
