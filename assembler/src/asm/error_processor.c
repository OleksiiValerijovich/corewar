/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_processor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:10:29 by ishyian           #+#    #+#             */
/*   Updated: 2019/08/09 19:58:52 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm/asm.h"

static void	type_error(int *state, char *str)
{
	if (*state == -1)
		usage();
	else if (*state == -2)
		ft_printf("Can't open file: %s\n", str);
	else if (*state == -3)
		ft_printf("Can't read from file: %s\n", str);
	else if (*state == -4)
		ft_printf("File is not regular: %s\n", str);
	else if (*state == -5)
	{
		ft_printf("No file specified.\n");
		usage();
	}
	else if (*state == -6)
	{
		ft_printf("Wrong flag\n");
		usage();
	}
	else if (*state == -7)
		ft_printf("");
}

void		error_processor(int *state, char *str)
{
	if (*state != -1)
		ft_printf("%{red}yERROR%{normal}y (%{bold}y%hd%{normal}y): ", *state);
	type_error(state, str);
	ft_putchar('\n');
}
