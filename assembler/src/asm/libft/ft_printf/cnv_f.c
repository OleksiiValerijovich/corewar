/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnv_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 02:38:49 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/04 19:16:44 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <math.h>
#include "./ft_printf.h"

static void			to_buf(t_ffmt *f, char *s)
{
	char					w;
	char					*point;

	point = ft_strchr(s, '.');
	w = (f->zero && !f->minus && ft_isdigit(*s)) ? '0' : ' ';
	(point && !f->sharp && !f->prec) ? ft_decrement(&f->len, 1) : 0;
	ft_decrement(&f->min_w, f->len);
	(f->plus || f->space || f->num_neg) ? ft_decrement(&f->min_w, 1) : 0;
	(f->zero && f->space && !f->num_neg) ? buf(" ", 1) : 0;
	(f->zero && f->num_neg) ? buf("-", 1) : 0;
	(f->zero && f->plus) ? buf("+", 1) : 0;
	(!f->minus && f->min_w) ? chr_to_buf(w, f->min_w) : 0;
	(!f->zero && f->space && !f->num_neg) ? buf(" ", 1) : 0;
	(!f->zero && f->num_neg) ? buf("-", 1) : 0;
	(!f->zero && f->plus) ? buf("+", 1) : 0;
	buf(s, f->len);
	(f->minus && f->min_w) ? chr_to_buf(w, f->min_w) : 0;
}

void				get_str(char *pre_fraction, char *pre_exp_pow, char **s)
{
	char					*fraction;
	char					*exp_pow;
	char					*exp;

	fraction = ft_longexpr(pre_fraction, '*', FR);
	free(pre_fraction);
	exp_pow = ft_longexpr(pre_exp_pow, '-', EXP_BIAS);
	free(pre_exp_pow);
	exp = ft_longexpr("2", '^', exp_pow);
	free(exp_pow);
	*s = ft_longexpr(fraction, '*', exp);
	free(fraction);
	free(exp);
}

void				check_const(t_ffmt *ffmt, char *bits, char **s)
{
	if (!ft_strcmp((bits + 64), "0000000000000000"))
	{
		bits[64] = '\0';
		if (!ft_strcmp(bits, N_P) || !ft_strcmp(bits, N_N))
			*s = ft_strdup(ffmt->cnv == 'F' ? "NAN" : "nan");
		else if (!ft_strcmp(bits, Z_P) || !ft_strcmp(bits, Z_N))
		{
			*s = ft_strdup("0");
			cnv_f_nbr_processor(ffmt, s, bits);
		}
		else if (!ft_strcmp(bits, I_P) || !ft_strcmp(bits, I_N))
			*s = ft_strdup(ffmt->cnv == 'F' ? "INF" : "inf");
	}
}

void				cnv_f(t_ffmt *ffmt, va_list ap)
{
	long double				num;
	char					*bits;
	long long unsigned		pre_fraction;
	short					pre_exp_pow;
	char					*s;

	s = NULL;
	if (ffmt->uppl)
		num = va_arg(ap, long double);
	else
		num = va_arg(ap, double);
	bits = ft_getbitstrr(&num, sizeof(long double) - 6);
	check_const(ffmt, bits, &s);
	if (!s)
	{
		pre_fraction = *((long long unsigned*)&num);
		bits[16] = '\0';
		pre_exp_pow = ft_atoi_base(bits + 1, 2);
		get_str(ft_ulltoa(pre_fraction), ft_itoa(pre_exp_pow), &s);
		cnv_f_nbr_processor(ffmt, &s, bits);
	}
	ffmt->len = ft_strlen(s);
	to_buf(ffmt, s);
	free(bits);
	free(s);
}
