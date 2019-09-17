/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:40:38 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/24 15:40:49 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int		ft_fprintf(int fd, const char *format, ...)
{
	va_list		ap;

	g_size = 0;
	if (format)
	{
		g_fd = fd;
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
