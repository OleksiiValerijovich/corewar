/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 09:23:49 by aturuk            #+#    #+#             */
/*   Updated: 2019/03/02 09:23:50 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_long_long_itoa_base(unsigned long long value, int base)
{
	int					len;
	unsigned long long	copy_value;
	char				*str_base;

	if (base < 2 || base > 16)
		return (NULL);
	copy_value = value;
	len = value == 0 ? 1 : 0;
	while (copy_value > 0)
	{
		copy_value = copy_value / base;
		len++;
	}
	str_base = ft_strnew(len);
	while (--len != -1)
	{
		str_base[len] = BASE[value % base];
		value = value / base;
	}
	return (str_base);
}

void		print_o(t_lst *pf, unsigned long long n)
{
	char	*str;
	int		len;

	str = ft_long_long_itoa_base(n, 8);
	ZERO_FLG = HASH_FLG != 0 ? 0 : ZERO_FLG;
	if (pf->prec == 0 && ft_strcmp(str, "0") == 0 && HASH_FLG == 0)
	{
		pf->width != 0 ? print_width(pf, 0) : 0;
		free(str);
		return ;
	}
	HASH_FLG = n == 0 ? 0 : HASH_FLG;
	len = ft_strlen(str) + (HASH_FLG == '#' ? 1 : 0);
	str = check_hash_flag(pf, str, 8);
	str = check_precission(pf, str, pf->prec - len, '0');
	print_s(pf, str);
	free(str);
}
