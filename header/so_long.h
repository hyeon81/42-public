/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:13:20 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/09/26 17:29:21 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	int		w;
	int		h;
	int		escape_x;
	int		escape_y;
	int		pos_x;
	int		pos_y;
	int		get_item;
	int		move_count;
	void	*img_c;
	void	*img_e;
	void	*img_p;
	void	*img0;
	void	*img1;
	int		p;
	int		c;
	int		e;
}				t_vars;

void	ft_exit_free(t_vars	*var);
void	check_square(t_vars *vars);
void	ft_put_image(t_vars *vars, void *img, int x, int y);
int		error_occur(int flag);
char	*read_line(int fd, t_vars *vars);
void	check_wall_wrap(t_vars *vars);
void	check_valid(t_vars *vars, int i, int j);
void	make_map(t_vars *vars, char *m_line, int i, int j);
void	render_map(t_vars *vars, int x, int y);
int		game_close(int keycode, t_vars	*vars);
int		make_move(int keycode, t_vars *vars);
void	make_new_pos(t_vars *vars, int add_y, int add_x);
void	make_window(t_vars *vars);

#endif
