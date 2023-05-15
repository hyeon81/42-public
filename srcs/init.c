/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:54:12 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/15 21:13:45 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void load_img(t_vars *v, int *tex, char *path, t_img *img)
{
    int y = 0;
    int x = 0;

    img->ptr = mlx_xpm_file_to_image(v->mlx, path, &img->width, &img->height);
    img->data = (int *)mlx_get_data_addr(img->ptr, &img->bpp, &img->size_l, &img->endian);
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

void load_tex(t_vars *v)
{
    t_img img;

    load_img(v, v->tex[0], "./texture/wall_1.xpm", &img);
    load_img(v, v->tex[1], "./texture/wall_2.xpm", &img);
    load_img(v, v->tex[2], "./texture/wall_3.xpm", &img);
    load_img(v, v->tex[3], "./texture/wall_4.xpm", &img);
	v->map_img.ptr = mlx_new_image(v->mlx, v->width, v->height);
	v->map_img.data = (int *)mlx_get_data_addr(v->map_img.ptr, &v->map_img.bpp, &v->map_img.size_l, &v->map_img.endian);
}

void init_dir(int posDir, double *dirX, double *dirY, double *planeX, double *planeY)
{
    if(posDir == E)
    {
        *dirX = 1;
        *dirY = 0;
        *planeX = 0;
        *planeY = -0.66;
    }
    else if (posDir == W)
    {
        *dirX = -1;
        *dirY = 0;
        *planeX = 0;
        *planeY = 0.66;
    }
    else if(posDir == S)
    {
        *dirX = 0;
        *dirY = -1;
        *planeX = -0.66;
        *planeY = 0;
    }
    else
    {
        *dirX = 0;
        *dirY = 1;
        *planeX = 0.66;
        *planeY = 0;
    }
}

int init_vars(t_vars *vars)
{
	/* raycast */
    vars->posX = 12;
    vars->posY = 12;
    vars->time = 0; 
    vars->oldTime = 0; 
    vars->moveSpeed = 0.4;
    vars->rotateSpeed = 0.05;

	/* info */
	vars->row = 24;
	vars->col = 24;
	vars->width = 480;
	vars->height = 360;

    vars->posDir = E;
    init_dir(vars->posDir, &(vars->dirX), &(vars->dirY), &(vars->planeX), &(vars->planeY));
	/* mlx */
    vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "Cub3d");

	int i = 0;
	int j;

	vars->tex = (int **)malloc(sizeof(int *) * 4);
	i = 0;
	while (i < 4)
	{
		vars->tex[i] = (int *)malloc(sizeof(int) * (TEX_H * TEX_W));
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < TEX_W * TEX_H)
		{
			vars->tex[i][j] = 0;
			j++;
		}
		i++;
	}
    return (0);
}