//
// Created by Oleksii KHERSONIUK on 2019-08-08.
//
#include "../../includes/vm/corewar_vm.h"

void	finish(void)
{
	if (g_vm->num_car <= 0)
		ft_printf("Contestant %d, \"%s\", has won !\n",
		g_vm->last_say_live, g_vm->bot[g_vm->last_say_live - 1].name);
	else
		print_map();
	exit(999);
}
