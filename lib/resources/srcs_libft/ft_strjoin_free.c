/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:14:44 by aturuk            #+#    #+#             */
/*   Updated: 2018/11/13 10:21:37 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char *s;

	s = ft_strjoin((char const *)s1, (char const *)s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (s);
}
