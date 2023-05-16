/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:54:08 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/16 21:34:04 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	move_forth_back(int keycode, t_vars *v)
{
	double	speed;

	speed = 0.4;
	if (keycode == KEY_W)
	{
		if (worldMap[(int)(v->pos.y)][(int)(v->pos.x + v->dir.x * speed)] == 0)
			v->pos.x += v->dir.x * speed;
		if (worldMap[(int)(v->pos.y + v->dir.y * speed)][(int)(v->pos.x)] == 0)
			v->pos.y += v->dir.y * speed;
	}
	if (keycode == KEY_S)
	{
		if (worldMap[(int)(v->pos.y)][(int)(v->pos.x - v->dir.x * speed)] == 0)
			v->pos.x -= v->dir.x * speed;
		if (worldMap[(int)(v->pos.y - v->dir.y * speed)][(int)(v->pos.x)] == 0)
			v->pos.y -= v->dir.y * speed;
	}
	return (0);
}

int	move_left_right(int keycode, t_vars *v)
{
	double	old_dir_x;
	double	old_plane_x;
	double	speed;

	old_dir_x = v->dir.x;
	old_plane_x = v->plane.x;
	speed = 0.05;
	if (keycode == KEY_A)
	{
		v->dir.x = v->dir.x * cos(speed) - v->dir.y * sin(speed);
		v->dir.y = old_dir_x * sin(speed) + v->dir.y * cos(speed);
		v->plane.x = v->plane.x * cos(speed) - v->plane.y * sin(speed);
		v->plane.y = old_plane_x * sin(speed) + v->plane.y * cos(speed);
	}
	if (keycode == KEY_D)
	{
		v->dir.x = v->dir.x * cos(-speed) - v->dir.y * sin(-speed);
		v->dir.y = old_dir_x * sin(-speed) + v->dir.y * cos(-speed);
		v->plane.x = v->plane.x * cos(-speed) - v->plane.y * sin(-speed);
		v->plane.y = old_plane_x * sin(-speed) + v->plane.y * cos(-speed);
	}
	return (0);
}

int	make_move(int keycode, t_vars *v)
{
	if (keycode == KEY_W || keycode == KEY_S)
		move_forth_back(keycode, v);
	if (keycode == KEY_A || keycode == KEY_D)
		move_left_right(keycode, v);
	if (keycode == ESC)
		exit(0);
	if (keycode == KEY_W || keycode == KEY_S || \
	keycode == KEY_A || keycode == KEY_D)
		main_loop(v);
	return (0);
}
