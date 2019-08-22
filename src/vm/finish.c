/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:36:00 by okherson          #+#    #+#             */
/*   Updated: 2019/08/22 10:36:02 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
