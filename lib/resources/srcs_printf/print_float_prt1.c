/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float_prt1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 09:24:45 by aturuk            #+#    #+#             */
/*   Updated: 2019/03/02 09:24:47 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	to_power(long long value, int pow)
{
	int copy_value;

	copy_value = value;
	while (pow > 1)
	{
		value *= copy_value;
		pow--;
	}
	return (value);
}

static int	check_nan_inf(t_lst *pf, long double d, char type)
{
	if (d != d)
	{
		ZERO_FLG = 0;
		pf->prec = -1;
		type == 'f' ? print_s(pf, "nan") : print_s(pf, "NAN");
		return (1);
	}
	if (d == 1.0 / 0.0 || (d < 0 && -d == 1.0 / 0.0))
	{
		ZERO_FLG = 0;
		pf->prec = -1;
		if (d < 0)
			type == 'f' ? print_s(pf, "-inf") : print_s(pf, "-INF");
		else
			type == 'f' ? print_s(pf, "inf") : print_s(pf, "INF");
		return (1);
	}
	return (0);
}

static char	*check_minus_zero(char *str, long double d)
{
	char	*ptr;

	if (d == 0.0 && 1.0 / (-d) == 1.0 / (0.0) && str[0] != '-')
	{
		ptr = str;
		str = ft_strjoin("-", ptr);
		free(ptr);
	}
	return (str);
}

void		print_f(t_lst *pf, long double d, char type)
{
	char *str;
	char sign;

	if (check_nan_inf(pf, d, type) == 1)
		return ;
	sign = d < 0 ? '-' : '+';
	if (d == 0.0 && 1.0 / (-d) == 1.0 / (0.0))
		sign = '-';
	d = d < 0 && (PLUS_FLG != 0 || SPACE_FLG != 0 || ZERO_FLG != 0) ? -d : d;
	str = get_double_str(pf, d);
	str = check_plus_flag(pf, str, sign);
	str = check_space_flag(pf, str, sign);
	if (ZERO_FLG == '0' && sign == '-' && !(PLUS_FLG != 0 || SPACE_FLG != 0))
	{
		write(1, "-", 1);
		pf->width -= pf->width > 0 ? 1 : 0;
		pf->len_out += 1;
	}
	else
		str = check_minus_zero(str, d);
	print_s(pf, str);
	free(str);
}
