/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:33:18 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/17 20:13:36 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(int **arr, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = 0;
}

int	ft_exit(t_vars *v)
{
	/* free */
	ft_free(v->tex, 4);
	mlx_destroy_image(v->mlx, v->map_img.ptr);
	mlx_destroy_window(v->mlx, v->win);
	exit(0);
}

void	set_coord(t_coord *c, double x, double y)
{
	c->x = x;
	c->y = y;
}
