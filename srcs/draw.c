#include "cub3d.h"

int fill_bg (t_vars *v)
{
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
		    v->buf[y][x] = color;
            x++;
        }
		y++;
	}
	return (0);
}

int make_texX(t_vars *v)
{
    double wallX;
    if (v->side == 0)
        wallX = v->posY + v->perpWallDist * v->rayDirY;
    else
        wallX = v->posX + v->perpWallDist * v->rayDirX;
    wallX -= floor(wallX);
    int texX = (int)(wallX * (double)TEX_W);
    if (v->side == 0 && v->rayDirX > 0)
        texX = TEX_W - texX - 1;
    if (v->side == 1 && v->rayDirY < 0)
        texX = TEX_W - texX - 1;
    return (texX);
}

void fill_buf(t_vars *v, int x, int texX)
{
    double step = 1.0 * TEX_H / v->lineHeight;
    double texPos = (v->start - (v->height / 2) + (v->lineHeight / 2)) * step;

    int y = v->start;
    int texY;
    int tex_num;
    while (y < v->end)
    {
		texY = (int)texPos & (TEX_H - 1);
		texPos += step;
        if (v->rayDirX > 0 && v->side == 0) //east
			tex_num = 0;
		else if (v->rayDirX < 0 && v->side == 0) //west
			tex_num = 1;
		else if (v->rayDirY < 0 && v->side == 1) //south
			tex_num = 2;
		else //north
			tex_num = 3;
		v->buf[y][x] = v->tex[tex_num][TEX_H * texY + texX];
		y++;
    }
}

void draw_map(t_vars *v)
{
    int y;
    int x;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            v->img.data[y * WIDTH + x] = v->buf[y][x];
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(v->mlx, v->win, v->img.ptr, 0, 0);
}


int make_draw(t_vars *v, int x)
{
    int texX;

    texX = make_texX(v);
    fill_buf(v, x, texX);
    draw_map(v);
    return (0);
}
