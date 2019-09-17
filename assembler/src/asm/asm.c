/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:00:30 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/17 12:11:59 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../../inc/asm/asm.h"

static void		argv_cycle(int argc, char **argv)
{
	int			i;

	i = 1;
	while (i < argc)
	{
		if (!process_flag(argv[i]))
			break ;
		i++;
	}
	if (i == argc && g_state == 0)
		g_state = -5;
	else if (g_state == 0)
		while (i < argc)
		{
			process_file(argv[i]);
			i++;
		}
}

int				main(int argc, char **argv)
{
	g_state = 0;
	ft_bzero(&g_data, sizeof(t_data));
	ft_bzero(&g_flags, sizeof(t_flags));
	if (argc == 1)
		g_state = -1;
	else
		argv_cycle(argc, argv);
	if (g_state < 0)
		error_processor(&g_state, NULL);
	return (0);
}
