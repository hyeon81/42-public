#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	char	*map;
	int		w;
	int		h;
	int     img_width;
	int     img_height;
	int		escape_x;
	int		escape_y;
	int     pos;
	int		item;
	int		get_item;
	int		move_count;
	void    *img;
	void	*img3;
	void	*bg;
	void	*img4;
}				t_vars;

int make_move(int keycode, t_vars *vars)
{
	//버튼 눌렀을때 반응
	if (keycode == 13 && vars->map[vars->pos - vars->w] != '1') //press W
	{
		if (vars->map[vars->pos - vars->w] == 'E')
			vars->pos = vars->pos - vars->w;
		else 
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, ((vars->pos)%vars->w) * 48, ((vars->pos)/vars->w) * 48); //지우고
			vars->pos = vars->pos - vars->w;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, ((vars->pos)%vars->w) * 48, ((vars->pos)/vars->w) * 48); //이동
			vars->move_count++;
		}
	}
	else if (keycode == 0 && vars->map[vars->pos - 1] != '1') //press A
	{
		if (vars->map[vars->pos - 1] == 'E')
			vars->pos = vars->pos - 1;
		else
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, ((vars->pos)%vars->w) * 48, ((vars->pos)/vars->w) * 48);
			vars->pos = vars->pos - 1;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, ((vars->pos)%vars->w) * 48, ((vars->pos)/vars->w) * 48);
			vars->move_count++;
		}
	}
	else if (keycode == 1 && vars->map[vars->pos + vars->w] != '1') //press S
	{
		if (vars->map[vars->pos + vars->w] == 'E')
			vars->pos = vars->pos + vars->w;
		else
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, ((vars->pos)%vars->w) * 48, ((vars->pos)/vars->w) * 48); //지우고
			vars->pos = vars->pos + vars->w;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, ((vars->pos)%vars->w) * 48, ((vars->pos)/vars->w) * 48); //이동
			vars->move_count++;
		}
	}
	else if (keycode == 2 && vars->map[vars->pos + 1] != '1') //press D
	{
		if (vars->map[vars->pos + 1] == 'E')
			vars->pos = vars->pos + 1;
		else
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, ((vars->pos)%vars->w) * 48, ((vars->pos)/vars->w) * 48); //지우고
			vars->pos = vars->pos + 1;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, ((vars->pos)%vars->w) * 48, ((vars->pos)/vars->w) * 48); //이동
			vars->move_count++;
		}
	}
	
	printf("your_move_count: %d\n", vars->move_count);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img3, vars->escape_x * 48, vars->escape_y * 48);
	//아이템이었을 경우
	if (vars->map[vars->pos] == 'C')
		(vars->get_item)++;
	//출구였을 경우
	if (vars->map[vars->pos] == 'E')
	{
		if (vars->item <= vars->get_item)
		{
			printf("Good! You escape!");
			exit(0);
		}
		else
			printf("You need to get all fish!");
	}
}

int key_hook(int keycode, t_vars *vars)
{
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		make_move(keycode, vars);
	printf("press key: %d\n", keycode);
	//x 눌렀을때. 다른 키 처리
	if (keycode == 53)
		exit(0);
	return (0);
}

// int close(int keycode, t_vars* vars)
// {
// 	// mlx_destroy_window(vars->mlx, vars->win);
// 	exit(0);
// }

int render_map(t_vars *vars)
{
	//맵 렌더하기 전에 맵 유효성 검사하기
	void *img1;
	vars->w = 13;
	vars->h = 5;
	vars->item = 0;
	vars->get_item = 0;
	vars->move_count = 0;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->w * 48, vars->h * 48, "Hello World!");

	img1 = mlx_xpm_file_to_image(vars->mlx, "./asset/fence.xpm", &vars->img_width, &vars->img_height);
	vars->bg = mlx_xpm_file_to_image(vars->mlx, "./asset/field.xpm", &vars->img_width, &vars->img_height);
	vars->img3 = mlx_xpm_file_to_image(vars->mlx, "./asset/home.xpm", &vars->img_width, &vars->img_height);
	vars->img4 = mlx_xpm_file_to_image(vars->mlx, "./asset/fish.xpm", &vars->img_width, &vars->img_height);
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./asset/cat.xpm", &vars->img_width, &vars->img_height);

	int i = 0;
	int y = -1;
	while (++y < vars->h)
	{
		int x = -1;
		while (++x < vars->w)
		{
			if (vars->map[i] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, img1, x * 48, y * 48);
			else if (vars->map[i] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, x * 48, y * 48);
			else if (vars->map[i] == 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img3, x * 48, y * 48);
				vars->escape_x = x;
				vars->escape_y = y;
			}
			else if (vars->map[i] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img4, x * 48, y * 48);
				(vars->item++);
			}
			else if (vars->map[i] == 'P')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x * 48, y * 48);
				vars->pos = i;
			}
			i++;
		}
	}
	mlx_key_hook(vars->win, key_hook, &vars);
	// mlx_hook(vars->win, 17, 0, close, &vars);
	mlx_loop(vars->mlx);
	return (0);
}
