/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clac.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:32:26 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/16 21:49:49 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_loop_vars(t_raycast *r, int x)
{
	//calculate ray position and direction
	r->camera_x = 2 * x / (double)WIDTH - 1; //카메라 평면에서 차지하는 x좌표
	r->ray_dir.x = r->dir->x + r->plane->x * r->camera_x; //광선의 방향 벡터
	r->ray_dir.y = r->dir->y + r->plane->y * r->camera_x;
	r->map_x = (int)r->pos->x;
	r->map_y = (int)r->pos->y;
	r->delta_dist.x = fabs(1 / r->ray_dir.x);
	r->delta_dist.y = fabs(1 / r->ray_dir.y);
	// if (r->ray_dirX == 0) 
	// 	r->delta_distX = 1e30; //뭘까 이 숫자..
	// else
	// 	r->delta_distX = fabs(1 / r->ray_dirX);
	// if (r->ray_dirY == 0)
	// 	r->delta_distY = 1e30;
	// else
	// 	r->delta_distY = fabs(1 / r->ray_dirY);
}

void	calc_step_side_dist(t_raycast *r)
{
	if (r->ray_dir.x < 0)
	{
		r->step.x = -1;
		r->side_dist.x = (r->pos->x - r->map_x) * r->delta_dist.x;
	}
	else
	{
		r->step.x = 1;
		r->side_dist.x = (r->map_x + 1.0 - r->pos->x) * r->delta_dist.x;
	}
	if (r->ray_dir.y < 0)
	{
		r->step.y = -1;
		r->side_dist.y = (r->pos->y - r->map_y) * r->delta_dist.y;
	}
	else
	{
		r->step.y = 1;
		r->side_dist.y = (r->map_y + 1.0 - r->pos->y) * r->delta_dist.y;
	}
}

void	shoot_ray(t_raycast *r)
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
		if (worldMap[r->map_y][r->map_x] == 1)
			break ;
	}
}

void	calc_ray(t_raycast *r, int x)
{
	init_loop_vars(r, x);
	calc_step_side_dist(r);
	shoot_ray(r);
}
