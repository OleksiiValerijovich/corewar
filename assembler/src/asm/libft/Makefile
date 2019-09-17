# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 14:57:31 by ishyian           #+#    #+#              #
#    Updated: 2019/09/17 12:16:25 by ishyian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libft.a
FLAGS =			-Wall -Wextra -Werror
SRCS =			get_next_line.c \
				get_next_line_endl.c \
				ft_atoi.c \
				ft_atoi_base.c \
				ft_atol.c \
				ft_atol_base.c \
				ft_atoll.c \
				ft_bzero.c \
				ft_decrement.c \
				ft_dllstadd.c \
				ft_dllstaddend.c \
				ft_dllstdel.c \
				ft_dllstdup.c \
				ft_dllstextract.c \
				ft_dllstnew.c \
				ft_dllstins.c \
				ft_dllstlen.c \
				ft_dllstmiddle.c \
				ft_dllstprint.c \
				ft_dllstswap.c \
				ft_getbitstr.c \
				ft_getbitstrr.c \
				ft_getlogfilefd.c \
				ft_getint.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_islower.c \
				ft_isnum.c \
				ft_isprint.c \
				ft_issign.c \
				ft_isspace.c \
				ft_isupper.c \
				ft_itoa.c \
				ft_itoa_base.c \
				ft_lltoa.c \
				ft_lltoa_base.c \
				ft_lstadd.c \
				ft_lstaddend.c \
				ft_lstdel.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlen.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstprint.c \
				ft_ltoa.c \
				ft_ltoa_base.c \
				ft_memalloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memchrcount.c \
				ft_memchrs.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memdup.c \
				ft_memjoin.c \
				ft_memmove.c \
				ft_memrchr.c \
				ft_memrchrs.c \
				ft_memsdel.c \
				ft_memset.c \
				ft_memstr.c \
				ft_memstrchrs.c \
				ft_numlen.c \
				ft_numlen_base.c \
				ft_printmem.c \
				ft_printmem_fd.c \
				ft_putchar.c \
				ft_putchar_fd.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putstr.c \
				ft_putstr_fd.c \
				ft_pswap.c \
				ft_quicksort.c \
				ft_quicksort_swap_items.c \
				ft_smalloc.c \
				ft_sqrt.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strchrcount.c \
				ft_strchrs.c \
				ft_strclr.c \
				ft_strcmp.c \
				ft_strcountfields.c \
				ft_strcpy.c \
				ft_strdel.c \
				ft_strdup.c \
				ft_strequ.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_strlongestwordlen.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strnequ.c \
				ft_strnew.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strrchrs.c \
				ft_strsplit.c \
				ft_strsplits_count.c \
				ft_strsplits_free.c \
				ft_strsplitlst.c \
				ft_strstr.c \
				ft_strstrchrs.c \
				ft_strsub.c \
				ft_strtolower.c \
				ft_strtoupper.c \
				ft_strtrim.c \
				ft_swap.c \
				ft_wstrlen.c \
				ft_wstrsumlen.c \
				ft_wchrlen.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_sfree.c \
				ft_uitoa_base.c \
				ft_ulltoa.c \
				ft_ulltoa_base.c \
				ft_ultoa_base.c \
				ft_unistrlen.c \
				ft_unumlen.c \
				ft_unumlen_base.c \
				ft_longexpr/ft_longexpr.c \
				ft_longexpr/ft_longexprcmp.c \
				ft_longexpr/is_valid.c \
				ft_longexpr/sum.c \
				ft_longexpr/subtraction.c \
				ft_longexpr/mult.c \
				ft_longexpr/topow.c \
				ft_longexpr/dodiv.c \
				ft_longexpr/dodiv_get_fraction.c \
				ft_longexpr/dodiv_rec_divider.c \
				ft_longexpr/modulo.c \
				ft_longexpr/compare.c \
				ft_longexpr/compare_int.c \
				ft_longexpr/res_postprocessor.c \
				ft_longexpr/set_sign.c \
				ft_printf/ft_printf.c \
				ft_printf/ft_fprintf.c \
				ft_printf/parser.c \
				ft_printf/buf.c \
				ft_printf/unicode.c \
				ft_printf/print.c \
				ft_printf/fmt_formalizer.c \
				ft_printf/fmt_form_digit.c \
				ft_printf/fmt_form_wildcard.c \
				ft_printf/fmt_form_tfmt.c \
				ft_printf/cnv_c.c \
				ft_printf/cnv_diouxxb.c \
				ft_printf/cnv_noncnv.c \
				ft_printf/cnv_p.c \
				ft_printf/cnv_s.c \
				ft_printf/cnv_f.c \
				ft_printf/cnv_f_nbr_processor.c \
				ft_printf/cnv_tfmt.c

OBJ =			$(SRCS:.c=.o)

INCLUDES =		./libft.h ./get_next_line.h

.SILENT:

all: 			$(NAME)

$(NAME): 		$(OBJ)
				ar rc $(NAME) $(OBJ)

%.o: 			%.c $(INCLUDES)
				gcc $(FLAGS) -o $@ -c $<

clean:
				rm -f $(OBJ)

fclean: 		clean
				rm -f $(NAME)

re: 			clean fclean all

.PHONY: 		all clean fclean
