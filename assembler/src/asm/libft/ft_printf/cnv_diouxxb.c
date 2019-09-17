/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnv_diouxXb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:52:08 by ishyian           #+#    #+#             */
/*   Updated: 2019/03/14 22:25:34 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static void			to_buf(t_ffmt *f, char *s, size_t len)
{
	char		w;

	w = (f->zero && !f->minus && !f->is_prec) ? '0' : ' ';
	ft_decrement(&f->prec, len);
	ft_decrement(&f->min_w, len + f->prec);
	(f->sharp && (ft_strchr("xXb", f->cnv))) ? ft_decrement(&f->min_w, 2) : 0;
	(f->sharp && f->cnv == 'o' && !f->prec) ? ft_decrement(&f->min_w, 1) : 0;
	(f->plus || f->space || f->num_neg) ? ft_decrement(&f->min_w, 1) : 0;
	(f->zero && f->num_neg && ft_strchr("di", f->cnv)) ? buf("-", 1) : 0;
	(!f->minus && f->min_w && w == ' ') ? chr_to_buf(w, f->min_w) : 0;
	(f->zero && f->plus && ft_strchr("di", f->cnv)) ? buf("+", 1) : 0;
	(f->space && ft_strchr("di", f->cnv)) ? buf(" ", 1) : 0;
	(f->sharp && f->cnv == 'x') ? buf("0x", 2) : 0;
	(f->sharp && f->cnv == 'X') ? buf("0X", 2) : 0;
	(f->sharp && f->cnv == 'o' && !f->prec) ? buf("0", 1) : 0;
	(f->sharp && f->cnv == 'b') ? buf("0b", 2) : 0;
	(!f->zero && f->num_neg && ft_strchr("di", f->cnv)) ? buf("-", 1) : 0;
	(!f->zero && f->plus && ft_strchr("di", f->cnv)) ? buf("+", 1) : 0;
	(!f->minus && f->min_w && w == '0') ? chr_to_buf(w, f->min_w) : 0;
	(f->prec) ? chr_to_buf('0', f->prec) : 0;
	buf(s, len);
	(f->minus && f->min_w) ? chr_to_buf(w, f->min_w) : 0;
}

static char			*get_str(t_ffmt *ffmt, long long nb)
{
	char		*s;

	if (ffmt->cnv == 'b')
		s = ft_ulltoa_base(nb, 2);
	else if (ffmt->cnv == 'o')
		s = ft_ulltoa_base(nb, 8);
	else if (ft_strchr("xX", ffmt->cnv))
		s = ft_ulltoa_base(nb, 16);
	else if (ffmt->cnv == 'u')
		s = ft_ulltoa(nb);
	else
		s = ft_lltoa(nb);
	if (ffmt->cnv == 'X')
		ft_strtoupper(s);
	return (s);
}

static long long	get_nbr(t_ffmt *ffmt, va_list ap)
{
	if (ffmt->ll && ft_strchr("di", ffmt->cnv))
		return ((long long)va_arg(ap, long long));
	else if (ffmt->ll && ft_strchr("ouxXb", ffmt->cnv))
		return ((unsigned long long)va_arg(ap, unsigned long long));
	else if ((ffmt->l || ffmt->z || ffmt->j) && ft_strchr("di", ffmt->cnv))
		return ((long)va_arg(ap, long));
	else if ((ffmt->l || ffmt->z || ffmt->j) && ft_strchr("ouxXb", ffmt->cnv))
		return ((unsigned long)va_arg(ap, unsigned long));
	else if (ffmt->h && ft_strchr("di", ffmt->cnv))
		return ((short)va_arg(ap, int));
	else if (ffmt->h && ft_strchr("ouxXb", ffmt->cnv))
		return ((unsigned short)va_arg(ap, unsigned int));
	else if (ffmt->hh && ft_strchr("di", ffmt->cnv))
		return ((char)va_arg(ap, int));
	else if (ffmt->hh && ft_strchr("ouxXb", ffmt->cnv))
		return ((unsigned char)va_arg(ap, unsigned int));
	else if (ft_strchr("di", ffmt->cnv))
		return ((int)va_arg(ap, int));
	else
		return ((unsigned int)va_arg(ap, unsigned int));
}

void				cnv_diouxxb(t_ffmt *ffmt, va_list ap)
{
	long long	nb;
	size_t		len;
	char		*s;

	nb = get_nbr(ffmt, ap);
	if (nb < 0 && !ft_strchr("ouxXb", ffmt->cnv))
	{
		ffmt->num_neg = 1;
		ffmt->space = 0;
		ffmt->plus = 0;
	}
	if ((nb == 0 && !ffmt->is_prec) || (nb == 0 && ft_strchr("xX", ffmt->cnv)))
		ffmt->sharp = 0;
	s = get_str(ffmt, nb);
	len = ft_strlen(s);
	if (ffmt->is_prec && ffmt->prec == 0 && nb == 0)
		len = 0;
	if ((nb == 0 && ffmt->is_prec && ffmt->prec == 0 && ffmt->cnv != 'o'))
		ffmt->sharp = 0;
	ffmt->num_neg ? to_buf(ffmt, s + 1, --len) : to_buf(ffmt, s, len);
	free(s);
}
