/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:53:55 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/17 20:53:10 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_block(t_vars *v, int x, int y, int color)
{
	int	i;
	int	j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			v->map_img.data[(y + i) * WIDTH + x + j] = color;
			j++;
		}
		i++;
	}
}

void	make_draw_minimap(t_vars *v)
{
	int	i;
	int	j;

	i = 0;
	while (i < v->row)
	{
		j = 0;
		while (j < v->col)
		{
			if (v->map[i][j] == '1')
				draw_block(v, j, i, 0xFFFFFF);
			else if ((int)v->p->pos.y == i && (int)v->p->pos.x == j)
				draw_block(v, j, i, 0xA63641);
			else
				draw_block(v, j, i, 0x808080);
			j++;
		}
		i++;
	}
}
