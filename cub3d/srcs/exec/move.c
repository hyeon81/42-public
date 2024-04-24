/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:54:08 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/23 13:14:48 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forth_back(int keycode, t_player *p, char **map)
{
	double	speed;

	speed = 0.2;
	if (keycode == KEY_W)
	{
		if (map[(int)(p->pos.y)][(int)(p->pos.x + p->dir.x * speed)] != '1')
			p->pos.x += p->dir.x * speed;
		if (map[(int)(p->pos.y + p->dir.y * speed)][(int)(p->pos.x)] != '1')
			p->pos.y += p->dir.y * speed;
	}
	if (keycode == KEY_S)
	{
		if (map[(int)(p->pos.y)][(int)(p->pos.x - p->dir.x * speed)] != '1')
			p->pos.x -= p->dir.x * speed;
		if (map[(int)(p->pos.y - p->dir.y * speed)][(int)(p->pos.x)] != '1')
			p->pos.y -= p->dir.y * speed;
	}
}

void	move_left_right(int keycode, t_player *p, char **map)
{
	double	speed;

	speed = 0.2;
	if (keycode == KEY_A)
	{
		if (map[(int)(p->pos.y)][(int)(p->pos.x - p->plane.x * speed)] != '1')
			p->pos.x -= p->plane.x * speed;
		if (map[(int)(p->pos.y - p->plane.y * speed)][(int)(p->pos.x)] != '1')
			p->pos.y -= p->plane.y * speed;
	}
	if (keycode == KEY_D)
	{
		if (map[(int)(p->pos.y)][(int)(p->pos.x + p->plane.x * speed)] != '1')
			p->pos.x += p->plane.x * speed;
		if (map[(int)(p->pos.y + p->plane.y * speed)][(int)(p->pos.x)] != '1')
			p->pos.y += p->plane.y * speed;
	}
}

void	view_left_right(int keycode, t_player *p)
{
	double	old_dir_x;
	double	old_plane_x;
	double	speed;

	old_dir_x = p->dir.x;
	old_plane_x = p->plane.x;
	speed = 0.03;
	if (keycode == KEY_LEFT)
	{
		p->dir.x = p->dir.x * cos(-speed) - p->dir.y * sin(-speed);
		p->dir.y = old_dir_x * sin(-speed) + p->dir.y * cos(-speed);
		p->plane.x = p->plane.x * cos(-speed) - p->plane.y * sin(-speed);
		p->plane.y = old_plane_x * sin(-speed) + p->plane.y * cos(-speed);
	}
	if (keycode == KEY_RIGHT)
	{
		p->dir.x = p->dir.x * cos(speed) - p->dir.y * sin(speed);
		p->dir.y = old_dir_x * sin(speed) + p->dir.y * cos(speed);
		p->plane.x = p->plane.x * cos(speed) - p->plane.y * sin(speed);
		p->plane.y = old_plane_x * sin(speed) + p->plane.y * cos(speed);
	}
}

int	make_move(int keycode, t_vars *v)
{
	if (keycode == KEY_W || keycode == KEY_S)
		move_forth_back(keycode, v->p, v->map);
	if (keycode == KEY_A || keycode == KEY_D)
		move_left_right(keycode, v->p, v->map);
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		view_left_right(keycode, v->p);
	if (keycode == ESC)
		ft_exit(v);
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || \
		keycode == KEY_D || keycode == KEY_LEFT || keycode == KEY_RIGHT)
		main_loop(v);
	return (0);
}
