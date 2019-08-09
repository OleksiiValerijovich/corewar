/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 09:21:21 by aturuk            #+#    #+#             */
/*   Updated: 2019/03/02 09:21:23 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_c(t_lst *pf, unsigned char c)
{
	MINUS_FLG != '-' ? print_width(pf, 1) : 0;
	write(1, &c, 1);
	pf->len_out += 1;
	MINUS_FLG == '-' ? print_width(pf, 1) : 0;
}

static void	print_lc_2b(unsigned int bin_uni, t_lst *pf)
{
	unsigned int copy;
	unsigned int first;
	unsigned int second;

	copy = bin_uni;
	first = 0b11000000;
	second = 0b10000000;
	first = first | (copy >> 6);
	second = second | (bin_uni & 0b111111);
	write(1, &first, 1);
	write(1, &second, 1);
	pf->len_out += 2;
}

static void	print_lc_3b(unsigned int bin_uni, t_lst *pf)
{
	unsigned int copy;
	unsigned int first;
	unsigned int second;
	unsigned int third;

	copy = bin_uni & 0b1111000000000000;
	first = 0b11100000;
	second = 0b10000000;
	third = 0b10000000;
	first = first | (copy >> 12);
	copy = bin_uni & 0b111111000000;
	second = second | (copy >> 6);
	copy = bin_uni & 0b111111;
	third = third | copy;
	write(1, &first, 1);
	write(1, &second, 1);
	write(1, &third, 1);
	pf->len_out += 3;
}

static void	print_lc_4b(unsigned int bin_uni, t_lst *pf)
{
	unsigned int copy;
	unsigned int first;
	unsigned int second;
	unsigned int third;
	unsigned int fourth;

	copy = bin_uni & 0b111111000000000000000000;
	first = 0b11110000;
	second = 0b10000000;
	third = 0b10000000;
	fourth = 0b10000000;
	first = first | (copy >> 18);
	copy = bin_uni & 0b111111000000000000;
	second = second | (copy >> 12);
	copy = bin_uni & 0b111111000000;
	third = third | (copy >> 6);
	copy = bin_uni & 0b111111;
	fourth = fourth | copy;
	write(1, &first, 1);
	write(1, &second, 1);
	write(1, &third, 1);
	write(1, &fourth, 1);
	pf->len_out += 4;
}

void		print_lc(t_lst *pf, wchar_t uni)
{
	if (uni <= 127 || (MB_CUR_MAX == 1 && MB_CUR_MAX <= 255))
		print_c(pf, (unsigned char)uni);
	else if (uni > 127 && uni <= 2047)
	{
		pf->width > 2 && MINUS_FLG != '-' ? print_width(pf, 2) : 0;
		print_lc_2b(uni, pf);
		pf->width > 2 && MINUS_FLG == '-' ? print_width(pf, 2) : 0;
	}
	else if (uni > 2047 && uni <= 65535)
	{
		pf->width > 3 && MINUS_FLG != '-' ? print_width(pf, 3) : 0;
		print_lc_3b(uni, pf);
		pf->width > 3 && MINUS_FLG == '-' ? print_width(pf, 3) : 0;
	}
	else
	{
		pf->width > 4 && MINUS_FLG != '-' ? print_width(pf, 4) : 0;
		print_lc_4b(uni, pf);
		pf->width > 4 && MINUS_FLG == '-' ? print_width(pf, 4) : 0;
	}
}
