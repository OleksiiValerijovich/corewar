/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_integer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 09:22:51 by aturuk            #+#    #+#             */
/*   Updated: 2019/03/02 09:22:52 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_u_long_long_itoa(unsigned long long n)
{
	char					*str;
	unsigned long long int	copy_n;
	int						len;

	if (n == 0)
		return (ft_strdup("0"));
	len = 0;
	copy_n = n;
	while (copy_n > 0)
	{
		copy_n /= 10;
		len++;
	}
	str = ft_strnew(len--);
	while (n > 0)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

void	print_u(t_lst *pf, unsigned long long n)
{
	char	*str;

	str = ft_u_long_long_itoa(n);
	ZERO_FLG = pf->prec != -1 ? 0 : ZERO_FLG;
	if (pf->prec == 0 && ft_strcmp(str, "0") == 0)
	{
		pf->width != 0 ? print_width(pf, 0) : 0;
		free(str);
		return ;
	}
	str = check_precission(pf, str, pf->prec - ft_strlen(str), '0');
	print_s(pf, str);
	free(str);
}
