/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_exec_code.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 02:04:54 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 15:24:41 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm/asm.h"

void		display_exec_code(void)
{
	ft_printf("Exec code size: %{green}y%d%{normal}y\n", g_data.exec_size);
}
