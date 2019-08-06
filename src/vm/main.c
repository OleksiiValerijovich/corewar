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

int			main(int argc, char **argv)
{

	ft_printf("test !!!! \n");
	if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		ft_printf(DOESNT_CREATE_VM);
//    validation_argv(argc, argv);
    validation_bin_bot();

    if (argc > 2)
    	ft_printf("%s\n", argv[1]);
	return (0);
}
