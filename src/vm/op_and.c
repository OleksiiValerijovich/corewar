//
// Created by Oleksii KHERSONIUK on 2019-08-12.
//

#include "../../includes/vm/corewar_vm.h"

void 		op_and(t_car *c)
{
	int 	arg[3];

	ft_bzero(arg, sizeof(int) * 3);
	get_arg_type(c);
	if ((g_vm->arg_type[0] && g_vm->arg_type[1] && g_vm->arg_type[2] == REG_CODE)
	{
		get_all_arg(arg, 3, c);
		if ((g_vm->arg_type[0] == REG_CODE && (arg[0] < 1 || arg[0] > 16)) ||
		(g_vm->arg_type[1] == REG_CODE && (arg[1] < 1 || arg[1] > 16)) ||
		(arg[2] < 1 || arg[2] > 16))
			step_for_not_valid_arg_types(c, 3);
		else
		{

		}
//		{
//			sec_arg(arg, c);
//		}
//		else if (g_vm->arg_type[0] == DIR_CODE)
//		{
//			sec_arg(arg, c);
//		}
//		else if (g_vm->arg_type[0] == IND_CODE)
//		{
//			sec_arg(arg, c);
//		}
	}
	else
		step_for_not_valid_arg_types(c, 3);
}