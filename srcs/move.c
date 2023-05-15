/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:54:08 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/15 21:42:10 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(t_vars *vars)
{
	//창 뿌수고 종료
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int move_forth_back(int keycode, t_vars *v)
{
	if (keycode == KEY_W)
	{
		if (worldMap[(int)(v->posX + v->dirX * v->moveSpeed)][(int)(v->posY)] == 0)
			v->posX += v->dirX * v->moveSpeed;
		if (worldMap[(int)(v->posX)][(int)(v->posY + v->dirY * v->moveSpeed)] == 0)
			v->posY += v->dirY * v->moveSpeed;
	}
	if (keycode == KEY_S)
	{
		if (worldMap[(int)(v->posX - v->dirX * v->moveSpeed)][(int)(v->posY)] == 0)
			v->posX -= v->dirX * v->moveSpeed;
		if (worldMap[(int)(v->posX)][(int)(v->posY - v->dirY * v->moveSpeed)] == 0)
			v->posY -= v->dirY * v->moveSpeed;
	}
	return (0);
}

int	move_left_right(int keycode, t_vars *v)
{
	double oldDirX = v->dirX;
	double oldPlaneX = v->planeX;
	if (keycode == KEY_A)
	{
		v->dirX = v->dirX * cos(v->rotateSpeed) - v->dirY * sin(v->rotateSpeed);
		v->dirY = oldDirX * sin(v->rotateSpeed) + v->dirY * cos(v->rotateSpeed);
		v->planeX = v->planeX * cos(v->rotateSpeed) - v->planeY * sin(v->rotateSpeed);
		v->planeY = oldPlaneX * sin(v->rotateSpeed) + v->planeY * cos(v->rotateSpeed);
	}
	if (keycode == KEY_D)
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
	if (keycode == KEY_W || keycode == KEY_S)
		move_forth_back(keycode, v);
	if (keycode == KEY_A || keycode == KEY_D)
		move_left_right(keycode, v);
	if (keycode == ESC)
		exit(0);
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || keycode == KEY_D)
		main_loop(v);
	return (0);
}
