/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_form_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:12:12 by ishyian           #+#    #+#             */
/*   Updated: 2019/03/13 21:31:07 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

const char		*fmt_form_digit(const char *fmt, t_ffmt *ffmt)
{
	long long	dig;
	short		len;

	dig = ft_atoll(fmt);
	len = ft_numlen(dig);
	if (*(fmt - 1) == '.')
	{
		ffmt->prec = dig;
		ffmt->is_prec = 1;
	}
	else if (*(fmt - 1) == ':')
	{
		ffmt->is_len = 1;
		ffmt->len = dig;
	}
	else
	{
		ffmt->min_w = dig;
		ffmt->is_min_w = 1;
	}
	return (fmt + len - 1);
}
