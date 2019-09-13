/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 09:14:05 by aturuk            #+#    #+#             */
/*   Updated: 2019/08/23 09:14:06 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm/corewar_vm.h"

static void	print_usage2(void)
{
	ft_printf("  %s% 12c %s\n", "-i <nbr>", ':', "Prints info");
	ft_printf("% 43s\n", "- 0 : Show only winner");
	ft_printf("% 38s\n", "- 1 : Show cycles");
	ft_printf("% 59s\n", "- 2 : Show introducing, winner and map");
	ft_printf("% 46s\n", "- 3 : Show carriage death");
	ft_printf("% 46s\n", "- 4 : Show all operations");
	ft_printf("#### NCURSES OUTPUT MODE " \
		"#######################################################\n");
	ft_printf("  %s% 18c %s\n", "-v", ':', "Ncurses output mode");
	ft_printf("###################################################" \
		"#############################\n");
	exit(0);
}

static void	print_usage(void)
{
	ft_printf("Usage: ./corewar [-dump <nbr_cycles> -i <nbr>" \
	", | -a | -lld_size |\n       -m | -l |-v ] <champion1.cor> [ -n <nbr> ]" \
	" <champion2.cor> <...>\n");
	ft_printf("###################################################" \
		"#############################\n");
	ft_printf("  %s% 9c %s\n", "-n <number>", ':',
		"Sets the number of the next player");
	ft_printf("  %s% 18c %s\n", "-a", ':', "Prints output from 'aff'");
	ft_printf("  %s% 11c %s\n", "-lld_size", ':', "Sets arg_size = 2 " \
		"for T_IND in operation lld (as original)");
	ft_printf("#### TEXT OUTPUT MODE " \
		"##########################################################\n");
	ft_printf("  %s% 2c %s\n", "-dump <nbr_cycles>", ':',
		"Dumps memory after nbr_cycles, then exits");
	ft_printf("  %s% 18c %s\n", "-m", ':', "Print map with 64 octets " \
		"per line (as original)");
	ft_printf("  %s% 18c %s\n", "-l", ':', "Show leaks");
	print_usage2();
}

void		error_exit(int i)
{
	i = 0;
	g_vm->flag->l ? system("leaks -q corewar") : 0;
	exit(0);
}

int			main(int argc, char **argv)
{
	if (argc == 1)
		print_usage();
	if (!(g_vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		error_exit(ft_printf(MEMORY));
	validation_argv(argc, argv);
	validation_bin_bot();
	map_initialization();
	if (g_vm->flag->v != 0)
		init_vz();
	war();
	g_vm->flag->l ? system("leaks -q corewar") : 0;
	return (0);
}
