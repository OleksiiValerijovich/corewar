/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dodiv_rec_divider.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:26:26 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/13 21:27:42 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./ft_longexpr.h"

static char		*part_ratio_multiplier(char *part_ratio, int part_ratio_zeroes)
{
	char		*ratio_multiplied;
	char		*zeroes;

	zeroes = ft_smalloc(part_ratio_zeroes + 1);
	ft_memset(zeroes, '0', part_ratio_zeroes);
	zeroes[part_ratio_zeroes] = '\0';
	ratio_multiplied = ft_strjoin(part_ratio, zeroes);
	free(part_ratio);
	free(zeroes);
	return (ratio_multiplied);
}

static char		*return_part_modulo(char *a, int part_len, char *part_modulo)
{
	int			diff;
	int			curr_part_len;

	diff = 1;
	curr_part_len = (int)ft_strlen(part_modulo);
	if (compare_int(part_modulo, '>', "0"))
	{
		diff = part_len - curr_part_len;
		ft_memcpy(a + diff, part_modulo, curr_part_len);
	}
	return (a + diff);
}

static char		*part_divider(char *part, char *b)
{
	int			ratio;
	char		*tofree;
	char		*part_modulo;

	ratio = 0;
	part_modulo = ft_strdup(part);
	while (!compare_int(part_modulo, '<', b))
	{
		tofree = part_modulo;
		part_modulo = ft_longexpr(part_modulo, '-', b);
		free(tofree);
		ratio++;
	}
	ft_strcpy(part, part_modulo);
	free(part_modulo);
	return (ft_itoa(ratio));
}

static int		get_part(char *a, char *b, char *part, int *part_ratio_zeroes)
{
	int			len;

	len = 0;
	part[0] = '0';
	part[1] = '\0';
	while (compare_int(part, '<', b))
	{
		part[len] = a[len];
		len++;
		part[len] = '\0';
	}
	ft_memset(a, '0', len);
	*part_ratio_zeroes = (int)ft_strlen(a) - len;
	return (len);
}

void			dodiv_rec_divider(char *a, char *b, char **res_curr,
									char *part)
{
	int			part_len;
	char		*part_ratio;
	int			part_ratio_zeroes;
	char		*tofree;

	part_len = get_part(a, b, part, &part_ratio_zeroes);
	part_ratio = part_divider(part, b);
	a = return_part_modulo(a, part_len, part);
	part_ratio = part_ratio_multiplier(part_ratio, part_ratio_zeroes);
	tofree = *res_curr;
	*res_curr = ft_longexpr(*res_curr, '+', part_ratio);
	free(tofree);
	free(part_ratio);
	if (ft_strlen(a) && !compare_int(a, '<', b))
		dodiv_rec_divider(a, b, res_curr, part);
}
