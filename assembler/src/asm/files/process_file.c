/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:24:44 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 15:39:49 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "../../../inc/asm/asm.h"

static void			buff_to_single_line(t_list *src_buff_list)
{
	size_t		curr;

	g_data.src_total_size++;
	g_data.src_file = ft_smalloc(g_data.src_total_size);
	g_data.src_file[g_data.src_total_size - 1] = '\0';
	curr = 0;
	while (src_buff_list)
	{
		ft_memmove(g_data.src_file + curr, src_buff_list->content,
		src_buff_list->content_size);
		curr = curr + src_buff_list->content_size;
		src_buff_list = src_buff_list->next;
	}
}

static void			read_file_to_buff(int fd, t_list **src_buff_list)
{
	char		*line;
	t_list		*buff_line;

	while (get_next_line_endl(fd, &line) == 1)
	{
		buff_line = ft_smalloc(sizeof(t_list));
		ft_bzero(buff_line, sizeof(t_list));
		buff_line->content = line;
		buff_line->content_size = ft_strlen(line);
		ft_lstaddend(src_buff_list, buff_line);
		g_data.src_total_size = g_data.src_total_size + buff_line->content_size;
		g_data.src_lines_num++;
	}
}

static int			open_file(char *filename, int *file_is_ok)
{
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		*file_is_ok = -2;
	else if (read(fd, NULL, 0) < 0)
		*file_is_ok = -3;
	return (fd);
}

void				process_file(char *filename)
{
	int			fd;
	int			file_is_ok;

	file_is_ok = 1;
	fd = open_file(filename, &file_is_ok);
	if (file_is_ok == 1)
	{
		read_file_to_buff(fd, &g_data.src_buff_list);
		buff_to_single_line(g_data.src_buff_list);
		g_data.filename = filename;
		fsm_lexical_analysis();
		if (!g_data.error)
			fsm_syntax_analysis();
		if (!g_data.error)
			translation();
		if (!g_data.error)
			write_code_to_file();
		display_error_count();
		options();
		free_data();
	}
	else
		error_processor(&file_is_ok, filename);
	close(fd);
}
