/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlogfilefd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:39:21 by ishyian           #+#    #+#             */
/*   Updated: 2019/06/24 12:06:33 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

int					ft_getlogfilefd(void)
{
	static int		fd;

	if (!fd)
		fd = open("log", O_CREAT | O_RDWR, 0775);
	return (fd);
}
