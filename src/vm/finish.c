//
// Created by Oleksii KHERSONIUK on 2019-08-08.
//
#include "../../includes/vm/corewar_vm.h"

void 	show_winner(void)
{
	print_map();
//	ft_printf("I am a WINNER\n");
//	ft_printf("the winner is %s\n", g_vm->bot[g_vm->last_say_live].name);
	exit(777);
}

void	finish(void)
{
//	ft_printf("the winner is %s\n", g_vm->bot[g_vm->last_say_live].name);
	ft_printf("FINISH\n");
	exit(999);
}
