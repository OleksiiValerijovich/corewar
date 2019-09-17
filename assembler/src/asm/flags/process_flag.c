/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:08:40 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 02:00:51 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../../../inc/asm/asm.h"

static int		do_flag_long(char *flag)
{
	if (!ft_strcmp(flag, "--size"))
		g_flags.exec_size = 1;
	else if (!ft_strcmp(flag, "--translation"))
		g_flags.translation = 1;
	else
	{
		g_state = -6;
		return (0);
	}
	return (1);
}

static int		do_flag_short(char *flag)
{
	if (*flag == 's')
		g_flags.exec_size = 1;
	else if (*flag == 't')
		g_flags.translation = 1;
	else
	{
		g_state = -6;
		return (0);
	}
	return (1);
}

static int		cycle_flags_short(char *flag)
{
	flag++;
	if (!*flag)
	{
		g_state = -6;
		return (0);
	}
	while (*flag)
	{
		if (!do_flag_short(flag))
			return (0);
		flag++;
	}
	return (1);
}

int				process_flag(char *flag)
{
	if (flag[0] == '-' && flag[1] != '-')
		return (cycle_flags_short(flag));
	else if (flag[0] == '-' && flag[1] == '-')
		return (do_flag_long(flag));
	return (0);
}
