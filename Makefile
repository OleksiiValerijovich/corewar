NAME	=	corewar

SRC_F	=	main.c \
			validation_argv.c \
			validation_bin_bot.c

SRC = $(addprefix ./src/, $(SRC_F))

OBJ_F 	=	main.o \
			validation_argv.o \
			validation_bin_bot.o

OBJ_DIR =	./obj/

OBJ = $(addprefix ./obj/, $(OBJ_F))

LIB = ./libft
LIB_OBJ = ./libft/*.o

HEADER = ./includes/corewar_vm.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER)
	 	@make -C $(LIB)
		@gcc $(OBJ) $(LIB_OBJ) -o $(NAME) -O3 $(FLAGS)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(addprefix ./obj/, %.o): $(addprefix ./src/, %.c)
		@gcc -o $@ -c $< -O3 $(FLAGS)

lib:
	@make -C $(LIB) re
clean:
	@make -C $(LIB) clean
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIB) fclean
	@rm -f $(NAME)

re: fclean all
