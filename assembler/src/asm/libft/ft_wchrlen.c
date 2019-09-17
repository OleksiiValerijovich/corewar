/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 18:20:19 by ishyian           #+#    #+#             */
/*   Updated: 2019/03/14 19:41:31 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <string.h>

size_t		ft_wchrlen(const wchar_t wc)
{
	if (wc < 128)
		return (1);
	else if (wc < 2048)
		return (2);
	else if (wc < 65536)
		return (3);
	else if (wc < 2097152)
		return (4);
	else
		return (0);
}
