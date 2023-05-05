/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:29:45 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/05 17:51:44 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define ROW 34
# define COL 14
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define ON_DESTROY 17
# define IMG_W 48
# define IMG_H 48

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

typedef struct  s_tex
{
    char		*path;
    //int			*tex;
}               t_tex;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	*img;

	// void	*img0;
	// void	*img1;
	// void	*imgw;
	// void	*imgp;

	t_tex   tex[4]; //동서남북 텍스쳐
    int         f_color; //바닥 색상
    int         c_color; //천장 색상
}t_vars;

int	ft_close(t_vars *vars);
int key_hook(int keycode, t_vars *vars);

#endif
