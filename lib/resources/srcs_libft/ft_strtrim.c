/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 12:25:31 by aturuk            #+#    #+#             */
/*   Updated: 2018/11/12 14:15:34 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		e;
	char	*str;

	if (s == 0)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	e = (int)(ft_strlen(s) - 1);
	while (s[e] == ' ' || s[e] == '\n' || s[e] == '\t')
		e--;
	if (e >= i)
		str = ft_strsub(s, i, (e - i + 1));
	else
	{
		if ((str = (char *)malloc(sizeof(*str))) == 0)
			return (NULL);
		*str = '\0';
	}
	return (str);
}
