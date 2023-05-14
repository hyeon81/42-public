/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meliesf <meliesf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:13:08 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/13 01:34:19 by meliesf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

int	print_err(char	*str)
{
	write(1, str, ft_strlen(str)); // ㅇㅔ러를 내보내야하나
	return(ERROR);
	// exit(-1);
}

// int	close(t_vars *vars)
// {
// 	//창 뿌수고 종료
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	exit(0);
// }

// void print_map(t_vars *vars)
// {
// 	int i;

// 	i = 0;
// 	printf("north = %s\n", vars->north);
// 	printf("south = %s\n", vars->south);
// 	printf("west = %s\n", vars->west);
// 	printf("east = %s\n", vars->east);

// 	// printf("----map-----\n");
// 	// while(vars->map[i])
// 	// 	printf("%s\n", vars->map[i]);
// }

// void	leaks()
// {
// 	system("leaks cub3D");
// }

void	init_info(t_vars	*vars , char	*filename)
{
	ft_memset(vars, 0, sizeof(t_vars));
	init_map(vars, filename);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	// atexit(leaks);
	if (argc != 2 || check_arg(argc, argv[1]))
	{
		print_err("Invalid filetype\n");
		return (ERROR);
	}
	init_info(&vars, argv[1]);
	// print_map(&vars);
	//앞 뒤 양 옆  구현(key)
	//재질과 스프라이트
	// vars.mlx = mlx_init();
	// //윈도우 생성
	// vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello World!");
	// mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);
	// mlx_loop(vars.mlx);


	return (0);
}
