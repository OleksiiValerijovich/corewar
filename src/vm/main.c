/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:56:17 by okherson          #+#    #+#             */
/*   Updated: 2019/08/01 18:59:22 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm/corewar_vm.h"

static void	print_usage(void)
{
	ft_printf("Usage: ./corewar [-dump <nbr_cycles> -p <nbr_cycles> -i <nbr>" \
	", | -b | -v ] <champion1.cor> [ -n <nbr> ] <champion2.cor> <...>\n");
	ft_printf("  %s% 9c %s\n", "-n <number>", ':',
		"Sets the number of the next player");
	ft_printf("#### TEXT OUTPUT MODE " \
		"##########################################################\n");
	ft_printf("  %s% 2c %s\n", "-dump <nbr_cycles>", ':',
		"Dumps memory after nbr_cycles, then exits");
	ft_printf("  %s% 5c %s\n", "-p <nbr_cycles>", ':',
		"Runs nbr_cycles, dumps memory, pauses, then repeats");
	ft_printf("  %s% 12c %s\n", "-i <nbr>", ':', "Prints info");
	ft_printf("% 36s\n", "- 0 : No info");
	ft_printf("% 40s\n", "- 1 : Show cycles");
	ft_printf("% 39s\n", "- 2 : Show lives");
	ft_printf("% 52s\n", "- 3 : Show number of carriage");
	ft_printf("% 40s\n", "- 4 : Show deaths");
	ft_printf("#### BINARY OUTPUT MODE " \
		"########################################################\n");
	ft_printf("  %s% 18c %s\n", "-b", ':', "Binary output mode");
	ft_printf("#### NCURSES OUTPUT MODE " \
		"#######################################################\n");
	ft_printf("  %s% 18c %s\n", "-v", ':', "Ncurses output mode");
	ft_printf("###################################################" \
		"#############################\n");
	exit(0);
}

void		error_exit(int i)
{
	i = 0;
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
	war();
	if (g_vm)
	return (0);
}
