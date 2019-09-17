/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 09:19:20 by aturuk            #+#    #+#             */
/*   Updated: 2019/03/02 09:19:22 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	find_flags(t_lst *pf)
{
	while (ft_strchr(FLAGS, pf->format[pf->pos_form]) &&
		pf->pos_form != pf->len_form)
	{
		if (pf->format[pf->pos_form] == '0' && MINUS_FLG == 0)
			ZERO_FLG = '0';
		if (pf->format[pf->pos_form] == '#')
			HASH_FLG = '#';
		if (pf->format[pf->pos_form] == ' ' && PLUS_FLG == 0)
			SPACE_FLG = ' ';
		if (pf->format[pf->pos_form] == '+')
		{
			PLUS_FLG = '+';
			SPACE_FLG = 0;
		}
		if (pf->format[pf->pos_form] == '-')
		{
			MINUS_FLG = '-';
			ZERO_FLG = 0;
		}
		pf->pos_form++;
	}
}

static void	find_width(va_list arg, t_lst *pf)
{
	if (pf->format[pf->pos_form] == '*')
	{
		pf->width = va_arg(arg, int);
		if (pf->width < 0)
		{
			MINUS_FLG = '-';
			ZERO_FLG = 0;
			pf->width *= -1;
		}
		pf->pos_form++;
	}
	else
	{
		while (pf->format[pf->pos_form] >= '0' &&
			pf->format[pf->pos_form] <= '9')
		{
			pf->width = pf->width * 10 + (pf->format[pf->pos_form] - '0');
			pf->pos_form++;
		}
	}
}

static void	find_precission(va_list arg, t_lst *pf)
{
	pf->prec = 0;
	if (pf->format[pf->pos_form] == '*')
	{
		pf->prec = va_arg(arg, int);
		if (pf->prec < 0)
			pf->prec = -1;
		pf->pos_form++;
	}
	else
	{
		while (pf->format[pf->pos_form] >= '0' &&
			pf->format[pf->pos_form] <= '9')
		{
			pf->prec = pf->prec * 10 + (pf->format[pf->pos_form] - '0');
			pf->pos_form++;
		}
	}
}

static void	find_modifier(t_lst *pf)
{
	if (pf->format[pf->pos_form] == 'h' || pf->format[pf->pos_form] == 'l')
	{
		if (pf->format[pf->pos_form] == 'h')
		{
			pf->mod = pf->format[pf->pos_form + 1] == 'h' ? HH_MOD : H_MOD;
			pf->pos_form += pf->mod == HH_MOD ? 2 : 1;
		}
		if (pf->format[pf->pos_form] == 'l')
		{
			pf->mod = pf->format[pf->pos_form + 1] == 'l' ? LL_MOD : L_MOD;
			pf->pos_form += pf->mod == LL_MOD ? 2 : 1;
		}
	}
	if (pf->format[pf->pos_form] == 'j' || pf->format[pf->pos_form] == 'z' ||
		pf->format[pf->pos_form] == 'L')
	{
		pf->mod = pf->format[pf->pos_form] == 'j' ? J_MOD : pf->mod;
		pf->mod = pf->format[pf->pos_form] == 'z' ? Z_MOD : pf->mod;
		pf->mod = pf->format[pf->pos_form] == 'L' ? LARGE_L_MOD : pf->mod;
		pf->pos_form++;
	}
}

void		find_all_spec(va_list arg, t_lst *pf)
{
	find_flags(pf);
	if (ft_isdigit(pf->format[pf->pos_form]) == 1 ||
	pf->format[pf->pos_form] == '*')
	{
		pf->width = 0;
		find_width(arg, pf);
	}
	if (pf->format[pf->pos_form] == '.')
	{
		pf->pos_form++;
		pf->prec = -1;
		find_precission(arg, pf);
	}
	if (ft_strchr("hlLjz", pf->format[pf->pos_form]))
		pf->mod == -1 ? find_modifier(pf) : pf->pos_form++;
}
