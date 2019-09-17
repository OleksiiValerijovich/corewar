/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 18:42:55 by ishyian           #+#    #+#             */
/*   Updated: 2019/03/12 21:03:31 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;

	g_size = 0;
	if (format)
	{
		g_fd = 1;
		if (ft_strchr(format, '%'))
		{
			va_start(ap, format);
			parser(format, ap);
		}
		else
			ft_printmem_fd(format, (g_size = ft_strlen(format)), g_fd);
	}
	return (g_size);
}
