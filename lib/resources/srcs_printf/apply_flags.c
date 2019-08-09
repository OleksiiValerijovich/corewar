/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 09:20:40 by aturuk            #+#    #+#             */
/*   Updated: 2019/03/02 09:20:43 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_precission(t_lst *pf, char *s, int len, char sign)
{
	char	*ptr;
	char	*prec;

	if (pf->prec == -1)
		return (s);
	len += (s[0] == '-' ? 1 : 0);
	if (len > 0)
	{
		ptr = s;
		prec = ft_memset(ft_strnew(len), '0', len);
		s = ft_strjoin(prec, s[0] == '-' ? ptr + 1 : ptr);
		free(ptr);
		free(prec);
		if (sign == '-' && PLUS_FLG != '+' && SPACE_FLG != ' ')
		{
			ptr = s;
			s = ft_strjoin("-", ptr);
			free(ptr);
		}
		ZERO_FLG = 0;
	}
	pf->prec = -1;
	return (s);
}

char	*check_plus_flag(t_lst *pf, char *s, char sign)
{
	char	*ptr;

	if (PLUS_FLG == '+')
	{
		if (ZERO_FLG == '0')
		{
			write(1, &sign, 1);
			pf->len_out += 1;
			pf->width -= pf->width != 0 ? 1 : 0;
		}
		else
		{
			ptr = s;
			s = sign == '+' ? ft_strjoin("+", ptr) : s;
			s = sign == '-' ? ft_strjoin("-", ptr) : s;
			free(ptr);
		}
	}
	return (s);
}

char	*check_space_flag(t_lst *pf, char *s, char sign)
{
	char	*ptr;

	if (SPACE_FLG == ' ')
	{
		if (ZERO_FLG == '0')
		{
			write(1, sign == '+' ? " " : "-", 1);
			pf->len_out += 1;
			pf->width -= pf->width != 0 ? 1 : 0;
		}
		else
		{
			ptr = s;
			s = ft_strjoin(sign == '+' ? " " : "-", ptr);
			free(ptr);
		}
	}
	return (s);
}

char	*check_hash_flag(t_lst *pf, char *s, int base)
{
	char	*ptr;

	if (HASH_FLG == '#')
	{
		if (base == 8)
		{
			ptr = s;
			s = ft_strjoin("0", ptr);
			free(ptr);
		}
		else if (base == 16)
		{
			ptr = s;
			s = ft_strjoin("0x", ptr);
			free(ptr);
		}
		HASH_FLG = 0;
	}
	return (s);
}

char	*fill_zero(t_lst *pf, char *s, int len)
{
	char	*zero;
	char	*ptr;

	zero = ft_memset(ft_strnew(pf->width - len), '0', pf->width - len);
	ptr = s;
	s = ft_strjoin(zero, ptr);
	free(zero);
	free(ptr);
	ZERO_FLG = 0;
	pf->width = 0;
	return (s);
}
