# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aturuk <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/02 09:25:50 by aturuk            #+#    #+#              #
#    Updated: 2019/03/02 09:25:51 by aturuk           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
WWW_FLAGS = -Wall -Wextra -Werror
INC = -I ./includes/

SRCS_LIBFT =	ft_atoi.c			ft_bzero.c			ft_isascii.c \
				ft_isalpha.c		ft_isalnum.c		ft_isdigit.c \
				ft_isprint.c		ft_lstadd.c			ft_lstadd_end.c \
				ft_lstadd_mid.c		ft_lstdelone.c		ft_lstdel.c \
				ft_lstiter.c		ft_lstnew.c			ft_lstmap.c \
				ft_memalloc.c		ft_memchr.c			ft_memccpy.c \
				ft_memcmp.c			ft_memdel.c			ft_memcpy.c \
				ft_itoa.c			ft_putchar.c		ft_putchar_fd.c \
				ft_putendl.c		ft_putendl_fd.c		ft_memmove.c \
				ft_putstr.c			ft_memset.c			ft_putstr_fd.c \
				ft_replace_chr.c	ft_putnbr_fd.c		ft_putnbr.c \
				ft_strchr.c			ft_strcat.c			ft_strclr.c \
				ft_strcmp.c			ft_strdup.c			ft_strdel.c \
				ft_striteri.c		ft_strcpy.c			ft_striter.c \
				ft_strequ.c			ft_strlen.c			ft_strlen_chr.c \
				ft_strjoin.c		ft_strjoin_free.c	ft_strlcat.c \
				ft_strncmp.c		ft_strmap.c			ft_strncat.c \
				ft_strmapi.c		ft_strncpy.c		ft_strnequ.c \
				ft_strnstr.c		ft_strnew.c			ft_strrchr.c \
				ft_tolower.c		ft_toupper.c		ft_strstr.c \
				ft_strtrim.c		ft_strsub.c			ft_strsplit.c \
				ft_numlen.c			ft_free_2d_array.c	ft_count_ch_in_str.c \
				ft_strlen_2d_array.c					ft_is_positive_int.c

SRCS_GNL =		get_next_line.c

SRCS_PRINTF =	ft_printf.c					analyze.c \
				find_type.c					apply_flags.c \
				print_character.c			print_string.c \
				print_signed_integer.c		print_unsigned_integer.c \
				print_octal.c				print_pointer_address.c \
				print_hexadecimal.c			print_float_prt1.c \
				print_float_prt2.c

DIR_SRCS = ./resources
ALL_SRCS =	$(addprefix $(DIR_SRCS)/srcs_libft/, $(SRCS_LIBFT)) \
			$(addprefix $(DIR_SRCS)/srcs_gnl/, $(SRCS_GNL)) \
	   		$(addprefix $(DIR_SRCS)/srcs_printf/, $(SRCS_PRINTF)) \

DIR_OSRCS  = ./tmp
OSRCS = $(addprefix $(DIR_OSRCS)/srcs_libft/, $(SRCS_LIBFT:.c=.o)) \
		$(addprefix $(DIR_OSRCS)/srcs_gnl/, $(SRCS_GNL:.c=.o)) \
	   	$(addprefix $(DIR_OSRCS)/srcs_printf/, $(SRCS_PRINTF:.c=.o)) \

all:	$(NAME)
		
$(NAME):$(OSRCS)
		@ar rc $(NAME) $(OSRCS)
		@ranlib $(NAME)
		@echo "\033[32m$(NAME) created.\033[0m"

$(DIR_OSRCS)/%.o: $(DIR_SRCS)/%.c
		@mkdir -p `dirname $@`
		@gcc -c $(WWW_FLAGS) $(INC) $< -o $@

clean:
		@/bin/rm -rf $(DIR_OSRCS)
		@echo "\033[32mObject files ($(NAME)) removed.\033[0m"

fclean:	clean
		@/bin/rm -rf $(NAME)
		@echo "\033[32m$(NAME) removed.\033[0m"

re:		fclean all
