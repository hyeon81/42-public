#include "cub3d.h"


void init_loop_vars(t_vars *vars, int x)
{
	vars->cameraX = 2 * x / (double)vars->width - 1; //카메라 평면에서 차지하는 x좌표
	vars->rayDirX = vars->dirX + vars->planeX * vars->cameraX; //광선의 방향 벡터
	vars->rayDirY = vars->dirY + vars->planeY * vars->cameraX;
	vars->mapX = (int)vars->posX;
	vars->mapY = (int)vars->posY;
	if (vars->rayDirX == 0) 
		vars->deltaDistX = 0;
	else
		vars->deltaDistX = fabs(1 / vars->rayDirX);
	if (vars->rayDirY == 0)
		vars->deltaDistY = 0;
	else
		vars->deltaDistY = fabs(1 / vars->rayDirY);
	vars->hit = 0;
}

int	calc_step_sideDist(t_vars *v)
{
    if(v->rayDirX < 0)
    {
        v->stepX = -1;
        v->sideDistX = (v->posX - v->mapX) * v->deltaDistX;
    }
    else
    {
        v->stepX = 1;
        v->sideDistX = (v->mapX + 1.0 - v->posX) * v->deltaDistX;
    }
    if(v->rayDirY < 0)
    {
        v->stepY = -1;
        v->sideDistY = (v->posY - v->mapY) * v->deltaDistY;
    }
    else
    {
        v->stepY = 1;
        v->sideDistY = (v->mapY + 1.0 - v->posY) * v->deltaDistY;
    }
	return (0);
}

int make_step(t_vars *v)
{
	while (v->hit == 0)
	{
		if (v->sideDistX < v->sideDistY)
		{
			v->sideDistX += v->deltaDistX;
			v->mapX += v->stepX;
			v->side = 0;
		}
		else
		{
			v->sideDistY += v->deltaDistY;
			v->mapY += v->stepY;
			v->side = 1;
		}
		if (worldMap[v->mapX][v->mapY] > 0)
			v->hit = 1;
	}
	return (0);
}

int clac_draw_line(t_vars *v)
{
	if (v->side == 0)
		// v->perpWallDist = v->sideDistX - v->deltaDistX;
        v->perpWallDist = (v->mapX - v->posX + (1 - v->stepX) / 2) / v->rayDirX;
	else
		// v->perpWallDist = v->sideDistY - v->deltaDistY;
        v->perpWallDist = (v->mapY - v->posY + (1 - v->stepY) / 2) / v->rayDirY;
	v->lineHeight = (int)(v->height / v->perpWallDist);
	v->start = (-(v->lineHeight) / 2) + (v->height / 2);
	if (v->start < 0)
		v->start = 0;
	v->end = (v->lineHeight / 2) + (v->height / 2);
	if (v->end >= v->height)
		v->end = v->height - 1;
	return (0);
}


int main_loop(t_vars *vars)
{
	int x;

	x = 0;
	make_background(vars);
	/* draw screen */
	while (x < vars->width)
	{
		init_loop_vars(vars, x);
		calc_step_sideDist(vars);
		make_step(vars);
		clac_draw_line(vars);
		make_draw(vars, x);
		x++;
	}
	return (0);
}
