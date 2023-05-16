/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:54:12 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/16 21:18:30 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_img(t_vars *v, int *tex, char *path, t_img *img)
{
	int	x;
	int	y;

	img->ptr = mlx_xpm_file_to_image(v->mlx, path, &img->width, &img->height);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bpp, &img->size_l, \
	&img->endian);
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			tex[img->width * y + x] = img->data[img->width * y + x];
			x++;
		}
		y++;
	}
}

void	load_tex(t_vars *v)
{
	t_img	img;

	load_img(v, v->tex[0], "./texture/wall_1.xpm", &img);
	load_img(v, v->tex[1], "./texture/wall_2.xpm", &img);
	load_img(v, v->tex[2], "./texture/wall_3.xpm", &img);
	load_img(v, v->tex[3], "./texture/wall_4.xpm", &img);
}

void	init_dir(t_coord *dir, t_coord *plane, int pos_dir)
{
	if (pos_dir == E)
	{
		set_coord(dir, 1, 0);
		set_coord(plane, 0, -0.66);
	}
	else if (pos_dir == W)
	{
		set_coord(dir, -1, 0);
		set_coord(plane, 0, 0.66);
	}
	else if (pos_dir == S)
	{
		set_coord(dir, 0, -1);
		set_coord(plane, -0.66, 0);
	}
	else
	{
		set_coord(dir, 0, 1);
		set_coord(plane, 0.66, 0);
	}
}

void	init_array(int ***tex)
{
	int	i;
	int	j;

	*tex = (int **)malloc(sizeof(int *) * 4);
	i = 0;
	while (i < 4)
	{
		(*tex)[i] = (int *)malloc(sizeof(int) * (TEX_H * TEX_W));
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < TEX_W * TEX_H)
		{
			(*tex)[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	init_vars(t_vars *v)
{
	v->pos.x = 12;
	v->pos.y = 12;
	v->row = 24;
	v->col = 24;
	v->width = 480;
	v->height = 360;
	v->pos_dir = W;
	v->f_color = 0x00ef91;
	v->c_color = 0x364369;
	init_dir(&(v->dir), &(v->plane), v->pos_dir);
	init_array(&(v->tex));

	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, v->width, v->height, "Cub3d");
	v->map_img.ptr = mlx_new_image(v->mlx, v->width, v->height);
	v->map_img.data = (int *)mlx_get_data_addr(v->map_img.ptr, &v->map_img.bpp, \
	&v->map_img.size_l, &v->map_img.endian);
	return (0);
}
