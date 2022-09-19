#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	char	*map;
	int		w;
	int		h;
	int     img_width;
	int     img_height;
	int     pos;
	void    *img;
	void	*bg;
}				t_vars;

int make_move(int keycode, t_vars *vars)
{
	//버튼 눌렀을때 반응
	if (keycode == 13 && vars->map[vars->pos - vars->w] == '0') //press W
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, (vars->pos%vars->w - 1) * 43, (vars->pos/vars->w) * 43);
		vars->pos = vars->pos - vars->w;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, (vars->pos%vars->w - 1) * 43, (vars->pos/vars->w) * 43);
	}
	else if (keycode == 0 && vars->map[vars->pos - 1] == '0') //press A
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, (vars->pos%vars->w - 1) * 43, (vars->pos/vars->w) * 43);
		vars->pos = vars->pos - vars->w;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, (vars->pos%vars->w - 1) * 43, (vars->pos/vars->w) * 43);
	}
	else if (keycode == 1) //press S
	{

	}
	else if (keycode == 2) //press D
	{

	}
}

int key_hook(int keycode, t_vars *vars)
{
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		make_move(keycode, vars);
	printf("press key: %d\n", keycode);
	//x 눌렀을때. 다른 키 처리
	return (0);
}

int render_map(char *map)
{
	//맵 렌더하기 전에 맵 유효성 검사하기
	void *img1;
	void *img3;
	void *img4;
	t_vars vars;
	vars.w = 13;
	vars.h = 5;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.w * 43, vars.h * 43, "Hello World!");

	img1 = mlx_xpm_file_to_image(vars.mlx, "./img/1.xpm", &vars.img_width, &vars.img_height);
	vars.bg = mlx_xpm_file_to_image(vars.mlx, "./img/2.xpm", &vars.img_width, &vars.img_height);
	img3 = mlx_xpm_file_to_image(vars.mlx, "./img/3.xpm", &vars.img_width, &vars.img_height);
	img4 = mlx_xpm_file_to_image(vars.mlx, "./img/4.xpm", &vars.img_width, &vars.img_height);
	vars.img = mlx_xpm_file_to_image(vars.mlx, "./img/5.xpm", &vars.img_width, &vars.img_height);

	int i = 0;
	int y = -1;
	while (++y < vars.h)
	{
		int x = -1;
		while (++x < vars.w)
		{
			if (map[i] == '1')
				mlx_put_image_to_window(vars.mlx, vars.win, img1, x * 43, y * 43);
			else if (map[i] == '0')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.bg, x * 43, y * 43);
			else if (map[i] == 'E')
				mlx_put_image_to_window(vars.mlx, vars.win, img3, x * 43, y * 43);
			else if (map[i] == 'C')
				mlx_put_image_to_window(vars.mlx, vars.win, img4, x * 43, y * 43);
			else if (map[i] == 'P')
			{
				mlx_put_image_to_window(vars.mlx, vars.win, vars.img, x * 43, y * 43);
				vars.pos = i + 1;
			}
			i++;
		}
	}
	vars.map = map;
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
