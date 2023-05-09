/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:13:08 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/09 21:32:30 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(void)
{
	t_vars vars;

	init_vars(&vars);
	mlx_hook(vars.win, ON_DESTROY, 0, &ft_close, &vars);
	mlx_key_hook(vars.win, &make_move, &vars);
	mlx_loop_hook(vars.mlx, &main_loop, &vars);
	mlx_loop(vars.mlx);

	return (0);
}