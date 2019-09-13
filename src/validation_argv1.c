/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_argv1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:01:49 by aturuk            #+#    #+#             */
/*   Updated: 2019/08/06 12:01:50 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm/corewar_vm.h"

static void	check_flag_n(char **av, int *i)
{
	int		tmp_i;
	int		n;

	tmp_i = *i;
	while (av[tmp_i])
	{
		if (!(ft_strcmp(av[tmp_i], "-n")))
		{
			if ((!(av[tmp_i + 1]) || av[tmp_i + 1][0] == '-' || av[tmp_i + 1][0]
			== '0' || !(is_positive_int(av[tmp_i + 1])) || (n =
			ft_atoi(av[tmp_i += 1])) < 1 || n > 4 || g_vm->bot[n - 1].argv))
				error_exit(ft_printf(FLG_N_INVAL));
			if (!(av[tmp_i += 1]) ||
			ft_strcmp(&(av[tmp_i][ft_strlen(av[tmp_i]) - 4]), ".cor"))
				error_exit(ft_printf(CHAMP_INVAL));
			g_vm->bot[n - 1].num = n;
			g_vm->bot[n - 1].argv = av[tmp_i];
			g_vm->num_bot += 1;
		}
		tmp_i++;
	}
	g_vm->flag->n += 1;
}

static void	check_champions(char **av, int *i)
{
	int		n;

	!(g_vm->flag->n) ? check_flag_n(av, i) : 0;
	if (!(ft_strcmp(av[*i], "-n")))
		*i += 2;
	else
	{
		if (ft_strcmp(&(av[*i][ft_strlen(av[*i]) - 4]), ".cor"))
			error_exit(ft_printf(CHAMP_INVAL));
		n = 0;
		while (g_vm->bot[n].argv)
			n++;
		n == 4 || g_vm->num_bot > 3 ? error_exit(ft_printf(CHAMP_MAX)) : 0;
		g_vm->bot[n].num = n + 1;
		g_vm->bot[n].argv = av[*i];
		g_vm->num_bot += 1;
	}
}

static void	check_position(void)
{
	int		i;

	if (!(g_vm->num_bot))
		error_exit(ft_printf(CHAMP_INVAL));
	i = 0;
	while (g_vm->bot[i].argv)
		i++;
	if (i < g_vm->num_bot)
		error_exit(ft_printf(CHAMP_INVAL));
	if (g_vm->flag->v && (g_vm->flag->a || g_vm->flag->dump || g_vm->flag->m ||
		g_vm->flag->l || g_vm->flag->i != -1))
		error_exit(ft_printf(FLG_V_AND_OTHER, FLG_V_AND_OTHER2));
}

void		validation_argv(int ac, char **av)
{
	int		i;

	if (!(g_vm->flag = (t_flag *)ft_memalloc(sizeof(t_flag))))
		error_exit(ft_printf(MEMORY));
	g_vm->flag->i = -1;
	i = 0;
	while (++i < ac)
	{
		if (!(ft_strcmp(av[i], "-dump")))
			check_flag_dump(av, &i);
		else if (!(ft_strcmp(av[i], "-i")) || !(ft_strcmp(av[i], "-l")))
			check_flag_i_l(av, &i);
		else if (!(ft_strcmp(av[i], "-v")) || !(ft_strcmp(av[i], "-a")) ||
			!(ft_strcmp(av[i], "-lld_size")) || !(ft_strcmp(av[i], "-m")))
			check_flags_v_a_lld_m(av, &i);
		else if (ft_strstr(av[i], ".cor") || !(ft_strcmp(av[i], "-n")))
			check_champions(av, &i);
		else
			error_exit(ft_printf(ARGV_INVAL));
	}
	check_position();
}
