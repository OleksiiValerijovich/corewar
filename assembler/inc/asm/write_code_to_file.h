/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_code_to_file.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 01:57:01 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 03:34:48 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE_CODE_TO_FILE_H
# define WRITE_CODE_TO_FILE_H
# define PROG_NAME_LENGTH (128)
# define COMMENT_LENGTH (2048)
# define COREWAR_EXEC_MAGIC 0xea83f3

# include "./asm.h"

typedef struct			s_file_data
{
	char				*filename;
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
	int					fd;
}						t_file_data;

void					write_big_endian(int fd, void *data, size_t size);
void					write_it(t_file_data *file_data);
void					check_string_lens(void);

#endif
