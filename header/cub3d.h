/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:29:45 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/17 18:32:45 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define ON_DESTROY 17
# define WIDTH 800
# define HEIGHT 800
# define TEX_W 64
# define TEX_H 64
# define TILE_SIZE 10

enum e_spawn {
	N,
	S,
	W,
	E
};

typedef struct s_img
{
	void		*ptr;
	int			*data;
	int			width;
	int			height;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct s_coord
{
	double	x;
	double	y;
}t_coord;

typedef struct s_raycast
{
	t_coord	*pos;
	t_coord	*dir;
	t_coord	*plane;
	t_coord	side_dist;
	t_coord	delta_dist;
	t_coord	step;
	t_coord	ray_dir;
	int		map_x;
	int		map_y;
	double	camera_x;
	int		side;
	double	prep_dist;
	int		line_h;
	int		start;
	int		end;
	int		tex_x;
}t_raycast;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	map_img;
	int		**tex;
	t_coord	pos;
	t_coord	dir;
	t_coord	plane;
	int		direction;
	int		row;
	int		col;
	int		f_color;
	int		c_color;
}t_vars;

static int worldMap[24][24]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

/* cub3d.c */
void	main_loop(t_vars *v);

/* calc.c */
void	init_loop_vars(t_raycast *r, int x);
void	calc_step_side_dist(t_raycast *r);
void	shoot_ray(t_raycast *r);
void	clac_draw_line(t_raycast *r);
void	calc_ray(t_raycast *r, int x);

/* draw.c */
void	clac_draw_line(t_raycast *r);
void	calc_tex_x(t_raycast *r);
void	set_map(t_raycast *r, int x, t_img *map_img, int **tex);
void	set_background(t_img *map_img, int floor, int ceiling);
void	set_draw(t_raycast *r);

/* init.c */
void	init_vars(t_vars *v);
void	load_tex(t_vars *v);

/* move.c */
int		ft_exit(t_vars *vars);
int		make_move(int keycode, t_vars *v);

/* minimap */
void	make_draw_minimap(t_vars *v);

/* utils */
void	set_coord(t_coord *v, double x, double y);
void	ft_free(int **arr, int idx);

#endif
