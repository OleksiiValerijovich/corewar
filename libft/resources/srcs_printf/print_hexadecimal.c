/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 09:24:15 by aturuk            #+#    #+#             */
/*   Updated: 2019/03/02 09:24:17 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	up_base(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] >= 'a' && s[i] <= 'f') || s[i] == 'x')
			s[i] -= 32;
		i++;
	}
}

static char	*get_ready_for_zero(t_lst *pf, char *str, int len)
{
	int save_width;

	if (pf->prec > 0 && pf->width > pf->prec && pf->prec > len)
	{
		save_width = pf->width;
		pf->width = pf->prec;
		str = fill_zero(pf, str, len);
		pf->prec = -1;
		pf->width = save_width;
	}
	else
	{
		if (pf->prec == -1)
			str = fill_zero(pf, str, len);
	}
	return (str);
}

void		print_x(t_lst *pf, unsigned long long n, char type)
{
	char	*str;
	int		len;

	str = ft_long_long_itoa_base(n, 16);
	HASH_FLG = n == 0 ? 0 : HASH_FLG;
	if (pf->prec == 0 && ft_strcmp(str, "0") == 0)
	{
		pf->width != 0 ? print_width(pf, 0) : 0;
		free(str);
		return ;
	}
	len = ft_strlen(str) + (HASH_FLG == '#' && !(pf->prec > 0) ? 2 : 0);
	if (ZERO_FLG == '0' && pf->width > len && n != 0)
		str = get_ready_for_zero(pf, str, len);
	str = check_precission(pf, str, pf->prec - len, '0');
	str = check_hash_flag(pf, str, 16);
	type == 'X' ? up_base(str) : 0;
	print_s(pf, str);
	free(str);
}
