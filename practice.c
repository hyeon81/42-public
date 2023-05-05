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

int key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		ft_close(vars);
	else if (keycode == W)
		printf("press W\n");
	else if (keycode == A)
		printf("press A\n");
	else if (keycode == S)
		printf("press S\n");
	else if (keycode == D)
		printf("press D\n");
	return (0);
}

double posX = 22, posY = 12;  //플레잉어의 초기 위치 벡터
double dirX = -1, dirY = 0; //플레이어의 초기 방향 벡터
double planeX = 0, planeY = 0.66; //플레이어의 카메라 평면
double time = 0; //time of current frame
double oldTime = 0; //time of previous frame.
//둘의 시간차를 통해 특정 키를 눌렀을때 (일정한 속도로 움직이기 위해) 이동거리를 결정하고 FPS를 측정하는데 사용

int w = 640;
int h = 480;

void	verLine(t_vars *vars, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(vars->mlx, vars->win, x, y, color);
		y++;
	}
}

void make_draw(t_vars *vars)
{
    for(int x = 0; x < w; x++)
    {
        //calculate ray position and direction
        double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
        //for문의 x값(화면의 수직선)이 위치가 카메라평면에서 차지하는 x좌표 입니다. 
        //for문의 x값이 0이면 (스크린의 왼쪽 끝이면) cameraX = -1
        //for문의 x값이 w/2이면 (스크린의 중앙이면) cameraX = 0
        //for문의 x값이 w이면 (스크린의 오른쪽 끝이면) cameraX = 1
        double rayDirX = dirX + planeX * cameraX; //광선의 방향 벡터
        double rayDirY = dirY + planeY * cameraX;

        //우리가 있는 맵의 박스?
        int mapX = (int)posX;
        int mapY = (int)posY;

        //length of ray from current position to next x or y-side
        double sideDistX;
        double sideDistY;

        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
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
            sideDistX = (posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - posX) * deltaDistX;
        }
        if(rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (posY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - posY) * deltaDistY;
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
        int lineHeight = (int)(h / perpWallDist);

        //calculate lowest and highest pixel to fill in current stripe
        int drawStart = -lineHeight / 2 + h / 2;
        if(drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + h / 2;
        if(drawEnd >= h) drawEnd = h - 1;

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
        verLine(vars, x, drawStart, drawEnd, color);
    }
}

int make_move()
{

}

int main_loop(t_vars *vars)
{
    make_draw(vars);
    make_move(vars);
    return (0);
}

int main(void)
{
    t_vars vars;

    vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, w, h, "Cub3d");
    // mlx_hook(vars.win, ON_DESTROY, 0, &ft_close, &vars); //x 눌렀을때
	// mlx_key_hook(vars.win, &key_hook, &vars); //키보드 이벤트 감지
    mlx_loop_hook(vars.mlx, &main_loop, &vars);
    mlx_loop(vars.mlx);

    return (0);
}
