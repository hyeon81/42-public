/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:33:18 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/22 17:23:48 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_int_free(int **arr, int idx)
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

void	ft_char_free(char **arr, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

int	ft_exit(t_vars *v)
{
	// free
	ft_int_free(v->tex, 4);
	mlx_destroy_image(v->mlx, v->map_img.ptr);
	mlx_destroy_window(v->mlx, v->win);
	exit(0);
}

void	set_coord(t_coord *c, double x, double y)
{
	c->x = x;
	c->y = y;
}
