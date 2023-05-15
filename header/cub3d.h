/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:29:45 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/15 21:16:15 by hyeokim2         ###   ########.fr       */
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
# define IMG_W 64
# define IMG_H 64
# define TEX_W 64
# define TEX_H 64
# define WIDTH 480
# define HEIGHT 360
# define TILE_SIZE 5

enum Spawn {
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

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	map_img;
	t_img	mini;

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
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	double	perpWallDist;
	int		lineHeight;
	int		start;
	int		end;
	int		**tex;
	int		posDir; //spawn dir
	int	width;
	int	height;
	//스크린 넓이

	int row;
	int col;
	//맵 크기 (row가 가로 크기, col이 세로 크기)

    int         f_color; //바닥 색상
    int         c_color; //천장 색상
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

/* calc.c */
void make_raycast(t_vars *vars);

/* cub3d.c */
int main_loop(t_vars *vars);

/* draw.c */
int draw_block(t_vars *v, int x, int y, int color);
int make_draw_minimap(t_vars *v);
int make_draw (t_vars *v, int x);
int make_background(t_vars *v);

/* init.c */
int init_vars(t_vars *vars);
void load_tex(t_vars *v);

/* keyevent.c */
int	ft_close(t_vars *vars);
int key_hook(int keycode, t_vars *vars);
int make_move(int keycode, t_vars *vars);


#endif
