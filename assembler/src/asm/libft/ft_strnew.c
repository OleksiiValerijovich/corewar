/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:50:38 by ishyian           #+#    #+#             */
/*   Updated: 2018/12/02 23:01:18 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char		*str;
	size_t		i;

	i = 0;
	if ((str = (char*)malloc(sizeof(char) * size + 1)))
	{
		while (i <= size)
			str[i++] = '\0';
		return (str);
	}
	return (NULL);
}
