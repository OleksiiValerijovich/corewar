/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:52:03 by aturuk            #+#    #+#             */
/*   Updated: 2018/12/28 10:59:35 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*check_list(int fd, t_list **gnl)
{
	t_list *check;

	if (*gnl == NULL)
	{
		*gnl = ft_lstnew(NULL, 0);
		(*gnl)->content_size = (size_t)fd;
		return (*gnl);
	}
	check = *gnl;
	while (check != NULL)
	{
		if (check->content_size == (size_t)fd)
			return (check);
		check = check->next;
	}
	check = ft_lstnew(NULL, 0);
	check->content_size = (size_t)fd;
	ft_lstadd(gnl, check);
	return (*gnl);
}

static int		filling(char **line, t_list **list)
{
	char		*tail;
	int			n;

	n = 0;
	if (((*list)->content) == NULL || !(ft_strlen((*list)->content)))
		return (0);
	tail = (*list)->content;
	while (tail[n] != '\n' && tail[n] != '\0')
		n++;
	*line = ft_strsub(tail, 0, n);
	tail = ft_strdup(tail + (tail[n] == '\n' ? n + 1 : n));
	free((*list)->content);
	(*list)->content = ft_strdup(tail);
	free(tail);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*gnl;
	t_list			*list;
	int				res;
	char			*buffer;
	char			*ptr;

	if (BUFF_SIZE < 1 || fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	list = check_list(fd, &gnl);
	buffer = (char *)malloc(sizeof(buffer) * (BUFF_SIZE + 1));
	while ((res = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[res] = '\0';
		ptr = list->content;
		list->content = ft_strjoin(list->content, buffer);
		free(ptr);
		if (ft_strchr(list->content, '\n') != NULL)
			break ;
	}
	free(buffer);
	return (filling(line, &list));
}
