/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 09:20:00 by aturuk            #+#    #+#             */
/*   Updated: 2019/03/02 09:20:01 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long			signed_int(char type, t_lst *pf, va_list arg)
{
	long long n;

	n = 0;
	if (type == 'D')
		return ((long long)va_arg(arg, long));
	else if (pf->mod == H_MOD)
		return ((long long)(short)va_arg(arg, int));
	else if (pf->mod == HH_MOD)
		return ((long long)(char)va_arg(arg, int));
	else if (pf->mod == L_MOD)
		return ((long long)va_arg(arg, long));
	else if (pf->mod == LL_MOD)
		return (va_arg(arg, long long));
	else if (pf->mod == J_MOD)
		return ((long long)va_arg(arg, intmax_t));
	else if (pf->mod == Z_MOD)
		return ((long long)va_arg(arg, size_t));
	else
		n = (long long)va_arg(arg, int);
	return (n);
}

static unsigned long long	unsigned_int(char type, t_lst *pf, va_list arg)
{
	unsigned long long n;

	n = 0;
	if (type == 'O' || type == 'U')
		return ((unsigned long long)va_arg(arg, unsigned long));
	else if (pf->mod == H_MOD)
		return ((unsigned long long)(unsigned short)va_arg(arg, unsigned int));
	else if (pf->mod == HH_MOD)
		return ((unsigned long long)(unsigned char)va_arg(arg, unsigned int));
	else if (pf->mod == L_MOD)
		return ((unsigned long long)va_arg(arg, unsigned long));
	else if (pf->mod == LL_MOD)
		return (va_arg(arg, unsigned long long));
	else if (pf->mod == J_MOD)
		return ((unsigned long long)va_arg(arg, uintmax_t));
	else if (pf->mod == Z_MOD)
		return ((unsigned long long)va_arg(arg, size_t));
	else
		n = (unsigned long long)va_arg(arg, unsigned int);
	return (n);
}

void						find_type(va_list arg, t_lst *pf)
{
	char type;

	type = pf->format[pf->pos_form];
	if (type == 'c' || type == 'C')
		pf->mod == L_MOD || type == 'C' ?
		print_lc(pf, va_arg(arg, wint_t)) : print_c(pf, va_arg(arg, int));
	else if (type == 's' || type == 'S')
		pf->mod == L_MOD || type == 'S' ?
		print_ls(pf, va_arg(arg, wchar_t *)) : print_s(pf, va_arg(arg, char *));
	else if (type == 'p')
		print_p(pf, (intptr_t)va_arg(arg, void *));
	else if (type == 'd' || type == 'D' || type == 'i')
		print_int(pf, signed_int(type, pf, arg));
	else if (type == 'o' || type == 'O')
		print_o(pf, unsigned_int(type, pf, arg));
	else if (type == 'u' || type == 'U')
		print_u(pf, unsigned_int(type, pf, arg));
	else if (type == 'x' || type == 'X')
		print_x(pf, unsigned_int(type, pf, arg), type);
	else if (type == 'f' || type == 'F')
		pf->mod == LARGE_L_MOD ? print_f(pf, va_arg(arg, long double), type) :
		print_f(pf, (long double)va_arg(arg, double), type);
	else
		print_c(pf, type);
	pf->pos_form++;
}
