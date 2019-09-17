/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unumlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:03:17 by ishyian           #+#    #+#             */
/*   Updated: 2019/02/15 18:47:54 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_unumlen(unsigned long long nb)
{
	size_t	len;

	len = 1;
	while ((nb = nb / 10) > 0)
		len++;
	return (len);
}
