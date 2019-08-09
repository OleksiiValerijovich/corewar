/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 09:40:36 by aturuk            #+#    #+#             */
/*   Updated: 2018/11/02 15:18:40 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*s;

	s = (char *)malloc(sizeof(*s) * (ft_strlen(str) + 1));
	if (s == 0)
		return (NULL);
	else
		ft_strcpy(s, str);
	return (s);
}
