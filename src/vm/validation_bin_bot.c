//
// Created by Oleksii KHERSONIUK on 2019-08-05.
//

#include "../../includes/vm/corewar_vm.h"
#include <stdio.h>

static void read_bot(int fd, int i)
{

	i = -1;
	unsigned char c[5000];
	vm->bot[i]->file_size = read(fd, c, 5000);
		ft_printf("%d ", i = ((c[136] << 24) + (c[137] << 16) +
		(c[138] << 8) + c[139]));

}

void		validation_bin_bot(void)
{
	int 	i;

	i = -1;


	read_bot(open("./champs/Gagnant.cor", O_RDONLY), i);


	while (vm->bot[++i])
	{
		read_bot(open(vm->bot[i]->argv, O_RDONLY), i);
			ft_printf(EMPTY_BOT_FILE);
	}
}