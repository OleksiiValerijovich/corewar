/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:14:42 by ishyian           #+#    #+#             */
/*   Updated: 2018/12/02 22:55:27 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t		i;

	if (s != NULL && fd != -1)
	{
		i = -1;
		while (s[++i] != '\0')
			ft_putchar_fd(s[i], fd);
		ft_putchar_fd('\n', fd);
	}
}
