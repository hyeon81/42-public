/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:35:28 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/19 20:49:18 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

void	print(t_vars *vars)
{
	int	i = 0;
	printf("------map------\n");
	while (vars->map[i])
		printf("%s\n", vars->map[i++]);
	printf("north = %s\n", vars->c.north);
	printf("south = %s\n", vars->c.south);
	printf("west = %s\n", vars->c.west);
	printf("east = %s\n", vars->c.east);
	printf("floorcolor = %d\n", vars->c.floor_color);
	printf("ceiling_color = %d\n", vars->c.ceiling_color);
	printf("---------------\n");
}

int	check_arg(char *filename)
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
	ft_memset(&check, 0, sizeof(t_check));
	check.mapset = ft_calloc(sizeof(int), 6);
	ft_memset(vars, 0, sizeof(t_vars));
	if (init_map(vars, fd, &check) == ERROR)
		exit_with_err("ERROR : init_map\n");
}

int	main(int argc, char **argv)
{
	t_player	p;
	t_color		c;
	t_vars		vars;

	if (argc != 2 || check_arg(argv[1]))
		exit_with_err("Invalid filetype\n");
	vars.p = &p;
	init_info(&vars, argv[1]);
	init_vars(&vars, &p);
	load_tex(&vars);
	main_loop(&vars);
	mlx_hook(vars.win, ON_DESTROY, 0, &ft_exit, &vars);
	mlx_hook(vars.win, KEY_PRESS, 1L << 0, &make_move, &(vars));
	mlx_loop_hook(vars.mlx, &draw_map, &vars);
	mlx_loop(vars.mlx);

	return (0);
}
