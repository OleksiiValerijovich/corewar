/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnv_noncnv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:04:08 by ishyian           #+#    #+#             */
/*   Updated: 2019/03/13 19:54:58 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void			cnv_noncnv(const char **fmt, t_ffmt *ffmt)
{
	char	w;

	if (**fmt && ffmt->is_min_w)
	{
		w = ffmt->zero ? '0' : ' ';
		ft_decrement(&ffmt->min_w, 1);
		!ffmt->minus ? chr_to_buf(w, ffmt->min_w) : 0;
		buf(*fmt, 1);
		ffmt->minus ? chr_to_buf(w, ffmt->min_w) : 0;
		(*fmt)++;
	}
}
