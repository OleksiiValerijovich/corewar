/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:05:30 by ishyian           #+#    #+#             */
/*   Updated: 2019/03/14 20:23:54 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <string.h>

size_t			ft_wstrlen(const wchar_t *ws)
{
	size_t		len;

	len = 0;
	while (ws && *ws != L'\0')
	{
		len++;
		ws++;
	}
	return (len);
}
