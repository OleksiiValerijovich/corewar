//
// Created by Oleksii KHERSONIUK on 2019-08-04.
//

#ifndef COREWAR_VM_H
#define COREWAR_VM_H

# include "../../libft/includes/libft.h"
# include "../../libft/includes/ft_printf.h"
# include "./corewar_error.h"
# include "./corewar_visual.h"
# include "./op.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>

# define IND		2
# define REG		1

typedef struct		s_flag
{
	int				n;//визнач. номер гравця
	int				dump;//мандаторі зупинка програми після н циклів
	int				p;//бонус пауза в NCURSES після певноЇ кількості циклів
	int				i;//інформація про гравців (в інформативному меню NCURSES)
	int				b;//бонус вивід в бінарному режимі
	int				v;//бонус вивід в режимі NCURSES
}					t_flag;

typedef struct		s_bot
{
	int				num;//порядковий номер гравця
	char			*argv;//адреса файлу гравця для зчитування бінарника
	uint8_t			bot_file[2900];// ввесь бінарних в 16-й системі числення
	uint32_t		file_size;//зчитаний розмір файлу бота
	uint32_t		magic_header;//перевірка правильності розширення
	uint8_t			name[PROG_NAME_LENGTH];//ім'я бота
	uint32_t		size_exec_code;// зчитане числове значення розміру команд
	uint8_t			comment[COMMENT_LENGTH];//комент бота
//	uint8_t			*code;//команди бота
}					t_bot;

typedef struct		s_car
{
	int				num;//the number of the car
	uint32_t		bot_num;//the number of player
	uint32_t		pos;//car position on the map
	int				last_live;//The number of the cycle in which the live operation was realized at last
	uint32_t		op_id;//operation ID (1-16)
	int				carry;// carry status (0/1)
	int 			step;// кількість буйт які потрібно буде перейти щоб опинитись на наступній операції
	int32_t			zjmp;//
	uint32_t		cycles_to_wait;//кількість циклів до моменту виконання операції на якій перебуває каретка
	uint32_t		reg[REG_NUMBER + 1];
	struct s_car	*prev;
	struct s_car	*next;
}					t_car;

typedef struct		s_op
{
	char			*name;
	uint8_t			code;
	uint8_t			num_arg;
	uint8_t			is_args_types;
	uint8_t			args_types[3];
	uint8_t			dir_size;
	int				wait;
}					t_op;

typedef struct		s_vm
{
	int				last_say_live;//гравець який останній скзав що живий
	int				num_of_life_tot;//загальна кількість виконаних операцій життя
	int				live_for_check;//кількість виконаних операцій життя змоменту останньої перевірки
	int				cycles_total;//кількість циклів з початку гри
	int				cycles_to_die;//довжина періоду до перевірки
	int				cycles_to_die_prev;// необхідна для перерахунку cysles_to_die
	int				cycles_after_check;//кількість циклів після перевірки (в межах cycles_to_die)
	int				check_count;//кількість проведених перевірок  з моменту зміни значення cycles_to_die
	int				fd[5];
	uint8_t			map[MEM_SIZE];//\/
	uint8_t			map_color[MEM_SIZE];//\/
	int				num_car;//\/
	int				num_bot;//\/
	t_bot			bot[4];
	t_car			*car;
	t_visualization	*vis;
	t_flag			*flag;
}					t_vm;

t_vm				*vm;
void				error_exit(int i);
void				validation_argv(int ac, char **av);
void				check_flag_dump_p(char **av, int *i);
void				check_flag_i(char **av, int *i);
void				check_flags_b_v(char **av, int *i);
void				validation_bin_bot(void);
void				map_initialization(void);
void				war(void);
uint8_t				*get_arg_type(t_car *c);


static t_op			g_op[17] =
		{
				{
						.name = NULL,
						.code = 0,
						.num_arg = 0,
						.is_args_types = 0,
						.args_types = {0 | 0 | 0},
						.dir_size = 0,
						.wait = 0
				},
				{
						.name = "live",
						.code = 0x01,
						.num_arg = 1,
						.is_args_types = 0,
						.args_types = {T_DIR | 0 | 0},
						.dir_size = 4,
						.wait = 10
				},
				{
						.name = "ld",
						.code = 0x02,
						.num_arg = 2,
						.is_args_types = 1,
						.args_types = {T_DIR | T_IND, T_REG, 0},
						.dir_size = 4,
						.wait = 5
				},
				{
						.name = "st",
						.code = 0x03,
						.num_arg = 2,
						.is_args_types = 1,
						.args_types = {T_REG, T_REG | T_IND, 0},
						.dir_size = 4,
						.wait = 5
				},
				{
						.name = "add",
						.code = 0x04,
						.num_arg = 3,
						.is_args_types = 1,
						.args_types = {T_REG, T_REG, T_REG},
						.dir_size = 4,
						.wait = 10
				},
				{
						.name = "sub",
						.code = 0x05,
						.num_arg = 3,
						.is_args_types = 1,
						.args_types = {T_REG, T_REG, T_REG},
						.dir_size = 4,
						.wait = 10
				},
				{
						.name = "and",
						.code = 0x06,
						.num_arg = 3,
						.is_args_types = 1,
						.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
						.dir_size = 4,
						.wait = 6
				},
				{
						.name = "or",
						.code = 0x07,
						.num_arg = 3,
						.is_args_types = 1,
						.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
						.dir_size = 4,
						.wait = 6
				},
				{
						.name = "xor",
						.code = 0x08,
						.num_arg = 3,
						.is_args_types = 1,
						.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
						.dir_size = 4,
						.wait = 6
				},
				{
						.name = "zjmp",
						.code = 0x09,
						.num_arg = 1,
						.is_args_types = 0,
						.args_types = {T_DIR, 0, 0},
						.dir_size = 2,
						.wait = 20
				},
				{
						.name = "ldi",
						.code = 0x0A,
						.num_arg = 3,
						.is_args_types = 1,
						.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
						.dir_size = 2,
						.wait = 25
				},
				{
						.name = "sti",
						.code = 0x0B,
						.num_arg = 3,
						.is_args_types = 1,
						.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
						.dir_size = 2,
						.wait = 25
				},
				{
						.name = "fork",
						.code = 0x0C,
						.num_arg = 1,
						.is_args_types = 0,
						.args_types = {T_DIR, 0, 0},
						.dir_size = 2,
						.wait = 800
				},
				{
						.name = "lld",
						.code = 0x0D,
						.num_arg = 2,
						.is_args_types = 1,
						.args_types = {T_DIR | T_IND, T_REG, 0},
						.dir_size = 4,
						.wait = 10
				},
				{
						.name = "lldi",
						.code = 0x0E,
						.num_arg = 3,
						.is_args_types = 1,
						.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
						.dir_size = 2,
						.wait = 50
				},
				{
						.name = "lfork",
						.code = 0x0F,
						.num_arg = 1,
						.is_args_types = 0,
						.args_types = {T_DIR, 0, 0},
						.dir_size = 2,
						.wait = 1000
				},
				{
						.name = "aff",
						.code = 0x10,
						.num_arg = 1,
						.is_args_types = 1,
						.args_types = {T_REG, 0, 0},
						.dir_size = 4,
						.wait = 2
				}
		};


#endif
