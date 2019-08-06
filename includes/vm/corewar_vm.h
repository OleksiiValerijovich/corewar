//
// Created by Oleksii KHERSONIUK on 2019-08-04.
//

#ifndef COREWAR_VM_H
#define COREWAR_VM_H

# include "../../libft/libft.h"
# include "op.h"
# include "visualization.h"
# include "exit_header.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>


# define IND		2
# define REG		1


typedef struct		s_flag
{
    int             b;//бонус вивід в бінарному режимі
    int             v;//бонус вивід в режимі NCURSES
    int             dump;//мандаторі зупинка програми після н циклів
    int             s;//бонус пауза в NCURSES після певноЇ кількості циклів
    int             i;//інформація про гравців (в інформативному меню NCURSES)
    int 			e;//error_manager mod activated
}                   t_flag;


typedef struct		s_bot
{
    int				num;//порядковий номер гравця
    char 			*argv;//адреса файлу гравця для зчитування бінарника
    uint8_t			bot_file[5000];// ввесь бінарних в 16-й системі числення
    uint32_t		file_size;//зчитаний розмір файлу бота
    uint32_t		*magic_header;//перевірка правильності розширення
    uint8_t			name[PROG_NAME_LENGTH];//ім'я бота
    uint32_t		size;// зчитане числове значення розміру команд
    uint8_t			comment[COMMENT_LENGTH];//комент бота
    uint8_t			*code;//команди бота
}					t_bot;

typedef struct		s_car
{
    int				zjmp;
    int				id;
    int				carry;
    uint32_t		pos;
    uint32_t		op_id;
    uint32_t		bot_id;
    int				live;
    uint32_t		cicles_to_wait;
    uint32_t		reg[REG_NUMBER + 1];
    struct s_car	*next;
    struct s_car	*back;
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
    int				nbr_cycles;
    int				v_fl;
    int				a_fl;
    int				lld_fl;
    int				leaks_fl;
    int				oct64_fl;
    int				ncurs;
    int				fd[5];
    uint8_t			map[MEM_SIZE];
    uint8_t			inf_vis[MEM_SIZE];
    int				last_say_live;
    int				cycles_from_start;
    int				cycles_after_check;
    int				cycles_to_die;
    int				cycles_to_die_prev;
    int				num_of_life;
    int				check_count;
    int				num_kar;
    int				num_bot;
    t_bot			*bot[4];
    t_car			*car;
    t_visualization	*vis;
    t_flag          flag;
}					t_vm;

t_vm                *vm;
void				validation_bin_bot(void);



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

#endif //COREWAR_COREWAR_VM_H
