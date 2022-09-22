/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   so_long.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hyeokim2 <hyeokim2@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/09/22 21:13:14 by hyeokim2		  #+#	#+#			 */
/*   Updated: 2022/09/22 21:45:45 by hyeokim2		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"

void	make_new_pos(t_vars *vars, int add_y, int add_x)
{
	if (vars->map[vars->pos_y + add_y][vars->pos_x + add_x] == '1')
		return ;
	if (vars->map[vars->pos_y + add_y][vars->pos_x + add_x] == 'E')
	{
		vars->pos_y = vars->pos_y + add_y;
		vars->pos_x = vars->pos_x + add_x;
	}
	else
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img0, vars->pos_x * 48, vars->pos_y * 48); //지우고
		vars->pos_y = vars->pos_y + add_y;
		vars->pos_x = vars->pos_x + add_x;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_p, vars->pos_x * 48, vars->pos_y * 48); //이동
		vars->move_count++;
		printf("your_move_count: %d\n", vars->move_count);
	}
}

void	make_move(int keycode, t_vars *vars)
{
	//버튼 눌렀을때 반응
	if (keycode == 13) //press W
		make_new_pos(vars, -1, 0);
	else if (keycode == 0) //press A
		make_new_pos(vars, 0, -1);
	else if (keycode == 1) //press S
		make_new_pos(vars, 1, 0);
	else if (keycode == 2) //press D
		make_new_pos(vars, 0, 1);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_e, vars->escape_x * 48, vars->escape_y * 48);
	//아이템이었을 경우
	if (vars->map[vars->pos_y][vars->pos_x] == 'C')
		(vars->get_item)++;
	//출구였을 경우
	if (vars->map[vars->pos_y][vars->pos_x] == 'E')
	{
		if (vars->item <= vars->get_item)
		{
			system("leaks a.out");
			exit(0);
		}
	}
}

int key_hook(int keycode, t_vars *vars)
{
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		make_move(keycode, vars);
	printf("press key: %d\n", keycode);
	//x 눌렀을때. 다른 키 처리
	if (keycode == 53)
		exit(0);
	return (0);
}

void	render_map(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->w * 48, vars->h * 48, "Hello World!");
	vars->img1 = mlx_xpm_file_to_image(vars->mlx, "./asset/fence.xpm", &vars->img_w, &vars->img_h);
	vars->img0 = mlx_xpm_file_to_image(vars->mlx, "./asset/field.xpm", &vars->img_w, &vars->img_h);
	vars->img_e = mlx_xpm_file_to_image(vars->mlx, "./asset/home.xpm", &vars->img_w, &vars->img_h);
	vars->img_c = mlx_xpm_file_to_image(vars->mlx, "./asset/fish.xpm", &vars->img_w, &vars->img_h);
	vars->img_p = mlx_xpm_file_to_image(vars->mlx, "./asset/cat.xpm", &vars->img_w, &vars->img_h);

	int y = -1;
	while (++y < vars->h)
	{
		int x = -1;
		while (++x < vars->w)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img0, x * 48, y * 48);
			if (vars->map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img1, x * 48, y * 48);
			else if (vars->map[y][x] == 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_e, x * 48, y * 48);
				vars->escape_x = x;
				vars->escape_y = y;
			}
			else if (vars->map[y][x] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_c, x * 48, y * 48);
				(vars->item++);
			}
			else if (vars->map[y][x] == 'P')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_p, x * 48, y * 48);
				vars->pos_x = x;
				vars->pos_y = y;
			}
		}
	}
}

int	main(void)
{
	char	*m_line;
	int		fd;
	t_vars	vars;

	//init_value 함수로 초기화해주기
	init_value(&vars);
	fd = open("testmap.ber", O_RDONLY);
	if (!(fd))
	{
		printf("Error\n");
		return (0);
	}
	m_line = read_line(fd, &vars);
	close(fd);
	make_map(&vars, m_line);
	check_valid(&vars);
	check_wall_wrap(&vars);
	render_map(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, &occur_error, &vars);
	mlx_loop(vars.mlx);
	system("leaks a.out");
	return (0);
}
