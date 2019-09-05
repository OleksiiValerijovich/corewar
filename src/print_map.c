/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:39:16 by okherson          #+#    #+#             */
/*   Updated: 2019/08/22 10:39:19 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm/corewar_vm.h"

static void	print_map2(int i)
{
	if (i != 0)
		write(1, " \n", 2);
	if (i == 0)
		ft_printf("0x0000 : ");
	else
		ft_printf("%#06x : ", i);
}

void		print_map(void)
{
	uint8_t *str;
	int		i;

	i = 0;
	str = g_vm->map;
	while (i < MEM_SIZE)
	{
		if (i % (g_vm->flag->m ? 64 : 32) == 0)
			print_map2(i);
		if (i % 1 == 0 && i % (g_vm->flag->m ? 64 : 32) != 0)
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
