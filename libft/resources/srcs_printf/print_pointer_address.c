/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_address.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 09:23:25 by aturuk            #+#    #+#             */
/*   Updated: 2019/03/02 09:23:26 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(t_lst *pf, intptr_t p)
{
	char	*str;
	int		len;

	str = p == 0 && pf->prec == 0 ? ft_strdup("\0") :
	ft_long_long_itoa_base((unsigned long long)p, 16);
	len = ft_strlen(str) + 2;
	str = check_precission(pf, str, pf->prec - len + 2, '0');
	if (ZERO_FLG == '0' && pf->width > len)
		str = fill_zero(pf, str, len);
	len = ft_strlen(str) + 2;
	MINUS_FLG != '-' ? print_width(pf, len) : 0;
	write(1, "0x", 2);
	write(1, str, len - 2);
	pf->len_out += len;
	MINUS_FLG == '-' ? print_width(pf, len) : 0;
	free(str);
}
