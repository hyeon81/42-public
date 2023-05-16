/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:13:08 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/16 16:09:59 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

int	print_err(char	*str)
{
	write(1, str, ft_strlen(str)); // ㅇㅔ러를 내보내야하나
	return(-1);
	exit(-1);
}

int	exit_with_err(char	*str)
{
	write(1, str, ft_strlen(str));
	exit(-1);
}

int	check_arg(int argc, char *filename)
{
	int	name_len;

	name_len = ft_strlen(filename);
	if (name_len <= 4)
		return (ERROR);
	if (filename[name_len - 1] != 'b' || filename[name_len - 2] != 'u' \
	|| filename[name_len - 3] != 'c' || filename[name_len - 4] != '.')
		return (ERROR);
	return (0);
}


void	init_info(t_vars	*vars, char	*filename)
{
	int		fd;
	t_check	check;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_with_err("Failed to open file.\n");
	check.mapset = ft_calloc(sizeof(int), 6);
	ft_memset(vars, 0, sizeof(t_vars));
	init_map(vars, fd, &check);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	// atexit(leaks);
	if (argc != 2 || check_arg(argc, argv[1]))
		exit_with_err("Invalid filetype\n");
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
