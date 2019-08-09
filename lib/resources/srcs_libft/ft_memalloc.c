/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 10:27:30 by aturuk            #+#    #+#             */
/*   Updated: 2018/11/10 16:56:00 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *memarr;

	if (size == 0)
		return (NULL);
	memarr = malloc(size);
	if (memarr == 0)
		return (NULL);
	ft_memset(memarr, 0, size);
	return (memarr);
}
