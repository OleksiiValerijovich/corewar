//
// Created by Oleksii KHERSONIUK on 2019-08-08.
//
#include "../../includes/vm/corewar_vm.h"

void 	show_winner(void)
{
	print_map();
//	ft_printf("I am a WINNER\n");
	exit(777);
}

void	finish(void)
{
	ft_printf("I am a WINNER that is why it is finish\n");
	exit(999);
}
