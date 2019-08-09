//
// Created by Oleksii KHERSONIUK on 2019-08-06.
//

#include "../../includes/vm/corewar_vm.h"

static void	introducing(void)
{
	int 	i;

	i = -1;
	ft_printf("Introducing contestants...\n");
	while (++i < vm->num_bot)
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		vm->bot[i].num, vm->bot[i].size_exec_code, vm->bot[i].name,
		vm->bot[i].comment);
}

void	car_initialization(int pos, int n_player)
{
	t_car	*new;

	new = (t_car *)ft_memalloc(sizeof(t_car));
		new->num = n_player;
		new->bot_num = n_player;
		new->pos = pos;
		new->reg[1] = 0 - (n_player + 1);
		vm->num_car++;
	if (!vm->car )
		vm->car = new;
	else
	{
		vm->car->prev = new;
		new->next = vm->car;
		vm->car = new;
	}
}

void 	map_initialization(void)
{
	int		i;
	int 	j;
	int 	m;

	i = -1;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->cycles_to_die_prev = CYCLE_TO_DIE;
	while (++i < vm->num_bot)
	{
		j = 2192;
		m = (4096 / vm->num_bot * i);
		car_initialization(m, i);
		while (j < (int)vm->bot[i].file_size)
		{
			vm->map_color[m] = i + 1;
			vm->map[m++] = vm->bot[i].bot_file[j++];
		}
	}
	introducing();
	vm->last_say_live = vm->num_bot;
	vm->cycles_to_die = CYCLE_TO_DIE;
}