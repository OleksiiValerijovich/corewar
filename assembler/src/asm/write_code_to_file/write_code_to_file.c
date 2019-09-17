/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_code_to_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:42:46 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 14:49:46 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../../inc/asm/asm.h"
#include "../../../inc/asm/write_code_to_file.h"

static int			open_new_file(char *filename)
{
	int				fd;

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
		g_data.error = 1;
	else if (read(fd, NULL, 0) < 0)
		g_data.error = 1;
	return (fd);
}

static char			*get_new_filename(void)
{
	char			*new_filename;
	int				filename_len;
	char			*last_dot;

	last_dot = ft_strrchr(g_data.filename, '.');
	if (last_dot)
	{
		filename_len = last_dot - g_data.filename + 1;
		new_filename = ft_smalloc(filename_len + 5);
		new_filename[filename_len + 4] = '\0';
		ft_memmove(new_filename, g_data.filename, filename_len - 1);
		ft_memmove(new_filename + filename_len - 1, ".cor", 4);
	}
	else
		new_filename = ft_strjoin(g_data.filename, ".cor");
	return (new_filename);
}

void				write_code_to_file(void)
{
	t_file_data		file_data;

	ft_bzero(&file_data, sizeof(t_file_data));
	file_data.magic = COREWAR_EXEC_MAGIC;
	file_data.filename = get_new_filename();
	file_data.fd = open_new_file(file_data.filename);
	file_data.prog_size = g_data.exec_size;
	check_string_lens();
	if (!g_data.error)
	{
		ft_memcpy(file_data.prog_name, g_data.champ_name + 1,
			ft_strlen(g_data.champ_name) - 2);
		ft_memcpy(file_data.comment, g_data.comment + 1,
			ft_strlen(g_data.comment) - 2);
		write_it(&file_data);
	}
	free(file_data.filename);
}
