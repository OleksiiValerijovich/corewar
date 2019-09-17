/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:48:04 by ishyian           #+#    #+#             */
/*   Updated: 2019/02/20 16:30:58 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_memjoin(void const *s1, size_t size_s1,
					void const *s2, size_t size_s2)
{
	void	*s3;

	if (s1 != NULL && s2 != NULL)
	{
		s3 = (void*)malloc(size_s1 + size_s2);
		if (s3 == NULL)
			return (s3);
		ft_memmove(s3, s1, size_s1);
		ft_memmove(s3 + size_s1, s2, size_s2);
		return (s3);
	}
	return (NULL);
}
