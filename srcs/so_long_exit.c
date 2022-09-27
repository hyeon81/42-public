#include "so_long.h"

void	ft_put_image(t_vars *vars, void *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img, x * 48, y * 48);
}

//end free
void	ft_exit_free(char **map, char *m_line, int flag)
{
	int i;

	i = 0;
	if (m_line)
		free(m_line);
	if (flag == 1)
	{	
		while (!(map[i]))
		{
			free(map[i]);
			i++;
		}
	}
	free(map);
	map = 0;
	exit(0);
} 

void	error_occur(int flag)
{
	if (flag == -1)
		printf("You escape!");
	if (flag == -2)
		printf("Error! argument is only one\n");
	if (flag == -3)
		printf("Error! map is not surrounded by wall\n");
	if (flag == -4)
		printf("Error! map is not square\n");
	if (flag == 0)
		printf("Error! Element is not enough\n");
	if (flag == 1)
		printf("Error! P should be one\n");
	if (flag == 2)
		printf("Error! C does not exist\n");
	if (flag == 3)
		printf("Error! E should be one\n");
	system("leaks so_long");
	exit(0);
}
