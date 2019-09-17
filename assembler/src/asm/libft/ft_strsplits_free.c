/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplits_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:25:43 by ishyian           #+#    #+#             */
/*   Updated: 2019/07/30 18:31:43 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_strsplits_free(char ***splits)
{
	size_t		i;

	i = 0;
	while ((*splits)[i])
	{
		ft_memdel((void **)&(*splits)[i]);
		i++;
	}
	ft_memdel((void **)splits);
}
