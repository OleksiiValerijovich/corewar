/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bin_bot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:03:52 by okherson          #+#    #+#             */
/*   Updated: 2019/08/06 13:05:30 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm/corewar_vm.h"

static void read_bot(int fd, int i)
{
	uint8_t 	*c;
	int 		j;
	int 		a;

	a = 0;
	j = 4;
	if ((vm->bot[i].file_size = read(fd, vm->bot[i].bot_file, 2900)) > 2874 ||
	vm->bot[i].file_size < 2192)
		error_exit(ft_printf(INCORRECT_COR_FILE, vm->bot[i].argv));
	c = vm->bot[i].bot_file;
	vm->bot[i].magic_header = ((c[0] << 24) + (c[1] << 16) + (c[2] << 8) + c[3]);
	if (vm->bot[i].magic_header != COREWAR_EXEC_MAGIC)
		error_exit(ft_printf(WRONG_MAGIC_HEADER));
	while (j < 132)
		vm->bot[i].name[a++] = c[j++];
	(c[132] || c[133] || c[134] || c[135] || c[2188] || c[2189] || c[2190] ||
	c[2191]) ? error_exit(ft_printf(INCORRECT_NULL)) : 0;
	if ((vm->bot[i].size_exec_code = (c[136] << 24) + (c[137] << 16) +
	(c[138] << 8) + c[139]) > 682 || vm->bot[i].size_exec_code + 2192 !=
	vm->bot[i].file_size)
		error_exit(ft_printf(INCORRECT_COR_FILE, vm->bot[i].argv));
	j = 140;
	a = 0;
	while (j < 2188)
		vm->bot[i].comment[a++] = c[j++];
}

void		validation_bin_bot(void)
{
	int 	i;

	i = -1;
	while (++i < vm->num_bot)
		read_bot(open(vm->bot[i].argv, O_RDONLY), i);
}