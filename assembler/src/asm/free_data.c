/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:48:15 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 23:22:02 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/asm/asm.h"

void			free_data(void)
{
	ft_lstdel(&g_data.src_buff_list, &ft_memsdel);
	free(g_data.src_file);
	ft_dllstdel(&g_data.lexems, &ft_memsdel);
	ft_dllstdel(&g_data.lines, &ft_memsdel);
	free(g_data.champ_name);
	free(g_data.comment);
	ft_bzero(&g_data, sizeof(t_data));
}
