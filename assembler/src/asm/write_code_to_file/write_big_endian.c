/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_big_endian.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 02:16:54 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 02:39:20 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		write_big_endian(int fd, void *data, size_t size)
{
	while (size--)
	{
		write(fd, &data[size], 1);
	}
}
