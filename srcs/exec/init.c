/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:54:12 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/23 18:03:17 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_img(t_vars *v, int *tex, char *path, t_img *img)
{
	int	x;
	int	y;

	img->ptr = mlx_xpm_file_to_image(v->mlx, path, &img->width, &img->height);
	if (!img->ptr)
	{
		write(2, "Error\n", 6);
		write(2, "texture load failed\n", 21);
		ft_exit(v);
	}
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
	mlx_destroy_image(v->mlx, img->ptr);
}

void	load_tex(t_vars *v)
{
	t_img	img;

	load_img(v, v->tex[0], v->c.east, &img);
	load_img(v, v->tex[1], v->c.west, &img);
	load_img(v, v->tex[2], v->c.south, &img);
	load_img(v, v->tex[3], v->c.north, &img);
}

void	init_dir(t_coord *dir, t_coord *plane, int direction)
{
	if (direction == EA)
	{
		set_coord(dir, 1, 0);
		set_coord(plane, 0, 0.66);
	}
	else if (direction == WE)
	{
		set_coord(dir, -1, 0);
		set_coord(plane, 0, -0.66);
	}
	else if (direction == NO)
	{
		set_coord(dir, 0, -1);
		set_coord(plane, 0.66, 0);
	}
	else
	{
		set_coord(dir, 0, 1);
		set_coord(plane, -0.66, 0);
	}
}

void	init_array(int ***tex)
{
	int	i;
	int	j;

	*tex = (int **)malloc(sizeof(int *) * 4);
	if (!(*tex))
		exit(1);
	i = 0;
	while (i < 4)
	{
		(*tex)[i] = (int *)malloc(sizeof(int) * (TEX_H * TEX_W + 1));
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < TEX_W * TEX_H + 1)
		{
			(*tex)[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	init_vars(t_vars *v, t_player *p)
{
	init_dir(&(p->dir), &(p->plane), p->direction);
	init_array(&(v->tex));
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WIDTH, HEIGHT, "Cub3d");
	v->map_img.ptr = mlx_new_image(v->mlx, WIDTH, HEIGHT);
	v->map_img.data = (int *)mlx_get_data_addr(v->map_img.ptr, &v->map_img.bpp, \
	&v->map_img.size_l, &v->map_img.endian);
}
