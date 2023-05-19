/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:13:08 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/19 17:08:03 by hyeokim2         ###   ########.fr       */
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
	r.p = v->p;
	set_background(&(v->map_img), v->c->floor_color, v->c->ceiling_color);
	while (x < WIDTH)
	{
		calc_ray(&r, x, v->map);
		set_draw(&r);
		set_map(&r, x, &(v->map_img), v->tex);
		x++;
	}
	draw_map(v);
}

int	main(void)
{
	t_player	p;
	t_color		c;
	t_vars		vars;

	init_vars(&vars, &p, &c);
	load_tex(&vars);
	main_loop(&vars);
	mlx_hook(vars.win, ON_DESTROY, 0, &ft_exit, &vars);
	mlx_hook(vars.win, KEY_PRESS, 1L << 0, &make_move, &(vars));
	mlx_loop_hook(vars.mlx, &draw_map, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
