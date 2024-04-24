/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:33:12 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/10/04 13:08:54 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image(t_vars *vars, void *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img, x * 48, y * 48);
}

int	ft_exit(t_vars	*vars)
{	
	mlx_destroy_image(vars->mlx, vars->img0);
	mlx_destroy_image(vars->mlx, vars->img1);
	mlx_destroy_image(vars->mlx, vars->img_e);
	mlx_destroy_image(vars->mlx, vars->img_c);
	mlx_destroy_image(vars->mlx, vars->img_p);
	mlx_destroy_window(vars->mlx, vars->win);
	ft_exit_free(vars);
	printf("game is close!");
	exit(0);
}

void	ft_exit_free(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	vars->map = 0;
}

void	error_occur(int flag, t_vars *vars)
{
	if (flag == -2)
		printf("Error! this is argument error or fd error\n");
	if (flag == -3)
		printf("Error! map is not surrounded by wall\n");
	if (flag == -4)
		printf("Error! map is not square\n");
	if (flag == -5)
		printf("Error! this is empty file\n");
	if (flag == 0)
		printf("Error! Element is not enough\n");
	if (flag == 1)
		printf("Error! P should be one\n");
	if (flag == 2)
		printf("Error! C does not exist\n");
	if (flag == 3)
		printf("Error! E should be one\n");
	if (flag != -2 && flag != -4)
		ft_exit_free(vars);
	exit(0);
}

void	ft_free_m_line(char *m_line)
{
	free(m_line);
	m_line = 0;
}
