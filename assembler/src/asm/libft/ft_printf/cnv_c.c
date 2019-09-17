/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnv_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 23:10:03 by ishyian           #+#    #+#             */
/*   Updated: 2019/03/14 21:01:05 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static void		to_buf(t_ffmt *ffmt, wchar_t wc)
{
	char		w;

	w = (ffmt->zero && !ffmt->minus) ? '0' : ' ';
	if (!ffmt->minus)
		chr_to_buf(w, ffmt->min_w);
	if (ffmt->l)
		wchr_to_buf(wc, MB_CUR_MAX);
	else
		buf(&wc, 1);
	if (ffmt->minus)
		chr_to_buf(w, ffmt->min_w);
}

void			cnv_c(t_ffmt *ffmt, va_list ap)
{
	wchar_t			wc;

	wc = ffmt->cnv == '%' ? '%' : va_arg(ap, int);
	if (ffmt->l)
	{
		if ((wc < 128 && MB_CUR_MAX >= 1) || MB_CUR_MAX == 1)
			ft_decrement(&ffmt->min_w, 1);
		else if ((wc > 127 && wc < 2048 && MB_CUR_MAX >= 2)
				|| (wc > 2047 && MB_CUR_MAX == 2))
			ft_decrement(&ffmt->min_w, 2);
		else if ((wc > 2047 && wc < 65536 && MB_CUR_MAX >= 3)
				|| (wc > 65535 && MB_CUR_MAX == 3))
			ft_decrement(&ffmt->min_w, 3);
		else if (wc < 2097151 && MB_CUR_MAX >= 4)
			ft_decrement(&ffmt->min_w, 4);
	}
	else
		ft_decrement(&ffmt->min_w, 1);
	if (ffmt->min_w)
		to_buf(ffmt, wc);
	else if (ffmt->l)
		wchr_to_buf(wc, MB_CUR_MAX);
	else
		buf(&wc, 1);
}
