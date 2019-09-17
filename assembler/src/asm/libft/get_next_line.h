/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:00:07 by ishyian           #+#    #+#             */
/*   Updated: 2019/05/21 15:56:14 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define META_SIZE (sizeof(int) + sizeof(long))
# define DATA lst->content
# define DATA_SIZE (META_SIZE + BUFF_SIZE)
# define STR (lst->content + META_SIZE)
# define STR_SIZE *(long*)(lst->content + sizeof(int))
# define LINE_SIZE lst->content_size
# define FD *(int*)(lst->content + 0)
# define FD_NEXT *(int*)(lst->next->content + 0)
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
#endif
