#include "cub3d.h"


void init_loop_vars(t_vars *v, int x)
{
	//calculate ray position and direction
	v->cameraX = 2 * x / (double)v->width - 1; //카메라 평면에서 차지하는 x좌표
	v->rayDirX = v->dirX + v->planeX * v->cameraX; //광선의 방향 벡터
	v->rayDirY = v->dirY + v->planeY * v->cameraX;
	v->mapX = (int)v->posX;
	v->mapY = (int)v->posY;
	v->deltaDistX = fabs(1 / v->rayDirX);
	v->deltaDistY = fabs(1 / v->rayDirY);
	// if (v->rayDirX == 0) 
	// 	v->deltaDistX = 1e30; //뭘까 이 숫자..
	// else
	// 	v->deltaDistX = fabs(1 / v->rayDirX);
	// if (v->rayDirY == 0)
	// 	v->deltaDistY = 1e30;
	// else
	// 	v->deltaDistY = fabs(1 / v->rayDirY);
	v->hit = 0;
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
	while (1)
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
		if (worldMap[v->mapX][v->mapY] == 1)
			break;
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