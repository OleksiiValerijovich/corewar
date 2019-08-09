/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 09:26:42 by aturuk            #+#    #+#             */
/*   Updated: 2019/03/02 09:26:44 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <locale.h>
# include <wchar.h>
# define FLAGS "-+ #0"
# define MINUS_FLG pf->flags[0]
# define PLUS_FLG pf->flags[1]
# define SPACE_FLG pf->flags[2]
# define HASH_FLG pf->flags[3]
# define ZERO_FLG pf->flags[4]
# define H_MOD 0
# define HH_MOD 1
# define L_MOD 2
# define LL_MOD 3
# define J_MOD 4
# define Z_MOD 5
# define LARGE_L_MOD 6
# define NULL_STR "(null)"
# define BASE "0123456789abcdef"

typedef	struct		s_lst
{
	char			*format;
	size_t			len_form;
	size_t			pos_form;
	char			flags[5];
	int				width;
	int				prec;
	int				mod;
	size_t			len_out;
}					t_lst;

int					ft_printf(const char *format, ...);
int					analyze(va_list arg, t_lst *pf);
void				find_all_spec(va_list arg, t_lst *pf);
void				find_type(va_list arg, t_lst *pf);
char				*ft_long_long_itoa(long long int n);
char				*ft_u_long_long_itoa(unsigned long long n);
char				*ft_long_long_itoa_base(unsigned long long value, int base);
long long			to_power(long long value, int pow);
char				*check_plus_flag(t_lst *pf, char *s, char sign);
char				*check_space_flag(t_lst *pf, char *s, char sign);
char				*check_hash_flag(t_lst *pf, char *s, int base);
char				*fill_zero(t_lst *pf, char *s, int len);
void				print_width(t_lst *pf, int print_len);
char				*check_precission(t_lst *pf, char *s, int len, char sign);
void				print_c(t_lst *pf, unsigned char c);
void				print_lc(t_lst *pf, wchar_t uni);
void				print_s(t_lst *pf, char *str);
void				print_ls(t_lst *pf, wchar_t *uni_str);
void				print_int(t_lst *pf, long long n);
void				print_u(t_lst *pf, unsigned long long n);
void				print_o(t_lst *pf, unsigned long long n);
void				print_x(t_lst *pf, unsigned long long n, char type);
void				print_p(t_lst *pf, intptr_t p);
void				print_f(t_lst *pf, long double d, char type);
char				*get_double_str(t_lst *pf, long double d);

#endif
