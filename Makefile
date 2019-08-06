NAME	=	corewar

SRC_F	=	main.c \
			validation_bin_bot.c

SRC = $(addprefix ./src/vm/, $(SRC_F))

OBJ_F 	=	main.o \
			validation_bin_bot.o

OBJ_DIR =	./obj/

OBJ = $(addprefix ./obj/, $(OBJ_F))

LIB_DIR = ./libft

HEADER = ./includes/vm/corewar_vm.h

FLAGS = -Wall -Wextra -Werror -g -O3

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER)
	 	#@make -C $(LIB_DIR)
		@gcc $(OBJ) -o $(NAME) $(FLAGS) -L $(LIB_DIR) -lft

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(addprefix ./obj/, %.o): $(addprefix ./src/vm/, %.c)
		@gcc -o $@ -c $< $(FLAGS)

lib:
	#@make -C $(LIB_DIR) re
clean:
	#@make -C $(LIB_DIR) clean
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	#@make -C $(LIB_DIR) fclean
	@rm -f $(NAME)

re: fclean all
