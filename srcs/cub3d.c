/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:33:10 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/22 21:33:43 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	printf("x = %f\n", vars->p->pos.x);
	printf("y = %f\n", vars->p->pos.y);
	printf("direction = %c\n", vars->p->direction);
	printf("col = %d\n", vars->col);
	printf("row = %d\n", vars->row);

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

void	init_info(t_vars	*vars, char	*filename, t_player *player)
{
	int		fd;
	t_check	check;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_with_err("Failed to open file.\n");
	ft_memset(vars, 0, sizeof(t_vars));
	ft_memset(&check, 0, sizeof(t_check));
	vars->p = player;
	check.mapset = ft_calloc(sizeof(int), 6);
	init_map(vars, fd, &check);
	close(fd);
}

void	all_free(t_vars *vars)
{
	free_all(vars->map);
	free(vars->c.north);
	free(vars->c.south);
	free(vars->c.west);
	free(vars->c.east);
}

void	leaks(void)
{
	system("leaks cub3D");
}

int	main(int argc, char	**argv)
{
	t_vars		vars;
	t_player	p;

	atexit(leaks);
	if (argc != 2 || check_arg(argv[1]))
		exit_with_err("Invalid filetype\n");
	init_info(&vars, argv[1], &p);
	// print(&vars);
	init_vars(&vars, &p);
	load_tex(&vars);
	main_loop(&vars);
	mlx_hook(vars.win, ON_DESTROY, 0, &ft_exit, &vars);
	mlx_hook(vars.win, KEY_PRESS, 1L << 0, &make_move, &(vars));
	mlx_loop_hook(vars.mlx, &draw_map, &vars);
	mlx_loop(vars.mlx);
	all_free(&vars);
	return (0);
}
