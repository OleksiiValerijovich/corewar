/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:53:25 by ishyian           #+#    #+#             */
/*   Updated: 2019/03/14 22:05:12 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./ft_printf.h"

static void		*release_buff(char *buff, size_t *free_buff)
{
	print(buff, BUFF_SIZE - *free_buff);
	*free_buff = BUFF_SIZE;
	free(buff);
	return (NULL);
}

void			buf(const void *s, size_t size)
{
	static char			*buff;
	static size_t		free_buff = BUFF_SIZE;

	if (!buff)
		buff = malloc(BUFF_SIZE);
	if (!s)
		buff = release_buff(buff, &free_buff);
	else
		while (size)
		{
			if (size >= free_buff)
			{
				print(buff, BUFF_SIZE - free_buff);
				free_buff = BUFF_SIZE;
				print(s, size);
				size = 0;
			}
			else
			{
				ft_memmove((buff + (BUFF_SIZE - free_buff)), s, size);
				free_buff -= size;
				size = 0;
			}
		}
}

static size_t	filler(char *s, char c, size_t *count)
{
	static t_fill		fill;
	size_t				len;

	len = *count - (*count % FILL_SIZE);
	ft_memset(&fill, c, FILL_SIZE);
	while (*count >= FILL_SIZE)
	{
		*((t_fill*)s) = fill;
		s = s + FILL_SIZE;
		*count = *count - FILL_SIZE;
	}
	return (len);
}

void			chr_to_buf(char c, size_t count)
{
	char				*s;

	if (count >= FILL_SIZE)
	{
		s = ft_smalloc(count - (count % FILL_SIZE));
		buf(s, filler(s, c, &count));
		free(s);
	}
	if (count >= BUFF_SIZE)
	{
		s = ft_smalloc(count);
		ft_memset(s, c, count);
		buf(s, count);
		free(s);
	}
	else
		while (count-- > 0)
			buf(&c, 1);
}

void			buf_print(void)
{
	buf(NULL, 0);
}
