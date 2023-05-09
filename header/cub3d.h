/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:29:45 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/09 21:33:44 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

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
    int			*tex;
}               t_tex;

typedef struct s_dda
{
	
}t_dda;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	*img;

	/* 이미지 */
	// void	*img0;
	// void	*img1;
	// void	*imgw;
	// void	*imgp;

	/* info */
	double posX; //플레잉어의 초기 위치 벡터
	double posY; 
	double dirX; //플레이어의 초기 방향 벡터
	double dirY;
	double planeX;//플레이어의 카메라 평면
	double planeY;
	double	moveSpeed;
	double	rotateSpeed;
	double	time;
	double	oldTime; //time of previous frame.
	//둘의 시간차를 통해 특정 키를 눌렀을때 (일정한 속도로 움직이기 위해) 이동거리를 결정하고 FPS를 측정하는데 사용

	/* raycast */
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;

	int	width;
	int	height;
	//스크린 넓이

	int row;
	int col;
	//맵 크기 (row가 가로 크기, col이 세로 크기)

	t_tex   tex[4]; //동서남북 텍스쳐
    int         f_color; //바닥 색상
    int         c_color; //천장 색상
}t_vars;

int	ft_close(t_vars *vars);
int key_hook(int keycode, t_vars *vars);
int main_loop(t_vars *vars);
int make_move(int keycode, t_vars *vars);
void make_raycast(t_vars *vars);
int init_vars(t_vars *vars);

#endif
