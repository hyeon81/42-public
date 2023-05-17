/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:13:08 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/17 18:47:35 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_map(t_vars *v)
{
	make_draw_minimap(v);
	mlx_put_image_to_window(v->mlx, v->win, v->map_img.ptr, 0, 0);

	return (0);
}

void	main_loop(t_vars *v)
{
	t_raycast	r;
	int			x;

	x = 0;
	r.dir = &(v->dir);
	r.plane = &(v->plane);
	r.pos = &(v->pos);
	set_background(&(v->map_img), v->f_color, v->c_color);
	while (x < WIDTH)
	{
		calc_ray(&r, x);
		set_draw(&r);
		set_map(&r, x, &(v->map_img), v->tex);
		x++;
	}
	draw_map(v);
}

int	main(void)
{
	t_vars	vars;

	init_vars(&vars);
	load_tex(&vars);
	main_loop(&vars);
	mlx_hook(vars.win, ON_DESTROY, 0, &ft_exit, &vars);
	mlx_hook(vars.win, 2, 1, &make_move, &vars);
	mlx_loop_hook(vars.mlx, &draw_map, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
