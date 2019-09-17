/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:11:30 by ishyian           #+#    #+#             */
/*   Updated: 2019/02/21 18:55:15 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void		ft_decrement(size_t *nb, size_t decremention)
{
	if (decremention < *nb)
		*nb = *nb - decremention;
	else
		*nb = 0;
}
