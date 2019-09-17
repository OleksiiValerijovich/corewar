/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lexem_type_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:41:02 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/13 18:07:35 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm/asm.h"

char				*get_lexem_type_name(enum e_lexems lexem)
{
	static char		*designators[11] = {
		[OPERATION] = "OPERATION",
		[STRING] = "STRING",
		[COMMAND] = "COMMAND",
		[ENDLINE] = "ENDLINE",
		[LABEL] = "LABEL",
		[DIRECT_LABEL] = "DIRECT_LABEL",
		[INDIRECT_LABEL] = "INDIRECT_LABEL",
		[DIRECT] = "DIRECT",
		[INDIRECT] = "INDIRECT",
		[REGISTRY] = "REGISTRY",
		[SEPARATOR] = "SEPARATOR"
	};

	return (designators[lexem]);
}
