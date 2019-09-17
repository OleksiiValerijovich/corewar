/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:25:43 by ishyian           #+#    #+#             */
/*   Updated: 2019/05/24 15:51:06 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static void		split_to_array(size_t *i, const char *s,
							char c, char **splitted)
{
	size_t		len;

	len = 0;
	if (s[i[0]] != c && s[i[0]] != '\0')
	{
		while (s[i[0]] != c && s[i[0]] != '\0' && ++len)
			i[0]++;
		splitted[i[1]] = (char*)malloc(sizeof(char) * len + 1);
		ft_strncpy(splitted[i[1]], s + i[0] - len, len);
		splitted[i[1]][len] = '\0';
		i[1]++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char		**splitted;
	size_t		i[2];

	if (s == NULL)
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	splitted = (char**)malloc(sizeof(char*) * (ft_strcountfields(s, c) + 1));
	while (s[i[0]] != '\0' && splitted != NULL)
	{
		while (s[i[0]] == c)
			i[0]++;
		split_to_array(i, s, c, splitted);
	}
	if (s[i[0]] == '\0')
		splitted[i[1]] = NULL;
	return (splitted);
}
