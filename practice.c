#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480
#include "cub3d.h"

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int	ft_close(t_vars *vars)
{
	//창 뿌수고 종료
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	make_draw(t_vars *vars, int x, int y1, int y2, int color)
{
    mlx_clear_window(vars->mlx, vars->win);
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(vars->mlx, vars->win, x, y, color);
		y++;
	}
}

void check_hit(t_vars *vars)
{
    for(int x = 0; x < vars->width; x++)
    {
        //calculate ray position and direction
        double cameraX = 2 * x / (double)vars->width - 1; //x-coordinate in camera space
        //for문의 x값(화면의 수직선)이 위치가 카메라평면에서 차지하는 x좌표 입니다. 
        //for문의 x값이 0이면 (스크린의 왼쪽 끝이면) cameraX = -1
        //for문의 x값이 w/2이면 (스크린의 중앙이면) cameraX = 0
        //for문의 x값이 w이면 (스크린의 오른쪽 끝이면) cameraX = 1
        double rayDirX = vars->dirX + vars->planeX * cameraX; //광선의 방향 벡터
        double rayDirY = vars->dirY + vars->planeY * cameraX;

        //우리가 있는 맵의 박스?
        int mapX = (int)vars->posX;
        int mapY = (int)vars->posY;

        //length of ray from current position to next x or y-side
        double sideDistX;
        double sideDistY;

        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX); //1e30 이건 어디서 나온 숫자여
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

        //what direction to step in x or y-direction (either +1 or -1)
        int stepX;
        int stepY;

        int hit = 0; //was there a wall hit?
        int side; //was a NS or a EW wall hit?
        //calculate step and initial sideDist
        if(rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (vars->posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - vars->posX) * deltaDistX;
        }
        if(rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (vars->posY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - vars->posY) * deltaDistY;
        }
        //perform DDA
        while(hit == 0)
        {
            //jump to next map square, either in x-direction, or in y-direction
            if(sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            //Check if ray has hit a wall
            if(worldMap[mapX][mapY] > 0) hit = 1;
        }
        
        double perpWallDist;

        if(side == 0) perpWallDist = (sideDistX - deltaDistX);
        else          perpWallDist = (sideDistY - deltaDistY);

        //Calculate height of line to draw on screen
        int lineHeight = (int)(vars->height / perpWallDist);

        //calculate lowest and highest pixel to fill in current stripe
        int drawStart = -lineHeight / 2 + vars->height / 2;
        if(drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + vars->height / 2;
        if(drawEnd >= vars->height) drawEnd = vars->height - 1;

        //choose wall color
        int color;
        switch(worldMap[mapX][mapY])
        {
            case 1:  color = 0x90F564; break; //green
            case 2:  color = 0x7178F5; break; //blue
            case 3:  color = 0xF5F558; break; //yellow
            case 4:  color = 0xF540E9; break; //pink
            default: color = 0xF5D34C; break; //deep yellow
        }

        //give x and y sides different brightness
        if(side == 1) {color = color / 2;}

        //draw the pixels of the stripe as a vertical line
        make_draw(vars, x, drawStart, drawEnd, color);
    }
}

int make_move(int keycode, t_vars *vars)
{
	if (keycode == W)
	{
		if (!worldMap[(int)(vars->posX + vars->dirX * vars->moveSpeed)][(int)(vars->posY)])
			vars->posX += vars->dirX * vars->moveSpeed;
		if (!worldMap[(int)(vars->posX)][(int)(vars->posY + vars->dirY * vars->moveSpeed)])
			vars->posY += vars->dirY * vars->moveSpeed;
	}
	//move backwards if no wall behind you
	if (keycode == S)
	{
		if (!worldMap[(int)(vars->posX - vars->dirX * vars->moveSpeed)][(int)(vars->posY)])
			vars->posX -= vars->dirX * vars->moveSpeed;
		if (!worldMap[(int)(vars->posX)][(int)(vars->posY - vars->dirY * vars->moveSpeed)])
			vars->posY -= vars->dirY * vars->moveSpeed;
	}
	//rotate to the right
	if (keycode == D)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = vars->dirX;
		vars->dirX = vars->dirX * cos(-vars->rotateSpeed) - vars->dirY * sin(-vars->rotateSpeed);
		vars->dirY = oldDirX * sin(-vars->rotateSpeed) + vars->dirY * cos(-vars->rotateSpeed);
		double oldPlaneX = vars->planeX;
		vars->planeX = vars->planeX * cos(-vars->rotateSpeed) - vars->planeY * sin(-vars->rotateSpeed);
		vars->planeY = oldPlaneX * sin(-vars->rotateSpeed) + vars->planeY * cos(-vars->rotateSpeed);
	}
	//rotate to the left
	if (keycode == A)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = vars->dirX;
		vars->dirX = vars->dirX * cos(vars->rotateSpeed) - vars->dirY * sin(vars->rotateSpeed);
		vars->dirY = oldDirX * sin(vars->rotateSpeed) + vars->dirY * cos(vars->rotateSpeed);
		double oldPlaneX = vars->planeX;
		vars->planeX = vars->planeX * cos(vars->rotateSpeed) - vars->planeY * sin(vars->rotateSpeed);
		vars->planeY = oldPlaneX * sin(vars->rotateSpeed) + vars->planeY * cos(vars->rotateSpeed);
	}
	if (keycode == ESC)
		exit(0);
	return (0);
}

int main_loop(t_vars *vars)
{
    check_hit(vars);
    return (0);
}

int init_vars(t_vars *vars)
{
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
    vars->width = 640;
    vars->height = 480;
    vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "Cub3d");

    return (0);
}

int main(void)
{
    t_vars vars;

    init_vars(&vars);
    mlx_hook(vars.win, ON_DESTROY, 0, &ft_close, &vars); //x 눌렀을때
	mlx_key_hook(vars.win, &make_move, &vars); //키보드 이벤트 감지
    mlx_loop_hook(vars.mlx, &main_loop, &vars);
    mlx_loop(vars.mlx);

    return (0);
}
