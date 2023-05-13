#include "cub3d.h"


int	ft_close(t_vars *vars)
{
	//창 뿌수고 종료
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
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
	if (keycode == W || keycode == S || keycode == A || keycode == D)
		main_loop(v);
	return (0);
}
