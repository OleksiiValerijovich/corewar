/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 13:33:14 by ishyian           #+#    #+#             */
/*   Updated: 2019/08/05 15:40:58 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm/asm.h"

void		usage(void)
{
	ft_printf("Usage:\t");
	ft_printf("$>./asm <input_file>\n");
	ft_printf("\t$>./asm <input_file_0> <input_file_1> <input_file_n>\n");
}
