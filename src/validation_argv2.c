/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_argv2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:32:54 by aturuk            #+#    #+#             */
/*   Updated: 2019/08/06 12:32:55 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm/corewar_vm.h"

void	check_flag_dump(char **av, int *i)
{
	IS_BOTS ? error_exit(ft_printf(FLG_PLACE)) : 0;
	if (av[*i][1] == 'd')
	{
		if (g_vm->flag->dump)
			error_exit(ft_printf(FLG_DUMP_EXISTS));
		if (!(av[*i + 1]) || av[*i + 1][0] == '-' ||
		!(is_positive_int(av[*i + 1])) || av[*i + 1][0] == '0')
			error_exit(ft_printf(FLG_DUMP_N));
		g_vm->flag->dump = ft_atoi(av[*i += 1]);
	}
}

void	check_flag_i_l(char **av, int *i)
{
	int		number;

	IS_BOTS ? error_exit(ft_printf(FLG_PLACE)) : 0;
	if (av[*i][1] == 'i')
	{
		if (g_vm->flag->i != -1)
			error_exit(ft_printf(FLG_I_EXISTS));
		if (!(av[*i + 1]) || av[*i + 1][0] == '-' ||
			!(is_positive_int(av[*i + 1])))
			error_exit(ft_printf(FLG_I_N));
		number = ft_atoi(av[*i + 1]);
		if (number < 0 || number > 4)
			error_exit(ft_printf(FLG_I_N));
		g_vm->flag->i = number;
		*i += 1;
	}
	if (av[*i][1] == 'l')
	{
		if (g_vm->flag->l)
			error_exit(ft_printf(FLG_L_EXISTS));
		g_vm->flag->l += 1;
	}
}

void	check_flags_v_a_lld_m(char **av, int *i)
{
	IS_BOTS ? error_exit(ft_printf(FLG_PLACE)) : 0;
	if (av[*i][1] == 'a')
	{
		if (g_vm->flag->a)
			error_exit(ft_printf(FLG_A_EXISTS));
		g_vm->flag->a += 1;
	}
	if (av[*i][1] == 'v')
	{
		if (g_vm->flag->v)
			error_exit(ft_printf(FLG_V_EXISTS));
		g_vm->flag->v += 1;
	}
	if (av[*i][1] == 'l')
	{
		if (g_vm->flag->lld_size)
			error_exit(ft_printf(FLG_LLD_SIZE_EXISTS));
		g_vm->flag->lld_size = 2;
	}
	if (av[*i][1] == 'm')
	{
		if (g_vm->flag->m)
			error_exit(ft_printf(FLG_M_EXISTS));
		g_vm->flag->m = 64;
	}
}
