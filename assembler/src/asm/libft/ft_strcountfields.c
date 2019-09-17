/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountfields.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:26:09 by ishyian           #+#    #+#             */
/*   Updated: 2018/12/03 16:41:10 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strcountfields(char const *s, char delim)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (s != NULL && s[i] != '\0')
	{
		while (s[i] == delim)
			i++;
		if (s[i] != delim && s[i] != '\0')
		{
			count++;
			while (s[i] != delim && s[i] != '\0')
				i++;
		}
	}
	return (count);
}
