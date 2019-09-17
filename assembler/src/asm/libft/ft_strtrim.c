/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:54:32 by ishyian           #+#    #+#             */
/*   Updated: 2018/12/02 23:03:13 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		ii;
	size_t		len;
	char		*trimmed;

	if (s == NULL)
		return (NULL);
	i = 0;
	ii = 0;
	len = ft_strlen(s);
	while (len != 0 &&
		(s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t'))
		len--;
	while (len != 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	trimmed = (char*)malloc(sizeof(char) * (len - i + 1));
	if (trimmed == NULL)
		return (trimmed);
	while (i < len)
		trimmed[ii++] = s[i++];
	trimmed[ii] = '\0';
	return (trimmed);
}
