/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:13:20 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/09/22 21:48:59 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	int		w;
	int		h;
	int     img_w;
	int     img_h;
	int		escape_x;
	int		escape_y;
	int     pos;
    int     pos_x;
    int     pos_y;
	int		item;
	int		get_item;
	int		move_count;
	void    *img_c;
	void	*img_e;
	void	*img_p;
	void	*img0;
	void	*img1;
    int     p;
    int     c;
    int     e;
}				t_vars;

int occur_error(int flag);
char *read_line(int fd, t_vars *vars);
void init_value(t_vars *vars);
void check_wall_wrap(t_vars *vars);
void check_valid(t_vars *vars);
void make_map(t_vars *vars, char *m_line);
void render_map(t_vars *vars);
int game_close(int keycode, t_vars* vars);
int key_hook(int keycode, t_vars *vars);
void make_move(int keycode, t_vars *vars);
void make_new_pos(t_vars *vars, int add_y, int add_x);

#endif
