/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:47:31 by ishyian           #+#    #+#             */
/*   Updated: 2018/12/02 23:00:16 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		ii;

	i = 0;
	ii = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[ii] != '\0' && ii < n)
	{
		s1[i] = s2[ii];
		i++;
		ii++;
	}
	s1[i] = '\0';
	return (s1);
}
