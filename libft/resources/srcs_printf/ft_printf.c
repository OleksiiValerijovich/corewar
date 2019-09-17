/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 09:17:52 by aturuk            #+#    #+#             */
/*   Updated: 2019/03/02 09:17:54 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				analyze(va_list arg, t_lst *pf)
{
	pf->pos_form++;
	pf->len_out = 0;
	ft_memset(pf->flags, 0, 5);
	pf->width = 0;
	pf->prec = -1;
	pf->mod = -1;
	if (pf->format[pf->pos_form] == '\0')
		return (pf->len_out);
	while (ft_strchr("-+ #0*123456789.hlLjz", pf->format[pf->pos_form]) &&
		pf->format[pf->pos_form] != '\0')
		find_all_spec(arg, pf);
	if (pf->format[pf->pos_form] != '\0')
		find_type(arg, pf);
	return (pf->len_out);
}

static t_lst	*create_list(const char *format)
{
	t_lst *pf;

	pf = (t_lst *)malloc(sizeof(t_lst));
	if (format != 0)
		pf->format = ft_strdup(format);
	else
		pf->format = NULL;
	pf->len_form = ft_strlen(pf->format);
	pf->pos_form = 0;
	pf->len_out = 0;
	return (pf);
}

int				ft_printf(const char *format, ...)
{
	va_list	arg;
	t_lst	*pf;
	int		res;

	pf = create_list(format);
	res = 0;
	va_start(arg, format);
	while (pf->pos_form != pf->len_form)
	{
		if (pf->format[pf->pos_form] == '%')
			res += analyze(arg, pf);
		else
		{
			write(1, &pf->format[pf->pos_form], 1);
			pf->pos_form++;
			res++;
		}
	}
	va_end(arg);
	pf->format != NULL ? free(pf->format) : 0;
	free(pf);
	return (res);
}
