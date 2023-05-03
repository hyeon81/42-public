#include "cub3d.h"

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

// int render_map(t_vars *vars)
// {
// 	int map[COL][ROW]={
// 		{-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
// 		{-1,-1,-1,-1,-1,-1,-1,-1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 		{-1,-1,-1,-1,-1,-1,-1,-1,1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 		{-1,-1,-1,-1,-1,-1,-1,-1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 		{1,1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 		{1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
// 		{1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,1,0,0,0,1,-1,-1,-1,-1},
// 		{1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,0,0,1,0,0,0,1,-1,-1,-1,-1},
// 		{1,1,0,0,0,0,0,0,1,1,0,1,0,1,0,1,1,1,0,0,0,0,0,0,1,0,0,0,1,-1,-1,-1,-1},
// 		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,1,-1,-1,-1,-1},
// 		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,1,0,0,1,0,0,0,1,-1,-1,-1,-1},
// 		{1,1,0,0,0,0,0,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1,0,2,0,1,1,1,-1,-1},
// 		{1,1,1,1,0,1,1,1,-1,1,1,1,0,1,0,1,-1,1,0,1,1,1,1,0,1,0,0,0,1,-1,-1,-1,-1},
// 		{1,1,1,1,1,1,1,1,-1,1,1,1,1,1,1,1,-1,1,1,1,1,1,1,1,1,1,1,1,1,-1,-1,-1,-1}
// 	}; //w는 빈곳, 1은 벽, 0은 공간, n은 스폰위치와 방향. (wesn으로 구성)

// 	int img_w = 48;
// 	int img_h = 48;
// 	//이미지 생성
// 	vars->img1 = mlx_xpm_file_to_image(vars->mlx, "./asset/fence.xpm", &img_w, &img_h);
// 	vars->img0 = mlx_xpm_file_to_image(vars->mlx, "./asset/field.xpm", &img_w, &img_h);
// 	vars->imgw = mlx_xpm_file_to_image(vars->mlx, "./asset/fence2.xpm", &img_w, &img_h);
// 	vars->imgp = mlx_xpm_file_to_image(vars->mlx, "./asset/cat.xpm", &img_w, &img_h);

// 	int x = 0;
// 	int y = 0;
// 	while (y < COL)
// 	{
// 		x = 0;
// 		while (x < ROW)
// 		{
// 			if (map[y][x] == 0)
// 				mlx_put_image_to_window(vars->mlx, vars->win, vars->img0, x * 48, y * 48);
// 			else if (map[y][x] == 1)
// 				mlx_put_image_to_window(vars->mlx, vars->win, vars->img1, x * 48, y * 48);
// 			else if (map[y][x] == 2)
// 				mlx_put_image_to_window(vars->mlx, vars->win, vars->imgp, x * 48, y * 48);
// 			else
// 				mlx_put_image_to_window(vars->mlx, vars->win, vars->imgw, x * 48, y * 48);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (0);
// }
