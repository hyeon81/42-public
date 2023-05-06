/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:13:08 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/05 18:26:55 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

// int	close(t_vars *vars)
// {
// 	//창 뿌수고 종료
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	exit(0);
// }

void	init_info(t_vars	*vars , char	*filename)
{
	ft_memset(vars, 0, sizeof(t_vars));
	init_map(vars, filename);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (check_arg(argc, argv[1]))
	{
		return (ERROR);
	}
	init_info(&vars, argv[1]);
	//앞 뒤 양 옆  구현(key)
	//재질과 스프라이트
	// vars.mlx = mlx_init();
	// //윈도우 생성
	// vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello World!");
	// mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);
	// mlx_loop(vars.mlx);
	return (0);
}
