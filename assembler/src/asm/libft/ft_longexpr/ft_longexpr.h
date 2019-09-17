/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longexpr.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 19:07:58 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/11 16:42:41 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LONGEXPR_H
# define FT_LONGEXPR_H
# define VALID_OPERATORS "+-*^/%>=<"
# define A_A_EQUAL_B_A (AA || AB || AC || (AD && AE && AF))
# define AA (!a->len_aft && !b->len_aft)
# define AB (!a->len_aft && b->len_aft && !ft_strchrs(b->point, "123456789"))
# define AC (!b->len_aft && a->len_aft && !ft_strchrs(a->point, "123456789"))
# define AD (a->len_aft && b->len_aft && *a->point == *b->point)
# define AE (!ft_strchrs(a->point + 1, "123456789"))
# define AF (!ft_strchrs(b->point + 1, "123456789"))
# define A_A_LESS_B_A (BA || BB || (BC && BD && BE))
# define BA (!a->len_aft && b->len_aft && ft_strchrs(b->point, "123456789"))
# define BB (a->len_aft && b->len_aft && *a->point < *b->point)
# define BC (a->len_aft && b->len_aft && *a->point == *b->point)
# define BD (!ft_strchrs(a->point + 1, "123456789"))
# define BE (ft_strchrs(b->point + 1, "123456789"))
# define A_A_GREATER_B_A (CA || CB || (CC && CD && CE))
# define CA (a->len_aft && !b->len_aft && ft_strchrs(a->point, "123456789"))
# define CB (a->len_aft && b->len_aft && *a->point > *b->point)
# define CC (a->len_aft && b->len_aft && *a->point == *b->point)
# define CD (ft_strchrs(a->point + 1, "123456789"))
# define CE (!ft_strchrs(b->point + 1, "123456789"))

# include "../libft.h"

typedef struct		s_longexpr
{
	const char		*start;
	const char		*end;
	const char		*point;
	size_t			len;
	size_t			len_bef;
	size_t			len_aft;
	unsigned char	neg:1;
}					t_longexpr;

int					is_valid(const char *a_arg, char op, const char *b_arg);
void				sum(t_longexpr *a, t_longexpr *b, char *res);
void				subtraction(t_longexpr *a, t_longexpr *b, char *res);
void				mult(t_longexpr *a, t_longexpr *b, char *res);
void				topow(t_longexpr *a, t_longexpr *b, char *res);
char				*dodiv(t_longexpr *a, t_longexpr *b);
char				*dodiv_get_fraction(char *a, char *b);
void				dodiv_rec_divider(char *a, char *b, char **res_curr,
															char *part);
char				*modulo(t_longexpr *a, t_longexpr *b);
int					compare(t_longexpr *a, char op, t_longexpr *b);
int					compare_int(const char *a, char op, const char *b);
void				res_postprocessor(char **res);
void				set_sign(t_longexpr *a, t_longexpr *b, char op,
																char **res);

#endif
