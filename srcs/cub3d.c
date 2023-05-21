/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meliesf <meliesf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:13:08 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/21 19:46:09 by meliesf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print(t_vars *vars)
{
	int	i = 0;
	printf("------map------\n");
	while (vars->map[i])
	printf("%s\n", vars->map[i++]);
	printf("north = %s\n", vars->north);
	printf("south = %s\n", vars->south);
	printf("west = %s\n", vars->west);
	printf("east = %s\n", vars->east);
	printf("floorcolor = %d\n", vars->floor_color);
	printf("ceiling_color = %d\n", vars->ceiling_color);
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
	ft_memset(vars, 0, sizeof(t_vars));
	ft_memset(&check, 0, sizeof(t_check));
	check.mapset = ft_calloc(sizeof(int), 6);
	init_map(vars, fd, &check);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2 || check_arg(argv[1]))
		exit_with_err("Invalid filetype\n");
	init_info(&vars, argv[1]);
	free_all(vars.map);
	free(vars.north);
	free(vars.south);
	free(vars.west);
	free(vars.east);
	// system("leaks cub3D");
	return (0);
}
