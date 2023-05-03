/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:13:08 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/03 20:14:34 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	//윈도우 생성
	vars.win = mlx_new_window(vars.mlx, 48 * ROW, 48 * COL, "Cub3d");
	// render_map(&vars);
	mlx_hook(vars.win, ON_DESTROY, 0, &ft_close, &vars); //x 눌렀을때
	mlx_key_hook(vars.win, &key_hook, &vars); //키보드 이벤트 감지
	mlx_loop(vars.mlx);

	return (0);
}
