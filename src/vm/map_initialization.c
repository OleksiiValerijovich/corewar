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
		vm->bot[i].num + 1, vm->bot[i].size_exec_code, vm->bot[i].name,
		vm->bot[i].comment);
}

void	car_initialization(int pos, int n_player)
{
	if (!vm->car )
	{
		vm->car = (t_car *)ft_memalloc(sizeof(t_car));
		vm->car->num = n_player;
		vm->car->bot_num = n_player;
		vm->car->pos = pos;
		vm->car->live = 1;
	}
	else
	{
		vm->car->next = (t_car *)ft_memalloc(sizeof(t_car));
		vm->car->next->prev = vm->car;
		vm->car = vm->car->next;
		vm->car->num = n_player;
		vm->car->bot_num = n_player;
		vm->car->pos = pos;
		vm->car->live = 1;
	}
}

void 	map_initialization(void)
{
	int		i;
	int 	j;
	int 	m;

	i = -1;
	vm->cycles_to_die = CYCLE_TO_DIE;
	while (++i < vm->num_bot)
	{
		j = 2192;
		m = (4096 / vm->num_bot * i);
		car_initialization(m, i);
		while (j < (int)vm->bot[i].file_size)
			vm->map[m++] = vm->bot[i].bot_file[j++];
	}
	introducing();
}