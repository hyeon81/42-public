
#include "so_long.h"
#include "get_next_line.h"

int make_new_pos(t_vars *vars, int new_pos_x, int new_pos_y, int add)
{
	if (vars->map[vars->pos_y - 1][vars->pos_x] == 'E')
		vars->pos_y = vars->pos_y + add;
	else 
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, vars->pos_x * 48, vars->pos_y * 48); //지우고
		vars->pos_y = vars->pos_y + add;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pos_x * 48, vars->pos_y * 48); //이동
		vars->move_count++;
	}
}

int make_move(int keycode, t_vars *vars)
{
	//버튼 눌렀을때 반응
	if (keycode == 13 && vars->map[vars->pos_y - 1][vars->pos_x] != '1') //press W
	{

		if (vars->map[vars->pos_y - 1][vars->pos_x] == 'E')
			vars->pos_y--;
		else 
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, vars->pos_x * 48, vars->pos_y * 48); //지우고
			vars->pos_y--;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pos_x * 48, vars->pos_y * 48); //이동
			vars->move_count++;
		}
	}
	else if (keycode == 0 && vars->map[vars->pos_y][vars->pos_x - 1] != '1') //press A
	{
		if (vars->map[vars->pos_y][vars->pos_x - 1] == 'E')
			vars->pos_x--;
		else
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, vars->pos_x * 48, vars->pos_y * 48);
			vars->pos_x--;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pos_x * 48, vars->pos_y * 48);
			vars->move_count++;
		}
	}
	else if (keycode == 1 && vars->map[vars->pos_y + 1][vars->pos_x] != '1') //press S
	{
		if (vars->map[vars->pos_y + 1][vars->pos_x] == 'E')
			vars->pos_y++;
		else
		{
			printf("here!\n");
			mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, vars->pos_x * 48, vars->pos_y * 48); //지우고
			vars->pos_y++;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pos_x * 48, vars->pos_y * 48); //이동
			vars->move_count++;
		}
	}
	else if (keycode == 2 && vars->map[vars->pos_y][vars->pos_x + 1] != '1') //press D
	{
		if (vars->map[vars->pos_y][vars->pos_x + 1] == 'E')
			vars->pos_x++;
		else
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, vars->pos_x * 48, vars->pos_y * 48); //지우고
			vars->pos_x++;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pos_x * 48, vars->pos_y * 48); //이동
			vars->move_count++;
		}
	}
	printf("your_move_count: %d\n", vars->move_count);
	printf("y: %d, x: %d\n", vars->pos_y, vars->pos_x);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img3, vars->escape_x * 48, vars->escape_y * 48);
	//아이템이었을 경우
	if (vars->map[vars->pos_y][vars->pos_x] == 'C')
		(vars->get_item)++;
	//출구였을 경우
	if (vars->map[vars->pos_y][vars->pos_x] == 'E')
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

int game_close(int keycode, t_vars* vars)
{
	// mlx_destroy_window(vars->mlx, vars->win);
	// exit(0);
}

int render_map(t_vars *vars)
{
	void *img1;
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

	int y = -1;
	while (++y < vars->h)
	{
		int x = -1;
		while (++x < vars->w)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, x * 48, y * 48);
			if (vars->map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, img1, x * 48, y * 48);
			else if (vars->map[y][x] == 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img3, x * 48, y * 48);
				vars->escape_x = x;
				vars->escape_y = y;
			}
			else if (vars->map[y][x] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img4, x * 48, y * 48);
				(vars->item++);
			}
			else if (vars->map[y][x] == 'P')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x * 48, y * 48);
				vars->pos_x = x;
				vars->pos_y = y;
			}
		}
	}
	mlx_key_hook(vars->win, key_hook, vars);
	// mlx_hook(vars->win, 17, L0, close, vars);
	mlx_loop(vars->mlx);
	return (0);
}


void make_map(t_vars *vars, char *m_line)
{
	int i = 0;
	int	j = 0;
	int m = 0;

	vars->map = (char **)malloc(sizeof(char *) * (vars->h + 1));
	while (i < vars->h)
	{
		vars->map[i] = (char *)malloc(sizeof(char) * (vars->w + 1));
		i++;
	}
	i = 0;
	while (i < vars->h)
	{
		j = 0;
		while (j < vars->w)
		{
			vars->map[i][j] = m_line[m];
			m++;
			j++;
		}
		i++;
	}
	// i = 0;
	// while (i < vars->h)
	// {
	// 	j = 0;
	// 	while (j < vars->w)
	// 	{
	// 		printf("%c", vars->map[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
}

int occur_error()
{
	printf("Error!\n");
	exit(0);
}

//지도 에러 체크
void check_valid(t_vars *vars)
{
	int j = 0;
	//P가 있는지 체크
	while (j < vars->h)
	{
		int i = 0;
		while (i < vars->w)
		{
			if (!(vars->map[j][i] == 'P' || vars->map[j][i] == 'E' || vars->map[j][i] == '1' || vars->map[j][i] == '0' || vars->map[j][i] == 'C'))
				occur_error();
			if (vars->map[j][i] == 'P')
				vars->p++;
			if (vars->map[j][i] == 'C')
				vars->c++;
			if (vars->map[j][i] == 'E')
				vars->e++;
			i++;
		}
		j++;
	}
	if (vars->p != 1 || vars->c < 1 || vars->e != 1)
		occur_error();
}

void check_wall_wrap(t_vars *vars)
{
	int j = 0;
	while (j < vars->h)
	{
		int i = 0;
		while (i < vars->w)
		{
			if (vars->map[0][i] != '1')
				occur_error();
			if (vars->map[j][0] != '1')
				occur_error();
			if (vars->map[vars->h - 1][i] != '1')
				occur_error();
			if (vars->map[j][vars->w - 1] != '1')
				occur_error();
			i++;
		}
		j++;
	}
}

void init_value(t_vars *vars)
{
	vars->h = 1;
	vars->p = 0;
	vars->c = 0;
	vars->e = 0;
}

char *read_line(int fd, t_vars *vars)
{
	char*	line;
	char*	m_line;
	char*	temp;

	line = get_next_line(fd);
	m_line = ft_strdup(line);
	vars->w = ft_strlen(line);
	free(line);
    while (line)
    {
        line = get_next_line(fd);
    	printf("Gnl line : %s\n", line);
		if (line == 0)
			break;
		if (vars->w != ft_strlen(line))
		{
			printf("Error!\n");
			return (0);
		}
		temp = ft_strjoin(m_line, line);
		ft_free(&m_line, &temp, 1);
		(vars->h)++;
        free(line);
    }
	return (m_line);
}

//지도 파싱
int main() 
{
	char*	m_line;
	int		fd;
	t_vars vars;

	//init_value 함수로 초기화해주기
	init_value(&vars);
    if (!(fd = open("testmap.ber", O_RDONLY)))
    {
    	printf("Error\n");
        return (0);
    }
	m_line = read_line(fd, &vars);
	make_map(&vars, m_line);
	check_valid(&vars);
	check_wall_wrap(&vars);
	render_map(&vars);
	close(fd);
    // system("leaks a.out");
    return (0);
}