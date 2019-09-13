/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:51:56 by aturuk            #+#    #+#             */
/*   Updated: 2019/08/23 11:51:57 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VM_H
# define COREWAR_VM_H

# include "../../libft/includes/libft.h"
# include "../../libft/includes/ft_printf.h"
# include "./corewar_error.h"
# include "./corewar_vz.h"
# include "./op.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>

typedef struct		s_flag
{
	int				n;
	int				a;
	int				dump;
	int				l;
	int				m;
	int				lld_size;
	int				i;
	int				v;
}					t_flag;

typedef struct		s_bot
{
	int				num;
	char			*argv;
	uint8_t			bot_file[2900];
	uint32_t		file_size;
	uint32_t		magic_header;
	uint8_t			name[PROG_NAME_LENGTH];
	uint32_t		size_exec_code;
	uint8_t			comment[COMMENT_LENGTH];
}					t_bot;

typedef struct		s_car
{
	int				num;
	uint32_t		bot_num;
	uint32_t		pos;
	int				last_live;
	uint32_t		op_id;
	int				carry;
	uint32_t		cycles_to_wait;
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
	int				last_say_live;
	int				num_of_life_tot;
	int				live_for_check;
	int				cycles_total;
	int				cycles_to_die;
	int				cycles_to_die_prev;
	int				cycles_after_check;
	int				check_count;
	int				car_process;
	uint8_t			arg_type[3];
	uint8_t			map[MEM_SIZE];
	uint8_t			map_color[MEM_SIZE];
	int				num_car;
	int				num_bot;
	t_bot			bot[4];
	t_car			*car;
	t_visualization	*vz;
	t_flag			*flag;
}					t_vm;

t_vm				*g_vm;

# define IS_BOTS1 (g_vm->bot[0].argv || g_vm->bot[1].argv ? 1 : 0)
# define IS_BOTS (IS_BOTS1 || g_vm->bot[2].argv || g_vm->bot[3].argv ? 1 : 0)

void				error_exit(int i);
void				validation_argv(int ac, char **av);
void				check_flag_dump(char **av, int *i);
void				check_flag_i_l(char **av, int *i);
void				check_flags_v_a_lld_m(char **av, int *i);
void				validation_bin_bot(void);
void				map_initialization(void);
void				war(void);
void				get_arg_type(t_car *c);
void				show_winner(void);
void				finish(void);
void				get_op(t_car *c);
void				op_live(t_car *c);
void				op_ld(t_car *c);
void				op_st(t_car *c);
void				print_map();
void				step_for_not_valid_arg_types(t_car *c, int arg_num);
void				op_sub(t_car *c);
void				op_add(t_car *c);
int					get_arg(t_car *c, int type_code, int pos, int arg_size);
void				get_all_arg(int *arg, int num_arg, t_car *c);
void				op_and(t_car *c);
void				op_or(t_car *c);
void				op_xor(t_car *c);
void				op_zjmp(t_car *c);
void				op_ldi(t_car *c);
void				op_sti(t_car *c);
void				op_fork(t_car *c);
void				op_lld(t_car *c);
void				op_lldi(t_car *c);
void				op_lfork(t_car *c);
void				op_aff(t_car *c);
void				car_position(t_car *c);
void				f_printf(t_car *c, int n_arg, int *arg);

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
