/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 09:51:22 by aturuk            #+#    #+#             */
/*   Updated: 2018/11/08 10:12:03 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	int w;
	int i;

	w = 0;
	i = 0;
	if (s[0] != '\0' && s[0] != c)
		w++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			w++;
		i++;
	}
	return (w);
}

static char	*w_to_arr(const char *s, char c)
{
	char	*arr;
	int		len;
	int		i;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	if ((arr = (char *)malloc(sizeof(*arr) * (len + 1))) == 0)
		return (NULL);
	i = 0;
	while (i < len)
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		word;
	int		k;

	k = 0;
	if (s != 0)
	{
		word = ft_words(s, c);
		if ((split = (char **)malloc(sizeof(char *) * (word + 1))) == 0)
			return (NULL);
		while (*s != '\0')
		{
			if (*s == c)
				s++;
			if (*s != c && k < word)
			{
				split[k] = w_to_arr(s, c);
				s = s + ft_strlen(split[k]);
				k++;
			}
		}
		split[k] = NULL;
		return (split);
	}
	return (NULL);
}
