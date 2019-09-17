/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float_prt2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 09:25:15 by aturuk            #+#    #+#             */
/*   Updated: 2019/03/02 09:25:16 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*if_prec_zero(t_lst *pf, long double d)
{
	char	*s1;
	char	*ptr;

	if (d > 0 && (long long)(d * 10.0) % 10 > 4 &&
		(d - (long long)d > 0.50 || (long long)d % 2 != 0))
		d += 1;
	if (d < 0 && (long long)(-d * 10.0) % 10 > 4 &&
		(-d - (long long)-d > 0.50 || (long long)-d % 2 != 0))
		d -= 1;
	s1 = ft_long_long_itoa((long long)d);
	if (HASH_FLG != 0)
	{
		ptr = s1;
		s1 = ft_strjoin(ptr, ".");
		free(ptr);
	}
	return (s1);
}

static char	*get_first_part(t_lst *pf, long double d)
{
	char	*s1;
	char	*ptr;

	if (pf->prec == 0)
		s1 = if_prec_zero(pf, d);
	else
	{
		s1 = ft_long_long_itoa((long long)d);
		ptr = s1;
		s1 = ft_strjoin(ptr, ".");
		free(ptr);
	}
	return (s1);
}

static char	*check_zero_begin(t_lst *pf, long double d)
{
	char		*zero_s;
	int			pow;
	int			i;
	int			prec;

	pow = 10;
	i = 0;
	zero_s = NULL;
	if ((long long)((d - (long long)d) * pow) % 10 == 0)
	{
		zero_s = ft_strnew(pf->prec);
		prec = pf->prec;
		while ((long long)((d - (long long)d) * pow) % 10 == 0 && i < prec)
		{
			zero_s[i++] = ((long long)((d - (long long)d) * pow) % 10) + '0';
			pow *= 10;
			pf->prec--;
		}
		zero_s[i] = '\0';
	}
	return (zero_s);
}

static char	*get_second_part(t_lst *pf, long double d)
{
	long double	d2;
	char		*s2;
	char		*zero_begin;
	char		*ptr;

	pf->prec = pf->prec == -1 ? 6 : pf->prec;
	d = d < 0 ? -d : d;
	d -= d - (long long)d == 0.25 && pf->prec == 1 ? 0.05 : 0;
	d2 = (d - (long long)d) * (to_power(10, pf->prec));
	if (d2 == 0.0)
		s2 = ft_memset(ft_strnew(pf->prec), '0', pf->prec);
	else
	{
		zero_begin = check_zero_begin(pf, d);
		d2 = ((long long)(d2 * 10.0) % 10) > 4 ? d2 + 1 : d2;
		s2 = zero_begin != NULL && pf->prec == 0 ? ft_strdup("\0") :
								ft_long_long_itoa((long long)d2);
		if (zero_begin != NULL && (ptr = s2))
		{
			s2 = ft_strjoin(zero_begin, ptr);
			free(ptr);
			free(zero_begin);
		}
	}
	return (s2);
}

char		*get_double_str(t_lst *pf, long double d)
{
	char	*s1;
	char	*s2;
	char	*str;

	if (d > 0 && d - (long long)d >= 0.9999995)
		d = (long long)d + 1;
	if (d < 0 && -d - (long long)-d >= 0.9999995)
		d = (long long)d - 1;
	if (d > 0 && d - (long long)d >= 0.95 && pf->prec == 1)
		d = (long long)d + 1;
	if (d < 0 && -d - (long long)-d >= 0.95 && pf->prec == 1)
		d = (long long)d - 1;
	s1 = get_first_part(pf, d);
	if (pf->prec == 0)
	{
		pf->prec = -1;
		return (s1);
	}
	s2 = get_second_part(pf, d);
	str = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	pf->prec = -1;
	return (str);
}
