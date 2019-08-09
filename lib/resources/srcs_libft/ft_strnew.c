/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 10:45:11 by aturuk            #+#    #+#             */
/*   Updated: 2018/11/07 15:40:33 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *snew;

	if ((snew = (char *)malloc(sizeof(*snew) * (size + 1))) == 0)
		return (NULL);
	ft_bzero(snew, size + 1);
	return (snew);
}
