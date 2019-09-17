/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 21:55:14 by ishyian           #+#    #+#             */
/*   Updated: 2019/03/14 21:56:33 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void		print(const void *s, size_t size)
{
	if (s)
	{
		g_size += size;
		ft_printmem_fd(s, size, g_fd);
	}
}
