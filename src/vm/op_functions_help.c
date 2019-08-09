//
// Created by Oleksii KHERSONIUK on 2019-08-09.
//

uint8_t		*get_arg_type(t_car *c)
{
	uint8_t	arg[3];

	arg[0] = vm->map[c->pos + 1 % MEM_SIZE] >> 6 & 0x03;
	arg[1] = vm->map[c->pos + 1 % MEM_SIZE] >> 4 & 0x03;
	arg[2] = vm->map[c->pos + 1 % MEM_SIZE] >> 2 & 0x03;
	return (arg);
}

