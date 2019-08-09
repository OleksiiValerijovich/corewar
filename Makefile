NAME	=	corewar

SRC_F	=	main.c \
			validation_argv1.c \
			validation_argv2.c \
			validation_bin_bot.c \
			map_initialization.c \
			op_functions_help.c \
			war.c \
			op_live.c \

SRC = $(addprefix ./src/vm/, $(SRC_F))

OBJ_F 	=	main.o \
			validation_argv1.o \
			validation_argv2.o \
			validation_bin_bot.o \
			map_initialization.o \
			op_functions_help.o \
			war.o \
			op_live.c \

OBJ_DIR =	./obj/

OBJ = $(addprefix ./obj/, $(OBJ_F))

LIB_DIR = ./libft

HEADER = ./includes/vm/corewar_vm.h

FLAGS = -Wall -Wextra -Werror -g -O3

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER)
	 	@make -C $(LIB_DIR)
		@gcc $(OBJ) -o $(NAME) $(FLAGS) -L $(LIB_DIR) -lft

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(addprefix ./obj/, %.o): $(addprefix ./src/vm/, %.c)
		@gcc -o $@ -c $< $(FLAGS)

lib:
	@make -C $(LIB_DIR) re
clean:
	@make -C $(LIB_DIR) clean
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -f $(NAME)

re: fclean all
