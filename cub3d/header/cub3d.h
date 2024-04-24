/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:38:34 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/23 14:22:22 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../get_next_line/get_next_line.h"

# define ERROR -1

# define ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_PRESS 2
# define ON_DESTROY 17
# define WIDTH 800
# define HEIGHT 800
# define TEX_W 64
# define TEX_H 64

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

typedef struct s_player
{
	t_coord	pos;
	t_coord	dir;
	t_coord	plane;
	int		direction;
}t_player;

typedef struct s_color
{	
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor_color;
	int		ceiling_color;
}t_color;

typedef struct s_raycast
{
	t_player	*p;
	t_coord		side_dist;
	t_coord		delta_dist;
	t_coord		step;
	t_coord		ray_dir;
	int			map_x;
	int			map_y;
	double		camera_x;
	int			side;
	double		prep_dist;
	int			line_h;
	int			start;
	int			end;
	int			tex_x;
}t_raycast;

typedef struct s_vars
{
	t_img		map_img;
	int			**tex;
	char		**map;
	int			row;
	int			col;

	void		*mlx;
	void		*win;
	t_player	*p;
	t_color		c;
}t_vars;

typedef enum e_identifier_type
{
	NO = 'N',
	SO = 'S',
	WE = 'W',
	EA = 'E',
	F = 'F',
	C = 'C',
}	t_identifier_type;

typedef struct s_check
{
	int	*mapset;
	int	path_count;
	int	count;
	int	mapflag;
	int	id;

}	t_check;

/* exec.c */
void	main_loop(t_vars *v);
int		draw_map(t_vars *v);

/* calc.c */
void	init_loop_vars(t_raycast *r, int x);
void	calc_step_side_dist(t_raycast *r);
void	clac_draw_line(t_raycast *r);
void	calc_ray(t_raycast *r, int x, char **map);

/* draw.c */
void	clac_draw_line(t_raycast *r);
void	calc_tex_x(t_raycast *r);
void	set_background(t_img *map_img, int floor, int ceiling);
void	set_draw(t_raycast *r);
void	set_draw_map(t_raycast *r, int x, t_img *map_img, int **tex);

/* init.c */
void	init_vars(t_vars *v, t_player *p);
void	load_tex(t_vars *v);

/* move.c */
int		ft_exit(t_vars *vars);
int		make_move(int keycode, t_vars *v);

/* minimap */
void	make_draw_minimap(t_vars *v);

/* utils */
void	set_coord(t_coord *c, double x, double y);
void	ft_int_free(int **arr, int idx);
void	ft_char_free(char **arr, int idx);

/* parse */
int		init_map(t_vars	*vars, int fd, t_check *check);
void	*ft_memset(void *b, int c, size_t len);
int		check_arg(char *filename);
char	**ft_split(char const *s, char c);
char	**free_all(char **arr);
int		ft_is_space(char c);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
int		strs_len(char	**strs);
void	*ft_calloc(size_t count, size_t size);
int		print_err(char	*str);
int		exit_with_err(char	*str);
char	**split_for_map(char const *s, char c);
int		set_map(char	*line, t_vars *vars, t_check *check);
int		exit_with_err(char	*str);
int		print_err(char	*str);
void	print(t_vars *vars);
char	**white_split(char const *s);
void	remove_newline(char	**map);
int		check_valid(char **map, t_player *player, int *col, int *row);
int		save_num(const char *str);
void	all_free(t_vars *vars);

#endif
