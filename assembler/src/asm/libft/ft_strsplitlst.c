/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:39:17 by ishyian           #+#    #+#             */
/*   Updated: 2018/12/03 16:36:29 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static void		split_to_list(size_t i, size_t len, t_list **s_list,
							const char *s)
{
	char		buf[len + 1];
	t_list		*tmp;

	ft_strncpy(buf, s + i - len, len);
	buf[len] = '\0';
	tmp = ft_lstnew(buf, len + 1);
	if (tmp == NULL)
		ft_lstdel(s_list, ft_memsdel);
	else if (*s_list == NULL)
		*s_list = tmp;
	else
		ft_lstaddend(s_list, tmp);
}

t_list			*ft_strsplitlst(char const *s, char c)
{
	t_list		*s_list;
	size_t		i;
	size_t		len;

	if (s == NULL)
		return (NULL);
	s_list = NULL;
	i = 0;
	if ((ft_strcountfields(s, c) != 0))
		while (s[i] != '\0')
		{
			while (s[i] == c)
				i++;
			len = 0;
			while (s[i] != c && s[i] != '\0' && ++len)
				i++;
			split_to_list(i, len, &s_list, s);
			if (s_list == NULL)
				return (NULL);
		}
	else
		s_list = ft_lstnew(s_list, 243);
	return (s_list);
}
