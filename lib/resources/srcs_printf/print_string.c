/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 09:21:53 by aturuk            #+#    #+#             */
/*   Updated: 2019/03/02 09:21:54 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_width(t_lst *pf, int print_len)
{
	char c;

	c = ZERO_FLG == '0' ? '0' : ' ';
	if (pf->width > print_len)
	{
		pf->width -= print_len;
		while (pf->width-- != 0)
		{
			write(1, &c, 1);
			pf->len_out++;
		}
	}
	else
		pf->width = 0;
}

void		print_s(t_lst *pf, char *str)
{
	int		len;
	int		print_len;

	if (pf->prec == 0)
		return (print_width(pf, 0));
	str = str == NULL ? NULL_STR : str;
	len = ft_strlen(str);
	print_len = pf->prec > 0 && pf->prec < len ? pf->prec : len;
	MINUS_FLG != '-' ? print_width(pf, print_len) : 0;
	write(1, str, print_len);
	pf->len_out += print_len;
	MINUS_FLG == '-' ? print_width(pf, print_len) : 0;
}

static int	ft_strlen_uni(wchar_t *uni_str)
{
	int len;

	len = 0;
	while (*uni_str)
	{
		if (*uni_str <= 127)
			len += 1;
		else if (*uni_str > 127 && *uni_str <= 2047)
			len += 2;
		else if (*uni_str > 2047 && *uni_str <= 65535)
			len += 3;
		else
			len += 4;
		uni_str++;
	}
	return (len);
}

static int	count_byte(wchar_t uni)
{
	if (uni <= 127)
		return (1);
	else if (uni > 127 && uni <= 2047)
		return (2);
	else if (uni > 2047 && uni <= 65535)
		return (3);
	else
		return (4);
}

void		print_ls(t_lst *pf, wchar_t *uni_str)
{
	int	print_len;
	int save_res;
	int	save_width;
	int i;

	if (uni_str == NULL || pf->prec == 0)
		return (print_s(pf, NULL));
	i = 0;
	print_len = 0;
	if (pf->prec > 0 && pf->prec < ft_strlen_uni(uni_str))
		while (print_len + count_byte(uni_str[i]) <= pf->prec)
			print_len += count_byte(uni_str[i++]);
	else
		print_len = ft_strlen_uni(uni_str);
	save_width = pf->width;
	MINUS_FLG != '-' ? print_width(pf, print_len) : 0;
	pf->width = 0;
	save_res = pf->len_out + print_len;
	while (*uni_str != '\0' && save_res != (int)pf->len_out)
		print_lc(pf, *uni_str++);
	pf->width = save_width;
	MINUS_FLG == '-' ? print_width(pf, print_len) : 0;
}
