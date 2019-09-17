/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:03:32 by ishyian           #+#    #+#             */
/*   Updated: 2018/12/02 22:34:00 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	size_t		i;

	i = -1;
	while (s != NULL && fd != -1 && s[++i] != '\0')
		ft_putchar_fd(s[i], fd);
}
