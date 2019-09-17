/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlongestwordlen.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:30:21 by ishyian           #+#    #+#             */
/*   Updated: 2018/12/03 16:42:28 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strlongestwordlen(char const *s)
{
	size_t		i;
	size_t		cur_len;
	size_t		max_len;

	i = 0;
	max_len = 0;
	while (s != NULL && s[i] != '\0')
	{
		while (ft_isspace(s[i]))
			i++;
		cur_len = 0;
		while (!ft_isspace(s[i]) && s[i] != '\0')
		{
			cur_len++;
			i++;
		}
		if (cur_len > max_len)
			max_len = cur_len;
	}
	return (max_len);
}
