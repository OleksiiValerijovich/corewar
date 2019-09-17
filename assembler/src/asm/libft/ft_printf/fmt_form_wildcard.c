/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_form_wildcard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:41:06 by ishyian           #+#    #+#             */
/*   Updated: 2019/03/13 21:31:28 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

const char		*fmt_form_wildcard(const char *fmt, t_ffmt *ffmt, va_list ap)
{
	int		dig;

	dig = va_arg(ap, int);
	if (*(fmt - 1) == '.')
	{
		ffmt->prec = dig >= 0 ? dig : 0;
		ffmt->is_prec = dig >= 0 ? 1 : 0;
	}
	else if (*(fmt - 1) == ':')
	{
		ffmt->is_len = 1;
		ffmt->len = ABS(dig);
	}
	else
	{
		if (dig < 0)
			ffmt->minus = 1;
		ffmt->min_w = ABS(dig);
		ffmt->is_min_w = 1;
	}
	return (fmt);
}
