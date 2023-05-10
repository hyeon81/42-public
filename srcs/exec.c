#include "cub3d.h"

int worldMap[24][24]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int	ft_close(t_vars *vars)
{
	//창 뿌수고 종료
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void init_loop_vars(t_vars *vars, int x)
{
	vars->cameraX = 2 * x / (double)vars->width - 1; //카메라 평면에서 차지하는 x좌표
	vars->rayDirX = vars->dirX + vars->planeX * vars->cameraX; //광선의 방향 벡터
	vars->rayDirY = vars->dirY + vars->planeY * vars->cameraX;
	vars->mapX = (int)vars->posX;
	vars->mapY = (int)vars->posY;
	if (vars->rayDirX == 0) //언제 광선이 0이 될까요...?
		vars->deltaDistX = 1e30;
	else
		vars->deltaDistX = fabs(1 / vars->rayDirX);
	if (vars->rayDirY == 0)
		vars->deltaDistY = 1e30;
	else
		vars->deltaDistY = fabs(1 / vars->rayDirY);
	vars->hit = 0;
}

int	calc_step_sideDist(t_vars *v)
{
    if(v->rayDirX < 0)
    {
        v->stepX = -1;
        v->sideDistX = (v->posX - v->mapX) * v->deltaDistX;
    }
    else
    {
        v->stepX = 1;
        v->sideDistX = (v->mapX + 1.0 - v->posX) * v->deltaDistX;
    }
    if(v->rayDirY < 0)
    {
        v->stepY = -1;
        v->sideDistY = (v->posY - v->mapY) * v->deltaDistY;
    }
    else
    {
        v->stepY = 1;
        v->sideDistY = (v->mapY + 1.0 - v->posY) * v->deltaDistY;
    }
	return (0);
}

int make_step(t_vars *v)
{
	while (v->hit == 0)
	{
		if (v->sideDistX < v->sideDistY)
		{
			v->sideDistX += v->deltaDistX;
			v->mapX += v->stepX;
			v->side = 0;
		}
		else
		{
			v->sideDistY += v->deltaDistY;
			v->mapY += v->stepY;
			v->side = 1;
		}
		if (worldMap[v->mapX][v->mapY] > 0)
			v->hit = 1;
	}
	return (0);
}

int clac_draw_line(t_vars *v)
{
	if (v->side == 0)
		v->perpWallDist = v->sideDistX - v->deltaDistX;
	else
		v->perpWallDist = v->sideDistY - v->deltaDistY;
	v->lineHeight = (int)(v->height / v->perpWallDist);
	v->start = (-(v->lineHeight) / 2) + (v->height / 2);
	if (v->start < 0)
		v->start = 0;
	v->end = (v->lineHeight / 2) + (v->height / 2);
	if (v->end >= v->height)
		v->end = v->height - 1;
	return (0);
}

// int make_draw_minimap(t_vars *v)
// {
// 	t_img img;

// 	img = mlx_new_image(v->mlx, )
// }

int make_draw (t_vars *v, int x) 
{
	int y;
	int color;

	y = v->start;
	mlx_clear_window(v->mlx, v->win);
	while (y <= v->end) //한줄긋기
	{
		if (v->side == 1)
			color = (v->tex[0].tex) / 2;
		else
			color = v->tex[0].tex;
		mlx_pixel_put(v->mlx, v->win, x, y, color);
		y++;
	}
	return (0);
}

int move_forth_back(int keycode, t_vars *v)
{
	if (keycode == W)
	{
		if (!worldMap[(int)(v->posX + v->dirX * v->moveSpeed)][(int)(v->posY)])
			v->posX += v->dirX * v->moveSpeed;
		if (!worldMap[(int)(v->posX)][(int)(v->posY + v->dirY * v->moveSpeed)])
			v->posY += v->dirY * v->moveSpeed;
	}
	else if (keycode == S)
	{
		if (!worldMap[(int)(v->posX - v->dirX * v->moveSpeed)][(int)(v->posY)])
			v->posX -= v->dirX * v->moveSpeed;
		if (!worldMap[(int)(v->posX)][(int)(v->posY - v->dirY * v->moveSpeed)])
			v->posY -= v->dirY * v->moveSpeed;
	}
	return (0);
}

int	move_left_right(int keycode, t_vars *v)
{
	double oldDirX = v->dirX;
	double oldPlaneX = v->planeX;
	if (keycode == A)
	{
		v->dirX = v->dirX * cos(v->rotateSpeed) - v->dirY * sin(v->rotateSpeed);
		v->dirY = oldDirX * sin(v->rotateSpeed) + v->dirY * cos(v->rotateSpeed);
		v->planeX = v->planeX * cos(v->rotateSpeed) - v->planeY * sin(v->rotateSpeed);
		v->planeY = oldPlaneX * sin(v->rotateSpeed) + v->planeY * cos(v->rotateSpeed);
	}
	if (keycode == D)
	{
		v->dirX = v->dirX * cos(-v->rotateSpeed) - v->dirY * sin(-v->rotateSpeed);
		v->dirY = oldDirX * sin(-v->rotateSpeed) + v->dirY * cos(-v->rotateSpeed);
		v->planeX = v->planeX * cos(-v->rotateSpeed) - v->planeY * sin(-v->rotateSpeed);
		v->planeY = oldPlaneX * sin(-v->rotateSpeed) + v->planeY * cos(-v->rotateSpeed);
	}
	return (0);
}

int make_move(int keycode, t_vars *v)
{
	if (keycode == W || keycode == S)
		move_forth_back(keycode, v);
	if (keycode == A || keycode == D)
		move_left_right(keycode, v);
	if (keycode == ESC)
		exit(0);
	// if (keycode == W || keycode == S || keycode == A || keycode == D)
	// 	main_loop(v);
	return (0);
}

int main_loop(t_vars *vars)
{
	int x;

	x = 0;
	while (x < vars->width)
	{
		init_loop_vars(vars, x);
		calc_step_sideDist(vars);
		make_step(vars);
		clac_draw_line(vars);
		make_draw(vars, x);
		x++;
	}
	return (0);
}
int init_texture(t_vars *vars)
{

}

int init_vars(t_vars *vars)
{
	int i;
	int j;

	/* raycast */
    vars->posX = 22;
    vars->posY = 12;
    vars->dirX = -1;
    vars->dirY = 0; 
    vars->planeX = 0;
    vars->planeY = 0.66; 
    vars->time = 0; 
    vars->oldTime = 0; 
    vars->moveSpeed = 0.5;
    vars->rotateSpeed = 0.1;

	/* info */
	vars->row = 24;
	vars->col = 24;
	vars->tex[0].tex = 0x90F564;
	vars->tex[1].tex = 0x7178F5;
	vars->tex[2].tex = 0xF5F558;
	vars->tex[3].tex = 0xF540E9;

	i = 0;
	while (i < vars->width)
	{
		j = 0;
		while (j < vars->height)
		{
			vars->buf[i][j] = 0;
			j++;
		}
		i++;
	}
	/* mlx */
    vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "Cub3d");

    return (0);
}