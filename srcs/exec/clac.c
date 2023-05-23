/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clac.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:32:26 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/23 13:30:05 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_loop_vars(t_raycast *r, int x)
{
	r->camera_x = 2 * x / (double)WIDTH - 1;
	r->ray_dir.x = r->p->dir.x + r->p->plane.x * r->camera_x;
	r->ray_dir.y = r->p->dir.y + r->p->plane.y * r->camera_x;
	r->map_x = (int)r->p->pos.x;
	r->map_y = (int)r->p->pos.y;
	if (r->ray_dir.x == 0)
		r->delta_dist.x = 1e30;
	else
		r->delta_dist.x = fabs(1 / r->ray_dir.x);
	if (r->ray_dir.y == 0)
		r->delta_dist.y = 1e30;
	else
		r->delta_dist.y = fabs(1 / r->ray_dir.y);
}

void	calc_step_side_dist(t_raycast *r)
{
	if (r->ray_dir.x < 0)
	{
		r->step.x = -1;
		r->side_dist.x = (r->p->pos.x - r->map_x) * r->delta_dist.x;
	}
	else
	{
		r->step.x = 1;
		r->side_dist.x = (r->map_x + 1.0 - r->p->pos.x) * r->delta_dist.x;
	}
	if (r->ray_dir.y < 0)
	{
		r->step.y = -1;
		r->side_dist.y = (r->p->pos.y - r->map_y) * r->delta_dist.y;
	}
	else
	{
		r->step.y = 1;
		r->side_dist.y = (r->map_y + 1.0 - r->p->pos.y) * r->delta_dist.y;
	}
}

void	shoot_ray(t_raycast *r, char **map)
{
	while (1)
	{
		if (r->side_dist.x < r->side_dist.y)
		{
			r->side_dist.x += r->delta_dist.x;
			r->map_x += r->step.x;
			r->side = 0;
		}
		else
		{
			r->side_dist.y += r->delta_dist.y;
			r->map_y += r->step.y;
			r->side = 1;
		}
		if (map[r->map_y][r->map_x] == '1')
			break ;
	}
}

void	calc_ray(t_raycast *r, int x, char **map)
{
	init_loop_vars(r, x);
	calc_step_side_dist(r);
	shoot_ray(r, map);
}
