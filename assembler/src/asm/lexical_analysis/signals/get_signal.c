/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 11:31:31 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 13:07:21 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm/asm.h"
#include "../../../../inc/asm/fsm_lexical_analysis.h"

static void			set_signals(int (*signals[15])(char c))
{
	signals[0] = is_null;
	signals[1] = is_alfa;
	signals[2] = is_digit;
	signals[3] = is_registry_alfa;
	signals[4] = is_eol;
	signals[5] = is_space;
	signals[6] = is_dir_char;
	signals[7] = is_separator;
	signals[8] = is_sign;
	signals[9] = is_label_char;
	signals[10] = is_underline;
	signals[11] = is_comment_char;
	signals[12] = is_cmd_char;
	signals[13] = is_quote;
	signals[14] = NULL;
}

enum e_signals		get_signal(char c)
{
	static int		(*signals[15])(char c);
	int				i;

	if (!*signals)
		set_signals(signals);
	i = 0;
	while (signals[i])
	{
		if ((signals[i])(c) != -1)
		{
			return ((signals[i])(c));
		}
		i++;
	}
	return (other);
}
