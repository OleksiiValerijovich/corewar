/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:03:09 by ishyian           #+#    #+#             */
/*   Updated: 2019/03/14 20:24:17 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static void		uchr_to_buf(const unsigned char c)
{
	buf(&c, 1);
}

void			wchr_to_buf(const wchar_t c, int max_size)
{
	if ((c < 128 && max_size >= 1) || (c >= 128 && max_size == 1))
		uchr_to_buf(c);
	else if ((c < 2048 && max_size >= 2) || (c >= 2048 && max_size == 2))
	{
		uchr_to_buf((c >> 6) + 0xc0);
		uchr_to_buf(((c & 0x3f) + 0x80));
	}
	else if ((c < 65536 && max_size >= 3) || (c >= 65536 && max_size == 3))
	{
		uchr_to_buf((c >> 12) + 0xe0);
		uchr_to_buf(((c >> 6) & 0x3f) + 0x80);
		uchr_to_buf((c & 0x3f) + 0x80);
	}
	else if ((c < 2097152 && max_size >= 4) || (c >= 2097152 && max_size >= 4))
	{
		uchr_to_buf((c >> 18) + 0xf0);
		uchr_to_buf(((c >> 12) & 0x3f) + 0x80);
		uchr_to_buf(((c >> 6) & 0x3f) + 0x80);
		uchr_to_buf((c & 0x3f) + 0x80);
	}
}

void			wstr_to_buf(const wchar_t *ws, int max_size, size_t len)
{
	size_t		i;

	i = 0;
	while (ws && *ws != L'\0' && (i = i + ft_wchrlen(*ws)) <= len)
	{
		wchr_to_buf(*ws, max_size);
		ws++;
	}
}
