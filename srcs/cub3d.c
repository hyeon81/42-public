/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:13:08 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/15 21:14:35 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int draw_map(t_vars *v)
{
    mlx_put_image_to_window(v->mlx, v->win, v->map_img.ptr, 0, 0);
	return (0);
}

int main(void)
{
	t_vars vars;

	init_vars(&vars);
	load_tex(&vars);
	main_loop(&vars);
	draw_map(&vars);
	mlx_hook(vars.win, ON_DESTROY, 0, &ft_close, &vars);
	mlx_hook(vars.win, 2, 1, &make_move, &vars);
	// mlx_key_hook(vars.win, &make_move, &vars);
	mlx_loop_hook(vars.mlx, &draw_map, &vars);
	mlx_loop(vars.mlx);

	return (0);
}