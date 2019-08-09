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

#include "../../includes/vm/corewar_vm.h"

static void	check_flag_n(char **av, int *i)
{
	int		tmp_i;
	int		n;

	tmp_i = *i;
	while (av[tmp_i])
	{
		if (!(ft_strcmp(av[tmp_i], "-n")))
		{
			if ((!(av[tmp_i + 1]) || av[tmp_i + 1][0] == '-' ||
			av[tmp_i + 1][0] == '0' || !(is_positive_int(av[tmp_i + 1])) ||
			(n = ft_atoi(av[tmp_i += 1])) < 1 || n > 4 || vm->bot[n - 1].argv))
				error_exit(ft_printf(FLG_N_INVAL));
			if (!(av[tmp_i += 1]) ||
			ft_strcmp(&(av[tmp_i][ft_strlen(av[tmp_i]) - 4]), ".cor"))
				error_exit(ft_printf(CHAMP_INVAL));
			vm->bot[n - 1].num = n;
			vm->bot[n - 1].argv = av[tmp_i];
			vm->num_bot += 1;
		}
		tmp_i++;
	}
	vm->flag->n += 1;
}

static void	check_champions(char **av, int *i)
{
	int		n;

	!(vm->flag->n) ? check_flag_n(av, i) : 0;
	if (!(ft_strcmp(av[*i], "-n")))
		*i += 2;
	else
	{
		if (ft_strcmp(&(av[*i][ft_strlen(av[*i]) - 4]), ".cor"))
			error_exit(ft_printf(CHAMP_INVAL));
		n = 0;
		while (vm->bot[n].argv)
			n++;
		n == 4 || vm->num_bot > 3 ? error_exit(ft_printf(CHAMP_MAX)) : 0;
		vm->bot[n].num = n + 1;
		vm->bot[n].argv = av[*i];
		vm->num_bot += 1;
	}
}

static void	check_position(void)
{
	int		i;

	if (vm->flag->v && vm->flag->b)
		error_exit(ft_printf(FLG_V_AND_B));
	if (vm->flag->p && !(vm->flag->v))
		error_exit(ft_printf(FLG_V_AND_P));
	if (vm->flag->dump && vm->flag->p)
		error_exit(ft_printf(FLG_DUMP_AND_P));
	if (!(vm->num_bot))
		error_exit(ft_printf(CHAMP_INVAL));
	i = 0;
	while (vm->bot[i].argv)
		i++;
	if (i < vm->num_bot)
		error_exit(ft_printf(CHAMP_INVAL));
}

void		validation_argv(int ac, char **av)
{
	int		i;

	if (!(vm->flag = (t_flag *)ft_memalloc(sizeof(t_flag))))
		error_exit(ft_printf(MEMORY));
	vm->flag->i = -1;
	i = 0;
	while (++i < ac)
	{
		if (!(ft_strcmp(av[i], "-dump")) || !(ft_strcmp(av[i], "-p")))
			check_flag_dump_p(av, &i);
		else if (!(ft_strcmp(av[i], "-i")))
			check_flag_i(av, &i);
		else if (!(ft_strcmp(av[i], "-b")) || !(ft_strcmp(av[i], "-v")))
			check_flags_b_v(av, &i);
		else if (ft_strstr(av[i], ".cor") || !(ft_strcmp(av[i], "-n")))
			check_champions(av, &i);
		else
			error_exit(ft_printf(ARGV_INVAL));
	}
	check_position();
}
