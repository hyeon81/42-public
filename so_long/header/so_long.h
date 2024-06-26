/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:13:20 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/09/30 12:47:03 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
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

void	value_init(t_vars *vars);
int		ft_exit(t_vars	*vars);
void	ft_exit_free(t_vars *vars);
void	ft_check_sqaure(char *line, int width);
void	ft_put_image(t_vars *vars, void *img, int x, int y);
void	error_occur(int flag, t_vars *vars);
char	*read_line(int fd, t_vars *vars);
void	check_wall_wrap(t_vars *vars);
void	check_valid(t_vars *vars, int i, int j);
void	make_map(t_vars *vars, char *m_line, int i);
void	render_map(t_vars *vars, int x, int y);
int		make_move(int keycode, t_vars *vars);
void	make_new_pos(t_vars *vars, int add_y, int add_x);
void	make_window(t_vars *vars);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
void	check_suffix(char *filename);
void	ft_free_m_line(char *m_line);
void	insert_map(t_vars *vars, char *m_line);

#endif
