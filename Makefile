NAME	=	corewar

SRC_F	=	main.c \
			validation_argv1.c \
			validation_argv2.c \
			validation_bin_bot.c \
			map_initialization.c \
			op_functions_help.c \
			f_printf.c \
			war.c \
			finish.c \
			op_live.c \
			op_ld.c \
			print_map.c \
			op_st.c \
			op_add.c \
			op_sub.c \
			op_and.c \
			op_or.c \
			op_xor.c \
			op_zjmp.c \
			op_ldi.c \
			op_sti.c \
			op_fork.c \
			op_lld.c \
			op_lldi.c \
			op_lfork.c \
			op_aff.c \
			main_vz.c \
			help_vz.c


SRC = 		$(addprefix ./src/, $(SRC_F))

OBJ_F 	=	main.o \
			validation_argv1.o \
			validation_argv2.o \
			validation_bin_bot.o \
			map_initialization.o \
			op_functions_help.o \
			f_printf.o \
			war.o \
			op_live.o \
			finish.o \
			op_ld.o \
			print_map.o \
			op_st.o \
			op_add.o \
			op_sub.o \
			op_and.o \
			op_or.o \
			op_xor.o \
			op_zjmp.o \
			op_ldi.o \
			op_sti.o \
			op_fork.o \
			op_lld.o \
			op_lldi.o \
			op_lfork.o \
			op_aff.o \
			main_vz.o \
			help_vz.o

OBJ_DIR =	./obj/

OBJ = 		$(addprefix ./obj/, $(OBJ_F))

LIB_DIR = 	./libft

HEADER = 	./includes/vm/corewar_vm.h\
			./includes/vm/op.h\
			./includes/vm/corewar_vz.h\
			./includes/vm/corewar_error.h

ASM_DIR = 	./assembler

FLAGS = 	-Wall -Wextra -Werror -g -O3

all: 		assembler $(NAME)

assembler:
			@make -C $(ASM_DIR)

$(NAME): 	$(OBJ_DIR) $(OBJ) $(HEADER)
#			@make -C $(LIB_DIR)
			@gcc $(OBJ) -o $(NAME) $(FLAGS) -L $(LIB_DIR) -lft -lncurses

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

$(addprefix ./obj/, %.o): $(addprefix ./src/, %.c) $(HEADER)
			@gcc -o $@ -c $< $(FLAGS)

#lib:
#			@make -C $(LIB_DIR) re

clean:
#			@make -C $(LIB_DIR) clean
			@make -C $(ASM_DIR) clean
			@rm -f $(OBJ)
			@rm -rf $(OBJ_DIR)

fclean: 	clean
#			@make -C $(LIB_DIR) fclean
			@make -C $(ASM_DIR) fclean
			@rm -f $(NAME)

re: 		fclean all

.PHONY: 	all libft clean fclean re assembler
