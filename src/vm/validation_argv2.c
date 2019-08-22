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

#include "../../includes/vm/corewar_vm.h"

void	check_flag_dump_p(char **av, int *i)
{
	if (g_vm->bot[0].argv || g_vm->bot[1].argv ||
	g_vm->bot[2].argv || g_vm->bot[3].argv)
		error_exit(ft_printf(FLG_PLACE));
	if (av[*i][1] == 'd')
	{
		if (g_vm->flag->dump)
			error_exit(ft_printf(FLG_DUMP_EXISTS));
		if (!(av[*i + 1]) || av[*i + 1][0] == '-' ||
		!(is_positive_int(av[*i + 1])) || av[*i + 1][0] == '0')
			error_exit(ft_printf(FLG_DUMP_N));
		g_vm->flag->dump = ft_atoi(av[*i += 1]);
	}
	if (av[*i][1] == 'p')
	{
		if (g_vm->flag->p)
			error_exit(ft_printf(FLG_P_EXISTS));
		if (!(av[*i + 1]) || av[*i + 1][0] == '-' ||
		!(is_positive_int(av[*i + 1])) || av[*i + 1][0] == '0')
			error_exit(ft_printf(FLG_P_N));
		g_vm->flag->p = ft_atoi(av[*i += 1]);
	}
}

void	check_flag_i(char **av, int *i)
{
	int		number;

	if (g_vm->bot[0].argv || g_vm->bot[1].argv ||
	g_vm->bot[2].argv || g_vm->bot[3].argv)
		error_exit(ft_printf(FLG_PLACE));
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

void	check_flags_b_v(char **av, int *i)
{
	if (g_vm->bot[0].argv || g_vm->bot[1].argv ||
	g_vm->bot[2].argv || g_vm->bot[3].argv)
		error_exit(ft_printf(FLG_PLACE));
	if (av[*i][1] == 'b')
	{
		if (g_vm->flag->b)
			error_exit(ft_printf(FLG_B_EXISTS));
		g_vm->flag->b += 1;
	}
	if (av[*i][1] == 'v')
	{
		if (g_vm->flag->v)
			error_exit(ft_printf(FLG_V_EXISTS));
		g_vm->flag->v += 1;
	}
}
