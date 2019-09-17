/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:31:05 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/15 13:12:46 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

enum				e_operations
{
	OPERATION_LIVE = 0x01,
	OPERATION_LD,
	OPERATION_ST,
	OPERATION_ADD,
	OPERATION_SUB,
	OPERATION_AND,
	OPERATION_OR,
	OPERATION_XOR,
	OPERATION_ZJMP,
	OPERATION_LDI,
	OPERATION_STI,
	OPERATION_FORK,
	OPERATION_LLD,
	OPERATION_LLDI,
	OPERATION_LFORK,
	OPERATION_AFF
};

#endif
