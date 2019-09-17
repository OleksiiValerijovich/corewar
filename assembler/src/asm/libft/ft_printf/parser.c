/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 20:45:14 by ishyian           #+#    #+#             */
/*   Updated: 2019/03/14 16:30:53 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static void			arg_output(const char **fmt, t_ffmt *ffmt, va_list ap)
{
	if (!ffmt->cnv)
		cnv_noncnv(fmt, ffmt);
	else if (ft_strchr("c%", ffmt->cnv))
		cnv_c(ffmt, ap);
	else if (ffmt->cnv == 's')
		cnv_s(ffmt, ap);
	else if (ffmt->cnv == 'p')
		cnv_p(ffmt, ap);
	else if (ft_strchr("diouxXb", ffmt->cnv))
		cnv_diouxxb(ffmt, ap);
	else if (ft_strchr("fF", ffmt->cnv))
		cnv_f(ffmt, ap);
	else if (ffmt->cnv == 'y')
		cnv_tfmt(ffmt);
}

static const char	*format_parcer(const char *fmt, va_list ap)
{
	t_ffmt		ffmt;

	ft_bzero(&ffmt, sizeof(t_ffmt));
	fmt = fmt_formalizer(fmt, &ffmt, ap);
	arg_output(&fmt, &ffmt, ap);
	return (fmt);
}

static const char	*string_output(const char *fmt)
{
	size_t		to_print;
	char		*prcnt;

	if ((prcnt = ft_strchr(fmt, '%')))
		to_print = prcnt - fmt;
	else
		to_print = ft_strlen(fmt);
	buf(fmt, to_print);
	return (fmt + to_print);
}

void				parser(const char *fmt, va_list ap)
{
	while (*fmt)
	{
		if (*fmt == '%')
			fmt = format_parcer(fmt + 1, ap);
		fmt = string_output(fmt);
	}
	buf_print();
	va_end(ap);
}
