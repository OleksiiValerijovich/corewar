//
// Created by Oleksii KHERSONIUK on 2019-08-06.
//

#include "../../includes/vm/corewar_vm.h"

static void	introducing(void)
{
	int 	i;

	i = -1;
	ft_printf("Introducing contestants...\n");
	while (++i < g_vm->num_bot)
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		g_vm->bot[i].num, g_vm->bot[i].size_exec_code, g_vm->bot[i].name,
		g_vm->bot[i].comment);
}

void	car_initialization(int pos, int n_player)
{
	t_car	*new;

	new = (t_car *)ft_memalloc(sizeof(t_car));
		new->num = n_player;
		new->bot_num = n_player + 1;
		new->pos = pos;
		new->reg[1] = 0 - (n_player + 1);
		g_vm->num_car++;
	if (!g_vm->car )
		g_vm->car = new;
	else
	{
		g_vm->car->prev = new;
		new->next = g_vm->car;
		g_vm->car = new;
	}
}

void 	map_initialization(void)
{
	int		i;
	int 	j;
	int 	m;

	i = -1;
	g_vm->cycles_to_die = CYCLE_TO_DIE;
	g_vm->cycles_to_die_prev = CYCLE_TO_DIE;
	while (++i < g_vm->num_bot)
	{
		j = 2192;
		m = (4096 / g_vm->num_bot * i);
		car_initialization(m, i);
		while (j < (int)g_vm->bot[i].file_size)
		{
			g_vm->map_color[m] = i + 1;
			g_vm->map[m++] = g_vm->bot[i].bot_file[j++];
		}
	}
	introducing();
	g_vm->last_say_live = g_vm->num_bot;
	g_vm->cycles_to_die = CYCLE_TO_DIE;
}