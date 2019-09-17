/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:09:00 by ishyian           #+#    #+#             */
/*   Updated: 2019/02/22 04:22:48 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long		ft_sqrt(long long nb)
{
	long long	sq_root;

	sq_root = 0;
	while (sq_root * sq_root < nb)
		sq_root++;
	while (sq_root * sq_root > nb)
		sq_root--;
	return (sq_root);
}
