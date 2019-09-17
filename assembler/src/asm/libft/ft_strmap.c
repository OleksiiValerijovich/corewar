/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:34:46 by ishyian           #+#    #+#             */
/*   Updated: 2018/12/02 22:59:18 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t		i;
	char		*str;

	if (s != NULL && f != NULL)
	{
		i = 0;
		str = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (str != NULL)
		{
			while (s[i] != '\0')
			{
				str[i] = f(s[i]);
				i++;
			}
			str[i] = '\0';
		}
		return (str);
	}
	return (NULL);
}
