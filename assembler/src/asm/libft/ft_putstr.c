/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:04:09 by ishyian           #+#    #+#             */
/*   Updated: 2018/12/03 18:13:52 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_putstr(const char *str)
{
	size_t		i;

	i = 0;
	while (str != NULL && str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}
