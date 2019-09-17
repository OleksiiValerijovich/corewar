/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsumlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 18:16:46 by ishyian           #+#    #+#             */
/*   Updated: 2019/03/14 20:23:43 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <string.h>
#include "libft.h"

size_t			ft_wstrsumlen(const wchar_t *ws)
{
	size_t		len;

	len = 0;
	while (ws && *ws != L'\0')
	{
		len = len + ft_wchrlen(*ws);
		ws++;
	}
	return (len);
}
