/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:03:48 by ishyian           #+#    #+#             */
/*   Updated: 2018/11/29 21:24:01 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s != NULL)
	{
		str = (char*)malloc(len + 1);
		if (str == NULL)
			return (str);
		ft_strncpy(str, s + start, len);
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
