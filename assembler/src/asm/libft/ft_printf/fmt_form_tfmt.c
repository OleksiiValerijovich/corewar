/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_form_tfmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:31:46 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/25 15:31:47 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static void			digit_processor(char *work, t_ffmt *f)
{
	int			curr_digit;

	while (*work)
	{
		while (*work && !ft_isdigit(*work))
			work++;
		if (*work)
		{
			curr_digit = ft_atoi(work);
			if (curr_digit >= 0 && curr_digit <= 8)
				f->tfmt.formatting[curr_digit] = curr_digit;
			else if (curr_digit >= 30 && curr_digit <= 37)
				f->tfmt.text_color = curr_digit;
			else if (curr_digit >= 40 && curr_digit <= 47)
				f->tfmt.bg_color = curr_digit;
			while (*work && ft_isdigit(*work))
				work++;
		}
	}
}

static void			bg_color_processor(char *work, t_ffmt *f)
{
	if (ft_strstr(work, "BLACK"))
		f->tfmt.bg_color = 40;
	else if (ft_strstr(work, "RED"))
		f->tfmt.bg_color = 41;
	else if (ft_strstr(work, "GREEN"))
		f->tfmt.bg_color = 42;
	else if (ft_strstr(work, "YELLOW"))
		f->tfmt.bg_color = 43;
	else if (ft_strstr(work, "BLUE"))
		f->tfmt.bg_color = 44;
	else if (ft_strstr(work, "PURPLE"))
		f->tfmt.bg_color = 45;
	else if (ft_strstr(work, "LIGHT_BLUE"))
		f->tfmt.bg_color = 46;
	else if (ft_strstr(work, "WHITE"))
		f->tfmt.bg_color = 47;
}

static void			text_color_processor(char *work, t_ffmt *f)
{
	if (ft_strstr(work, "black"))
		f->tfmt.text_color = 30;
	else if (ft_strstr(work, "red"))
		f->tfmt.text_color = 31;
	else if (ft_strstr(work, "green"))
		f->tfmt.text_color = 32;
	else if (ft_strstr(work, "yellow"))
		f->tfmt.text_color = 33;
	else if (ft_strstr(work, "blue"))
		f->tfmt.text_color = 34;
	else if (ft_strstr(work, "purple"))
		f->tfmt.text_color = 35;
	else if (ft_strstr(work, "light-blue"))
		f->tfmt.text_color = 36;
	else if (ft_strstr(work, "white"))
		f->tfmt.text_color = 37;
}

static void			text_formatting_processor(char *work, t_ffmt *f)
{
	if (ft_strstr(work, "normal"))
		f->tfmt.formatting[0] = 0;
	else if (ft_strstr(work, "bold"))
		f->tfmt.formatting[1] = 1;
	else if (ft_strstr(work, "italic"))
		f->tfmt.formatting[3] = 3;
	else if (ft_strstr(work, "underlined"))
		f->tfmt.formatting[4] = 4;
}

const char			*fmt_form_tfmt(const char *fmt, t_ffmt *f)
{
	char		*end_cnv;
	char		*end_tfmt;
	char		*work;

	end_tfmt = ft_strchr(fmt, '}');
	end_cnv = ft_strchr(end_tfmt, 'y');
	if (end_cnv && end_tfmt && end_tfmt < end_cnv)
	{
		ft_memset((char*)&f->tfmt, -1, sizeof(t_tfmt));
		work = ft_memdup(fmt + 1, end_tfmt - fmt);
		work[end_tfmt - fmt - 1] = '\0';
		text_formatting_processor(work, f);
		text_color_processor(work, f);
		bg_color_processor(work, f);
		digit_processor(work, f);
		free(work);
		return (end_tfmt);
	}
	else
		return (fmt);
}
