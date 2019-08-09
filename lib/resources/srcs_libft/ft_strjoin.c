/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 10:40:57 by aturuk            #+#    #+#             */
/*   Updated: 2018/11/13 10:18:37 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *s;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 != NULL && s2 == NULL)
		s = ft_strdup(s1);
	else if (s1 == NULL && s2 != NULL)
		s = ft_strdup(s2);
	else
	{
		s = (char *)malloc(sizeof(*s) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (s == 0)
			return (NULL);
		ft_strcpy(s, s1);
		ft_strcat(s, s2);
	}
	return (s);
}
