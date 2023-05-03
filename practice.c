#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480
#include "../header/cub3d.h"

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

int main(void)
{
    double posX = 22, posY = 12;  //플레잉어의 초기 위치 벡터
    double dirX = -1, dirY = 0; //플레이어의 초기 방향 벡터
    double planeX = 0, planeY = 0.66; //플레이어의 카메라 평면

    double time = 0; //time of current frame
    double oldTime = 0; //time of previous frame.
    //둘의 시간차를 통해 특정 키를 눌렀을때 (일정한 속도로 움직이기 위해) 이동거리를 결정하고 FPS를 측정하는데 사용

    t_vars vars;
    vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 480, 480, "Cub3d");

    mlx_hook(vars.win, ON_DESTROY, 0, &ft_close, &vars); //x 눌렀을때
	mlx_key_hook(vars.win, &key_hook, &vars); //키보드 이벤트 감지
    while (!done()) //이 반복문은 계속 반복해서 전체 프레임을 그려내고 입력을 읽는 일을 합니다.
    {
        for(int x = 0; x < w; x++)
        {
            //calculate ray position and direction
            double cameraX = 2 * x / double(w) - 1; //x-coordinate in camera space
            //for문의 x값(화면의 수직선)이 위치가 카메라평면에서 차지하는 x좌표 입니다. 
            //for문의 x값이 0이면 (스크린의 왼쪽 끝이면) cameraX = -1
            //for문의 x값이 w/2이면 (스크린의 중앙이면) cameraX = 0
            //for문의 x값이 w이면 (스크린의 오른쪽 끝이면) cameraX = 1
            double rayDirX = dirX + planeX * cameraX; //광선의 방향 벡터
            double rayDirY = dirY + planeY * cameraX;


        }
    }
    mlx_loop(vars.mlx);
    return (0);
}
