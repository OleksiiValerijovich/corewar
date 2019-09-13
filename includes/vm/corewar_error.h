/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_error.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:23:58 by aturuk            #+#    #+#             */
/*   Updated: 2019/08/06 12:24:00 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_ERROR_H
# define COREWAR_ERROR_H

# define MEMORY "ERROR. Can't allocate memory.\n"
# define ARGV_INVAL "ERROR. Invalid arguments.\n"
# define FLG_PLACE "ERROR. Invalid placement of arguments.\n"
# define FLG_DUMP_EXISTS "ERROR. Flag [-dump <nbr_cycles>] already exists.\n"
# define FLG_DUMP_N "ERROR. Missing / inv. <nbr_cycles> in the flag [-dump].\n"
# define FLG_P_EXISTS "ERROR. Flag [-p <nbr_cycles>] already exists.\n"
# define FLG_P_N "ERROR. Missing / invalid <nbr_cycles> in the flag [-p].\n"
# define FLG_I_EXISTS "ERROR. Flag [-i <nbr>] already exists.\n"
# define FLG_I_N "ERROR. Missing / invalid number in the flag [-i <nbr>].\n"
# define FLG_A_EXISTS "ERROR. Flag [-a] already exists.\n"
# define FLG_M_EXISTS "ERROR. Flag [-m] already exists.\n"
# define FLG_L_EXISTS "ERROR. Flag [-l] already exists.\n"
# define FLG_V_EXISTS "ERROR. Flag [-v] already exists.\n"
# define FLG_LLD_SIZE_EXISTS "ERROR. Flag [-lld_size] already exists.\n"
# define FLG_N_INVAL "ERROR. Missing / invalid number of the next champion.\n"
# define FLG_V_AND_OTHER2 "| [-m] | [-l] | [-i] can't exist together.\n"
# define FLG_V_AND_OTHER "ERROR. Flags [-v] and [-a] | [-dump] %s"
# define CHAMP_INVAL "ERROR. Missing / invalid champion.\n"
# define CHAMP_MAX "ERROR. Too many champions.\n"
# define EMPTY_BOT_FILE "ERROR. The file that was send is empty.\n"
# define TOO_LARGE_BOT_FILE "ERROR. The file, %s, is larger for %d.\n"
# define WRONG_MAGIC_HEADER "ERROR. The magic header is wrong.\n"
# define INCORRECT_NULL "ERROR. It is no NULL space in the file.\n"
# define INCORRECT_COR_FILE "ERROR. File %s is incorrect.\n"

#endif
