/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnv_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 22:57:18 by ishyian           #+#    #+#             */
/*   Updated: 2019/03/14 20:32:43 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static void		to_buf(t_ffmt *f, char *s, size_t len)
{
	char		w;

	ft_decrement(&f->prec, len);
	ft_decrement(&f->min_w, len + f->prec + 2);
	w = (f->zero && !f->minus) ? '0' : ' ';
	f->zero ? buf("0x", 2) : 0;
	f->min_w && !f->minus ? chr_to_buf(w, f->min_w) : 0;
	!f->zero ? buf("0x", 2) : 0;
	f->prec ? chr_to_buf('0', f->prec) : 0;
	buf(s, len);
	f->min_w && f->minus ? chr_to_buf(w, f->min_w) : 0;
}

void			cnv_p(t_ffmt *ffmt, va_list ap)
{
	size_t		p;
	size_t		len;
	char		*s;

	p = va_arg(ap, size_t);
	s = ft_ulltoa_base(p, 16);
	len = ft_strlen(s);
	if (ffmt->min_w > len + 2 || ffmt->prec > len)
		to_buf(ffmt, s, len);
	else
	{
		buf("0x", 2);
		if (!(p == 0 && ffmt->is_prec && ffmt->prec == 0))
			buf(s, len);
	}
	free(s);
}
