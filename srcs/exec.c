#include "cub3d.h"

void init_raycast(t_vars *vars, int x)
{
	vars->cameraX = 2 * x / (double)vars->width - 1; //카메라 평면에서 차지하는 x좌표
	vars->rayDirX = vars->dirX + vars->planeX * vars->cameraX; //광선의 방향 벡터
	vars->rayDirY = vars->dirY + vars->planeY * vars->cameraX;
	vars->mapX = (int)vars->posX;
	vars->mapY = (int)vars->posY;
}

void make_raycast(t_vars *vars)
{
	int x;

	x = 0;
	while (x < vars->width)
	{
		init_raycast(vars, x);
		
		x++;
	}
}

int make_move(int keycode, t_vars *vars)
{
	if (keycode == W)
	{

	}
	if (keycode == S)
	{

	}
	if (keycode == A)
	{
		
	}
	if (keycode == D)
	{
		
	}
}

int main_loop(t_vars *vars)
{
	check_hit(vars);

	return (0);
}

int init_vars(t_vars *vars)
{
	/* raycast */
    vars->posX = 22;
    vars->posY = 12;
    vars->dirX = -1;
    vars->dirY = 0; 
    vars->planeX = 0;
    vars->planeY = 0.66; 
    vars->time = 0; 
    vars->oldTime = 0; 
    vars->moveSpeed = 0.5;
    vars->rotateSpeed = 0.3;

	/* info */
    vars->width = 640;
    vars->height = 480;
	vars->tex[0].tex = 0x90F564;
	vars->tex[1].tex = 0x7178F5;
	vars->tex[2].tex = 0xF5F558;
	vars->tex[3].tex = 0xF540E9;

	/* mlx */
    vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "Cub3d");

    return (0);
}