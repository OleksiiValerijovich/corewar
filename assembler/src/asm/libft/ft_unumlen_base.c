/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unumlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 01:56:08 by ishyian           #+#    #+#             */
/*   Updated: 2019/02/20 01:57:52 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_unumlen_base(unsigned long long nb, int base)
{
	size_t	len;

	len = 1;
	while ((nb = nb / base) > 0)
		len++;
	return (len);
}
