/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_integer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 09:22:25 by aturuk            #+#    #+#             */
/*   Updated: 2019/03/02 09:22:27 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_num(long long int n)
{
	int		len;

	len = n <= 0 ? 1 : 0;
	n *= n < 0 ? -1 : 1;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_long_long_itoa(long long int n)
{
	char	*str;
	int		len;

	if (n == -9223372036854775807 - 1)
		str = ft_strcpy(ft_strnew(20), "-9223372036854775808");
	else
	{
		len = count_num(n);
		str = ft_strnew(len--);
		if (n < 0)
		{
			str[0] = '-';
			n = n * -1;
		}
		while (n > 0 || (len > -1 && str[len] != '-'))
		{
			str[len] = (n % 10) + '0';
			n = n / 10;
			len--;
		}
	}
	return (str);
}

void		print_int(t_lst *pf, long long n)
{
	char	*str;
	char	sign;

	sign = n < 0 ? '-' : '+';
	str = ft_long_long_itoa(n < 0 && (PLUS_FLG != 0 ||
			SPACE_FLG != 0 || ZERO_FLG != 0) ? -n : n);
	ZERO_FLG = pf->prec != -1 ? 0 : ZERO_FLG;
	if (pf->prec == 0 && ft_strcmp(str, "0") == 0)
	{
		pf->width != 0 ? print_width(pf, 0) : 0;
		free(str);
		return ;
	}
	str = check_precission(pf, str, pf->prec - ft_strlen(str), sign);
	str = check_plus_flag(pf, str, sign);
	str = check_space_flag(pf, str, sign);
	if (ZERO_FLG == '0' && sign == '-' && !(PLUS_FLG != 0 || SPACE_FLG != 0))
	{
		write(1, "-", 1);
		pf->width -= pf->width > 0 ? 1 : 0;
		pf->len_out += 1;
	}
	print_s(pf, str);
	free(str);
}
