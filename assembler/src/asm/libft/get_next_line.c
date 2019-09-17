/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:52:37 by ishyian           #+#    #+#             */
/*   Updated: 2019/06/21 19:14:56 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include "./libft.h"

static void			wr_to_line(t_list *lst, char **line, long size, int *state)
{
	char			*tmp;

	if (LINE_SIZE == 0)
		*line = ft_memdup(STR, size);
	else
	{
		tmp = *line;
		*line = ft_memjoin(*line, LINE_SIZE, STR, size);
		free(tmp);
	}
	LINE_SIZE += size;
	tmp = *line;
	*line = ft_memjoin(*line, LINE_SIZE, "\0", 1);
	if (*line == NULL)
		*state = -1;
	free(tmp);
}

static void			rd_from_fd(t_list *lst, char **line, int *state)
{
	long			next;

	next = 0;
	while (STR_SIZE && !next && *state != -1)
	{
		if (STR_SIZE != -1 && ft_memchr(STR, '\n', STR_SIZE))
			next = (ft_memchr(STR, '\n', STR_SIZE)) - STR + 1;
		if (STR_SIZE != -1)
			wr_to_line(lst, line, (next ? next - 1 : STR_SIZE), state);
		if (next && next < STR_SIZE)
			ft_memmove(STR, STR + next, STR_SIZE - next);
		if (!next)
			STR_SIZE = read(FD, STR, BUFF_SIZE);
	}
	if ((!next && STR_SIZE == 0 && LINE_SIZE == 0 && *state != -1))
		*state = 0;
	STR_SIZE = (!next || !(STR_SIZE - next)) ? -1 : STR_SIZE - next;
	LINE_SIZE = 0;
}

static void			rm_lst(int fd, t_list *lst, t_list **first)
{
	t_list			*to_del;

	to_del = NULL;
	while (lst && FD != fd && lst->next && lst->next->content && FD_NEXT != fd)
		lst = lst->next;
	if (lst)
	{
		if (lst && FD == fd)
		{
			to_del = lst;
			*first = lst->next;
		}
		else if (lst->next && lst->next->content && FD_NEXT == fd)
		{
			to_del = lst->next;
			lst->next = lst->next->next;
		}
		if (to_del->content)
			free(to_del->content);
		free(to_del);
	}
}

static t_list		*get_fd_lst(const int fd, t_list *lst, t_list *first)
{
	while (lst && FD != fd)
		lst = lst->next;
	if (!lst)
	{
		lst = ft_lstnew(NULL, 0);
		if (!lst)
			return (NULL);
		DATA = ft_memalloc(DATA_SIZE);
		if (!DATA)
		{
			free(lst);
			return (NULL);
		}
		ft_lstaddend(&first, lst);
		STR_SIZE = -1;
		LINE_SIZE = 0;
		FD = fd;
	}
	return (lst);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_list			*current;
	int				state;

	if (fd < 0 || !line || (read(fd, 0, 0)) < 0 || BUFF_SIZE < 1)
		return (-1);
	state = 1;
	*line = NULL;
	if (!lst)
		lst = get_fd_lst(fd, lst, lst);
	current = get_fd_lst(fd, lst, lst);
	if (lst != NULL && current != NULL)
		rd_from_fd(current, line, &state);
	else
		state = -1;
	if (state == -1 || state == 0)
	{
		rm_lst(fd, lst, &lst);
		free(*line);
		*line = NULL;
	}
	return (state);
}
