/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dodiv_get_fraction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 22:07:21 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/13 22:07:22 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./ft_longexpr.h"

static void		add_zeroes(char **res_fraction, char *pre_zeroes)
{
	char	*tofree;

	tofree = *res_fraction;
	*res_fraction = ft_strjoin(pre_zeroes, *res_fraction);
	free(tofree);
	free(pre_zeroes);
}

static void		a_multiplier(char **a, char *b)
{
	char		*tofree;

	tofree = *a;
	*a = ft_longexpr(*a, '*', b);
	free(tofree);
	free(b);
}

static char		*get_multiplier(char *a, char *b)
{
	char		*multiplier;
	size_t		len_greatest;

	len_greatest = GREATEST(ft_strlen(a), ft_strlen(b));
	multiplier = ft_smalloc(len_greatest + 2);
	multiplier[0] = '1';
	ft_memset(multiplier + 1, '0', len_greatest);
	multiplier[len_greatest + 1] = '\0';
	return (multiplier);
}

static char		*get_zeroes(char **a, char *b)
{
	int			count;
	char		*zeroes;
	char		*tofree;

	count = -1;
	while (compare_int(*a, '<', b))
	{
		tofree = *a;
		*a = ft_longexpr(*a, '*', "10");
		free(tofree);
		count++;
	}
	if (count == 0)
		return (NULL);
	zeroes = ft_smalloc(count + 1);
	ft_memset(zeroes, '0', count);
	zeroes[count] = '\0';
	return (zeroes);
}

char			*dodiv_get_fraction(char *a, char *b)
{
	char		*res_fraction;
	char		*part;
	char		*pre_zeroes;
	size_t		part_len;

	pre_zeroes = get_zeroes(&a, b);
	a_multiplier(&a, get_multiplier(a, b));
	part_len = ft_strlen(a);
	part = ft_smalloc(part_len + 1);
	part[part_len] = '\0';
	res_fraction = ft_itoa(0);
	dodiv_rec_divider(a, b, &res_fraction, part);
	if (pre_zeroes)
		add_zeroes(&res_fraction, pre_zeroes);
	free(part);
	free(a);
	return (res_fraction);
}
