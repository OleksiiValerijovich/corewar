/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:45:37 by ishyian           #+#    #+#             */
/*   Updated: 2019/04/15 12:45:39 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_longexpr.h"

static int		divide_validator(char op, const char *b_arg)
{
	if (op == '/')
		if (compare_int(b_arg, '=', "0"))
		{
			ft_printf("ft_longexpr: Error: Divide by zero\n");
			return (0);
		}
	if (op == '%')
		if (compare_int(b_arg, '=', "0"))
		{
			ft_printf("ft_longexpr: Error: Modulo by zero\n");
			return (0);
		}
	return (1);
}

static int		operator_validator(char op)
{
	if (ft_strchr(VALID_OPERATORS, op))
		return (1);
	return (0);
}

static int		argument_validator(const char *x_arg)
{
	if (!ft_issign(*x_arg) && !ft_isdigit(*x_arg))
		return (0);
	x_arg++;
	while (*x_arg)
	{
		if (!ft_isdigit(*x_arg) && *x_arg != '.')
			return (0);
		x_arg++;
	}
	return (1);
}

int				is_valid(const char *a_arg, char op, const char *b_arg)
{
	if (!a_arg || !b_arg)
	{
		ft_printf("ft_longexpr: Error: At least one argument is NULL!\n");
		return (0);
	}
	else if (!argument_validator(a_arg) || !argument_validator(b_arg))
	{
		ft_printf("ft_longexpr: Error: At least one argument is invalid. \
Argument may contain only decimal digits, one point and sign!\n");
		return (0);
	}
	else if (!operator_validator(op))
	{
		ft_printf("ft_longexpr: Error: Operator is unsupported. \
Operator may be one of the \"%s\"!\n", VALID_OPERATORS);
		return (0);
	}
	else if (!divide_validator(op, b_arg))
		return (0);
	return (1);
}
