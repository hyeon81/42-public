/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:40:12 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/10/04 13:21:50 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_window(t_vars *vars)
{
	int	img_w;
	int	img_h;

	img_h = 48;
	img_w = 48;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->w * 48, vars->h * 48, \
	"so_long");
	vars->img1 = mlx_xpm_file_to_image(vars->mlx, "./asset/fence.xpm", \
	&img_w, &img_h);
	vars->img0 = mlx_xpm_file_to_image(vars->mlx, "./asset/field.xpm", \
	&img_w, &img_h);
	vars->img_e = mlx_xpm_file_to_image(vars->mlx, "./asset/home.xpm", \
	&img_w, &img_h);
	vars->img_c = mlx_xpm_file_to_image(vars->mlx, "./asset/fish.xpm", \
	&img_w, &img_h);
	vars->img_p = mlx_xpm_file_to_image(vars->mlx, "./asset/cat.xpm", \
	&img_w, &img_h);
}

void	make_new_pos(t_vars *vars, int add_y, int add_x)
{
	if (vars->map[vars->pos_y + add_y][vars->pos_x + add_x] == '1')
		return ;
	if (vars->map[vars->pos_y + add_y][vars->pos_x + add_x] == 'E')
	{
		if (vars->c <= vars->get_item)
			ft_exit(vars);
		else if (vars->c > vars->get_item)
			printf("You need to get all fish\n");
	}
	else
	{
		ft_put_image(vars, vars->img0, vars->pos_x, vars->pos_y);
		vars->pos_y = vars->pos_y + add_y;
		vars->pos_x = vars->pos_x + add_x;
		ft_put_image(vars, vars->img_p, vars->pos_x, vars->pos_y);
		vars->move_count++;
		printf("your_step: %d\n", vars->move_count);
	}
}

int	make_move(int keycode, t_vars *vars)
{
	if (keycode == 53)
		ft_exit(vars);
	if (!(keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2))
		return (0);
	if (keycode == 13)
		make_new_pos(vars, -1, 0);
	else if (keycode == 0)
		make_new_pos(vars, 0, -1);
	else if (keycode == 1)
		make_new_pos(vars, 1, 0);
	else if (keycode == 2)
		make_new_pos(vars, 0, 1);
	ft_put_image(vars, vars->img_e, vars->escape_x, vars->escape_y);
	if (vars->map[vars->pos_y][vars->pos_x] == 'C')
	{
		(vars->get_item)++;
		vars->map[vars->pos_y][vars->pos_x] = '0';
	}
	return (0);
}

void	render_map(t_vars *vars, int x, int y)
{
	while (++y < vars->h)
	{
		x = -1;
		while (++x < vars->w)
		{
			ft_put_image(vars, vars->img0, x, y);
			if (vars->map[y][x] == '1')
				ft_put_image(vars, vars->img1, x, y);
			else if (vars->map[y][x] == 'E')
			{
				ft_put_image(vars, vars->img_e, x, y);
				vars->escape_x = x;
				vars->escape_y = y;
			}
			else if (vars->map[y][x] == 'C')
				ft_put_image(vars, vars->img_c, x, y);
			else if (vars->map[y][x] == 'P')
			{
				ft_put_image(vars, vars->img_p, x, y);
				vars->pos_x = x;
				vars->pos_y = y;
			}
		}
	}
}

int	main(int argc, char *argv[])
{
	char	*m_line;
	int		fd;
	t_vars	vars;

	check_suffix(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || fd < 0)
		error_occur(-2, 0);
	value_init(&vars);
	m_line = read_line(fd, &vars);
	close(fd);
	if (m_line[0] == '\0')
		error_occur(-2, 0);
	make_map(&vars, m_line, -1);
	check_wall_wrap(&vars);
	check_valid(&vars, 0, 0);
	make_window(&vars);
	render_map(&vars, -1, -1);
	mlx_key_hook(vars.win, make_move, &vars);
	mlx_hook(vars.win, 17, 0, ft_exit, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
