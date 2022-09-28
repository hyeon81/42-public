/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:33:12 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/09/28 18:18:14 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image(t_vars *vars, void *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img, x * 48, y * 48);
}

int	ft_exit(t_vars	*vars)
{
	printf("game is close!");
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	error_occur(int flag)
{
	if (flag == -2)
		printf("Error! this is argument error or fd error\n");
	if (flag == -3)
		printf("Error! map is not surrounded by wall\n");
	if (flag == -4)
		printf("Error! map is not square\n");
	if (flag == 0)
		printf("Error! Element is not enough\n");
	if (flag == 1)
		printf("Error! P should be one\n");
	if (flag == 2)
		printf("Error! C does not exist\n");
	if (flag == 3)
		printf("Error! E should be one\n");
	exit(0);
}
