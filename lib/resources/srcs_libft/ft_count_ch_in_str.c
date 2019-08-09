/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_ch_in_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:49:56 by aturuk            #+#    #+#             */
/*   Updated: 2019/05/03 14:49:59 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_ch_in_str(char *s, char ch)
{
	int i;
	int count_ch;

	i = -1;
	count_ch = 0;
	if (s)
	{
		while (s[++i] != '\0')
			if (s[i] == ch)
				count_ch++;
	}
	return (count_ch);
}
