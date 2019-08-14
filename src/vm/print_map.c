//
// Created by Oleksii KHERSONIUK on 2019-08-11.
//

#include "../../includes/vm/corewar_vm.h"

void 	print_map()
{
	uint8_t *str;
	int 	i;

//	printf("map:\n");
	i = 0;
	str = g_vm->map;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
		{
			if (i != 0)
				write(1, " \n", 2);
			if (i == 0)
				ft_printf("0x0000 : ");
			else
				ft_printf("%#06x : ", i);
		}
		if (i % 1 == 0 && i % 64 != 0)
			write(1, " ", 1);
		if (!str[i])
			write(1, "00 ", 2);
		else
		{
			if (str[i] < 16)
				write(1, "0", 1);
			ft_printf("%x", str[i]);

		}
		i++;
	}
	write(1, " \n", 2);
}