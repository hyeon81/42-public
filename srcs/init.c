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
	v->img.ptr = mlx_new_image(v->mlx, v->width, v->height);
	v->img.data = (int *)mlx_get_data_addr(v->img.ptr, &v->img.bpp, &v->img.size_l, &v->img.endian);
}
int init_vars(t_vars *vars)
{
	/* raycast */
    vars->posX = 12;
    vars->posY = 12;
    vars->dirX = -1;
    vars->dirY = 0; 
    vars->planeX = 0;
    vars->planeY = 0.66; 
    vars->time = 0; 
    vars->oldTime = 0; 
    vars->moveSpeed = 0.5;
    vars->rotateSpeed = 0.1;

	/* info */
	vars->row = 24;
	vars->col = 24;
	vars->width = 480;
	vars->height = 360;
	vars->texture[0].tex = 0x90F564;
	vars->texture[1].tex = 0x7178F5;
	vars->texture[2].tex = 0xF5F558;
	vars->texture[3].tex = 0xF540E9;

	/* mlx */
    vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "Cub3d");

	int i = 0;
	int j;
    
    int x;
    int y;
    int color;

    y = 0;
	while (y < HEIGHT) 
	{
        x = 0;
        while (x < WIDTH)
        {
            if (y < HEIGHT / 2)
                color = 0x0067a3;
            else
                color = 0x964b00;
		    vars->buf[y][x] = color;
            x++;
        }
		y++;
	}
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