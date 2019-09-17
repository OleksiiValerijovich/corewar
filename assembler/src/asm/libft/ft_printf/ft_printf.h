/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:00:59 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/07 16:06:59 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "../libft.h"
# define CONVERSIONS "cCpsSdDioOuUxXbfF%y"
# define VALID_CHRS "cCpsSdDioOuUxXbfF%y{#-+ *.:hlLbrzj1234567890"
# define BUFF_SIZE 64
# define FILL_SIZE 8
# define EXP_BIAS "16383"
# define FR "0.000000000000000000108420217248550443400745280086994171142578125"
# define Z_P "0000000000000000000000000000000000000000000000000000000000000000"
# define Z_N "1000000000000000000000000000000000000000000000000000000000000000"
# define I_P "0111111111111111100000000000000000000000000000000000000000000000"
# define I_N "1111111111111111100000000000000000000000000000000000000000000000"
# define N_P "0111111111111111110000000000000000000000000000000000000000000000"
# define N_N "1111111111111111110000000000000000000000000000000000000000000000"

typedef struct		s_tfmt
{
	char			formatting[8];
	char			text_color;
	char			bg_color;
}					t_tfmt;

typedef struct		s_ffmt
{
	char			cnv;
	unsigned char	sharp:1;
	unsigned char	zero:1;
	unsigned char	minus:1;
	unsigned char	num_neg:1;
	unsigned char	plus:1;
	unsigned char	space:1;
	unsigned char	h:1;
	unsigned char	hh:1;
	unsigned char	l:1;
	unsigned char	ll:1;
	unsigned char	uppl:1;
	unsigned char	r:1;
	unsigned char	z:1;
	unsigned char	j:1;
	unsigned char	is_min_w:1;
	size_t			min_w;
	unsigned char	is_prec:1;
	size_t			prec;
	unsigned char	is_len:1;
	size_t			len;
	struct s_tfmt	tfmt;
}					t_ffmt;

typedef struct		s_fill
{
	char			fill[FILL_SIZE];
}					t_fill;

size_t				g_size;
size_t				g_fd;

void				buf(const void *s, size_t len);
void				buf_print(void);
void				chr_to_buf(const char c, size_t count);
void				wchr_to_buf(const wchar_t c, int max_size);
void				wstr_to_buf(const wchar_t *s, int max_size, size_t len);
void				print(const void *s, size_t size);
void				parser(const char *fmt, va_list ap);
const char			*fmt_formalizer(const char *fmt, t_ffmt *ffmt, va_list ap);
const char			*fmt_form_digit(const char *fmt, t_ffmt *ffmt);
const char			*fmt_form_wildcard(const char *fmt, t_ffmt *f, va_list ap);
const char			*fmt_form_tfmt(const char *fmt, t_ffmt *f);
void				cnv_c(t_ffmt *ffmt, va_list ap);
void				cnv_s(t_ffmt *ffmt, va_list ap);
void				cnv_p(t_ffmt *ffmt, va_list ap);
void				cnv_diouxxb(t_ffmt *ffmt, va_list ap);
void				cnv_f(t_ffmt *ffmt, va_list ap);
void				cnv_f_nbr_processor(t_ffmt *ffmt, char **nbr, char *bits);
void				cnv_noncnv(const char **fmt, t_ffmt *ffmt);
void				cnv_tfmt(t_ffmt *ffmt);

#endif
