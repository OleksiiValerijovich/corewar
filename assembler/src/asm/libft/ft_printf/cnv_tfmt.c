/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnv_tfmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:14:32 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/25 16:14:33 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static void		to_buf(char *tfmt_bytes, size_t size)
{
	char		*tmp;
	size_t		len;
	short		trigger;

	trigger = 0;
	len = 0;
	buf("\x1b[", 2);
	while (len < size)
	{
		if (tfmt_bytes[len] != -1)
		{
			if (trigger == 0)
				trigger = 1;
			else
				buf(";", 1);
			tmp = ft_itoa(tfmt_bytes[len]);
			buf(tmp, ft_strlen(tmp));
			free(tmp);
		}
		len++;
	}
	buf("m", 1);
}

static void		tfmt_processor(t_tfmt tfmt)
{
	char		*tfmt_bytes;

	tfmt_bytes = (char*)&tfmt;
	to_buf(tfmt_bytes, sizeof(t_tfmt));
}

void			cnv_tfmt(t_ffmt *ffmt)
{
	tfmt_processor(ffmt->tfmt);
}
