/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:22:25 by ishyian           #+#    #+#             */
/*   Updated: 2019/02/19 23:23:01 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_numlen_base(long long nb, int base)
{
	size_t	len;

	len = 1;
	if (nb < 0)
		nb *= -1;
	while ((nb = nb / base) > 0)
		len++;
	return (len);
}
