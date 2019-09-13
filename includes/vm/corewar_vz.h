/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vz.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aturuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:28:36 by aturuk            #+#    #+#             */
/*   Updated: 2019/08/06 12:28:37 by aturuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VZ_H
# define COREWAR_VZ_H

# include <ncurses.h>

typedef struct		s_visualization
{
	WINDOW			*map;
	WINDOW			*menu;
	int				speed;
	int				keycode;
}					t_visualization;

void				end_exit(void);
void				main_vz(void);
void				init_vz(void);
void				init_color_pairs(void);
void				print_players(void);

#endif
