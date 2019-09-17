/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_formalizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:57:44 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/07 16:06:17 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static void			check(t_ffmt *ffmt)
{
	if (ft_strchr("SCDOU", ffmt->cnv))
	{
		ffmt->l = 1;
		ffmt->cnv = ffmt->cnv + ('a' - 'A');
	}
	if (ft_strchr("ouxXb", ffmt->cnv) && (ffmt->plus || ffmt->space))
	{
		ffmt->plus = 0;
		ffmt->space = 0;
	}
	else if (ffmt->space && ffmt->plus)
		ffmt->space = 0;
}

static const char	*flag_parcer_(const char *fmt, t_ffmt *ffmt, va_list ap)
{
	if (*fmt == 'r')
		ffmt->r = 1;
	else if (*fmt == 'z')
		ffmt->z = 1;
	else if (*fmt == 'j')
		ffmt->j = 1;
	else if (*fmt == '.')
		ffmt->is_prec = 1;
	else if (ft_isdigit(*fmt))
		fmt = fmt_form_digit(fmt, ffmt);
	else if (*fmt == '*')
		fmt = fmt_form_wildcard(fmt, ffmt, ap);
	else if (*fmt == '{')
		fmt = fmt_form_tfmt(fmt, ffmt);
	return (fmt);
}

static const char	*flag_parcer(const char *fmt, t_ffmt *ffmt, va_list ap)
{
	if (*fmt == '#')
		ffmt->sharp = 1;
	else if (*fmt == '-')
		ffmt->minus = 1;
	else if (*fmt == '+')
		ffmt->plus = 1;
	else if (*fmt == ' ')
		ffmt->space = 1;
	else if (*fmt == 'h' && *(fmt + 1) == 'h' && !ffmt->h && fmt++)
		ffmt->hh = 1;
	else if (*fmt == 'h')
		ffmt->h = 1;
	else if (*fmt == 'l' && *(fmt + 1) == 'l' && fmt++)
		ffmt->ll = 1;
	else if (*fmt == 'l')
		ffmt->l = 1;
	else if (*fmt == 'L')
		ffmt->uppl = 1;
	else if (*fmt == '0' && !ft_strchr(".:", *(fmt - 1))
			&& (!ft_isdigit(*(fmt - 1)) || *(fmt - 1) == '0'))
		ffmt->zero = 1;
	else
		fmt = flag_parcer_(fmt, ffmt, ap);
	return (++fmt);
}

const char			*fmt_formalizer(const char *fmt, t_ffmt *ffmt, va_list ap)
{
	while (*fmt && ft_strchr(VALID_CHRS, *fmt))
	{
		if (ft_strchr(CONVERSIONS, *fmt))
		{
			ffmt->cnv = *fmt;
			check(ffmt);
			return (fmt + 1);
		}
		fmt = flag_parcer(fmt, ffmt, ap);
	}
	return (fmt);
}
