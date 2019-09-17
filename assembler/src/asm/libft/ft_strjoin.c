/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:27:05 by ishyian           #+#    #+#             */
/*   Updated: 2018/11/29 20:59:53 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (s1 != NULL && s2 != NULL)
	{
		s3 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
		if (s3 == NULL)
			return (s3);
		ft_strcpy(s3, s1);
		ft_strcpy(s3 + ft_strlen(s1), s2);
		return (s3);
	}
	return (NULL);
}
