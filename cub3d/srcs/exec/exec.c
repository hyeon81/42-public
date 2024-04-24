/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:25:36 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/23 17:58:39 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_background(t_img *map_img, int floor, int ceiling)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				map_img->data[y * WIDTH + x] = ceiling;
			else
				map_img->data[y * WIDTH + x] = floor;
			x++;
		}
		y++;
	}
}

int	draw_map(t_vars *v)
{
	mlx_put_image_to_window(v->mlx, v->win, v->map_img.ptr, 0, 0);
	return (0);
}

void	main_loop(t_vars *v)
{
	t_raycast	r;
	int			x;

	x = 0;
	r.p = v->p;
	set_background(&(v->map_img), v->c.floor_color, v->c.ceiling_color);
	while (x < WIDTH)
	{
		calc_ray(&r, x, v->map);
		set_draw(&r);
		set_draw_map(&r, x, &(v->map_img), v->tex);
		x++;
	}
	draw_map(v);
}
