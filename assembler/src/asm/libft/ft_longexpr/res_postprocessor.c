/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_postprocessor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 21:31:43 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/14 21:31:45 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./ft_longexpr.h"

void			res_postprocessor(char **res)
{
	char		*new_res;
	char		*point;
	size_t		i;

	i = 0;
	if ((point = ft_strchr(*res, '.')))
	{
		if (compare_int((point + 1), '=', "0"))
			*point = '\0';
		else
		{
			point = ft_strchr(point, '\0');
			while (*(--point) == '0')
				*point = '\0';
		}
	}
	while (*(*res + i) == '0' && ft_isdigit(*(*res + i + 1)))
		i++;
	new_res = ft_strdup((*res + i));
	free(*res);
	*res = new_res;
}
