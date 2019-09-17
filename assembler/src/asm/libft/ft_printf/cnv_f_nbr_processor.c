/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnv_f_nbr_processor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:11:46 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/18 17:11:49 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int					is_curr_even(char *s)
{
	if (*s == '.')
		s--;
	if ((*s - '0') % 2 == 0)
		return (1);
	return (0);
}

char				*get_part(char *s)
{
	char			*add;
	size_t			i;

	add = ft_strdup(s);
	i = 0;
	while ((ft_isdigit(add[i]) || add[i] == '.') && add[i + 1] != '\0')
	{
		if (ft_isdigit(add[i]))
			add[i] = '0';
		i++;
	}
	add[i] = '1';
	return (add);
}

void				nbr_rounder(char **s, size_t curr_pos)
{
	char			*add;
	char			*tofree;
	int				equal_to_zero;

	tofree = *s;
	equal_to_zero = 0;
	if (!*(*s + curr_pos + 1) || ft_longexprcmp(*s + curr_pos + 1, '=', "0"))
		equal_to_zero = 1;
	if ((*s)[curr_pos] - '0' < 5 || ((*s)[curr_pos] - '0' == 5 &&
		is_curr_even(*s + curr_pos - 1) && equal_to_zero))
	{
		(*s)[curr_pos] = '\0';
		*s = ft_strdup(*s);
		free(tofree);
	}
	else if ((*s)[curr_pos] - '0' > 4)
	{
		if ((*s)[curr_pos - 1] == '.')
			curr_pos--;
		(*s)[curr_pos] = '\0';
		add = get_part(*s);
		*s = ft_longexpr(*s, '+', add);
		free(add);
		free(tofree);
	}
}

void				add_zeroes(char **s, size_t zeroes_count)
{
	char			*zeroes;
	char			*tofree;

	zeroes = ft_smalloc(zeroes_count + 1);
	ft_memset(zeroes, '0', zeroes_count);
	zeroes[zeroes_count] = '\0';
	tofree = *s;
	*s = ft_strjoin(*s, zeroes);
	free(zeroes);
	free(tofree);
}

void				cnv_f_nbr_processor(t_ffmt *f, char **s, char *bits)
{
	char			*point;
	char			*tofree;
	size_t			len_aft;

	f->num_neg = (bits[0] == '1') ? 1 : 0;
	f->num_neg ? (f->plus = 0) : 0;
	!f->is_prec ? (f->prec = 6) : 0;
	point = ft_strchr(*s, '.');
	if (!point)
		len_aft = 0;
	else
		len_aft = ft_strlen(point + 1);
	if (!point && f->prec != 0)
	{
		tofree = *s;
		*s = ft_strjoin(*s, ".");
		free(tofree);
	}
	if (len_aft < f->prec)
		add_zeroes(s, f->prec - len_aft);
	else if (len_aft > f->prec)
	{
		nbr_rounder(s, (point - *s) + f->prec + 1);
		cnv_f_nbr_processor(f, s, bits);
	}
}
