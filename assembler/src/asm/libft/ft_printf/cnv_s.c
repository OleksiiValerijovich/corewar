/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnv_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:55:31 by ishyian           #+#    #+#             */
/*   Updated: 2019/03/14 21:06:44 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static size_t	get_len(t_ffmt *ffmt, const void *s)
{
	if (s)
	{
		if (ffmt->is_len)
			return (ffmt->len);
		if (!ffmt->l)
			return (ft_strlen(s));
		else
			return (ft_wstrsumlen(s));
	}
	return (ft_strlen("(null)"));
}

static void		to_buf(t_ffmt *ffmt, const void *s, size_t len)
{
	char	w;

	w = ffmt->zero && !ffmt->minus ? '0' : ' ';
	ft_decrement(&ffmt->min_w, len);
	if (!ffmt->minus)
		chr_to_buf(w, ffmt->min_w);
	if (s)
	{
		if (ffmt->l)
			wstr_to_buf(s, MB_CUR_MAX, len);
		else
			buf(s, len);
	}
	else
		buf("(null)", len);
	if (ffmt->minus)
		chr_to_buf(w, ffmt->min_w);
}

void			cnv_s(t_ffmt *ffmt, va_list ap)
{
	const void		*s;
	size_t			len;

	s = va_arg(ap, void *);
	len = get_len(ffmt, s);
	if (ffmt->is_prec)
		len = len > ffmt->prec ? ffmt->prec : len;
	to_buf(ffmt, s, len);
}
