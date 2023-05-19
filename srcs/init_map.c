/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:49:07 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/19 21:24:46 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (0);
	return (1);
}

int	make_line(char *line, char **backup, t_check *check, int *direction)
{
	int		i;
	char	*tmp;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1' && \
			line[i] != '\n' && line[i] != 'N' && line[i] != 'S' && line[i] != \
			'W' && line[i] != 'E')
			return (ERROR);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || \
			line[i] == 'E')
		{
			*direction = line[i];
			check->path_count++;
		}
		i++;
	}
	tmp = *backup;
	*backup = ft_strjoin(*backup, line);
	free(tmp);
	return (0);
}

int	parse_line(char *line, char **backup, t_check *check, int *direction)
{
	int	i;

	i = 0;
	if (check->count != 6)
		return (0);
	if (check->mapflag == 1)
	{
		if (make_line(line, backup, check, direction) == ERROR)
			return (ERROR);
		return (0);
	}
	while (ft_is_space(line[i]) == 0)
			i++;
	if (!line[i])
		return (0);
	if (line[i] == '1')
	{
		check->mapflag = 1;
		if (make_line(line, backup, check, direction) == ERROR)
			return (ERROR);
	}
	else
		return (ERROR);
	return (0);
}


//첫줄 , 마지막줄이 벽으로 이루어져있는지 각 줄의 첫번째 인덱스가 벽인지

//
//1. \n , ' ' 일 경우 해당 위치의 옆이 공백이나 1로 설정이 되어있는지 확인 (이경우는 좌)
//2. ' ' 가 들어온 경우는 상 하 좌 우 모두 체크

// 1. 0의 동서남북에 개행 또는 띄어쓰기가 있으면 에러 == 
// int	validwall(char** map, int x, int y, char c)
// {
// 	printf("validwall = %c\n", c);

// 	printf("3_1\n");
// 	printf("map[y][x - 1] = %c\n", map[y][x - 1]);
// 	int 
// 	if (map[y][x - 1] && map[y][x - 1] != ' ' && map[y][x - 1] != '1')
// 		return (1);
// 	printf("3_2\n");
// 	if (c == ' ')
// 	{
// 		if	((map[y][x + 1] != ' ' && map[y][x + 1] != '1') || \
// 			(map[y + 1][x] != ' ' && map[y + 1][x] != '1') || \
// 			(map[y - 1][x] != ' ' && map[y - 1][x] != '1'))
// 			return (1);
// 	}
// 	return (0);
// }


// int	check_valid(char **map, t_player *player, int *col, int *row)// 밑에 개행 없애고 가로 세로 체크
// {
// 	int	i;
// 	int	j;
// 	int	tmp;

// 	i = 0;
// 	tmp = 0;
// 	while (map[0][i])
// 	{
// 		if (map[0][i] != '1' && map[0][i] != ' ' && map[0][i] != '\n')
// 			return (ERROR);
// 		i++;
// 	}
// 	i = 0;
// 	while (map[i])
// 	{
// 		if (map[i][0] && map[i][0] != '1' && map[i][0] != ' ' && map[i][0] != '\n') //왼쪽 사이드
// 			return (ERROR);
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == ' ' || map[i][j] == '\n')//' '/개행일때 '상하좌우'가 1과 ' '뿐인지
// 			{	
// 				printf("3\n");
// 				if(i > 0 && j > 0)
// 				{
// 					if (validwall(map, i, j, map[i][j]))
// 						return (ERROR);
// 				}
// 				// printf("4\n");
// 			}
// 			printf("5\n");
// 			if (map[i][j] == player->direction)
// 			{
// 				player->x = j;
// 				player->y = i;
// 			}
// 			if (tmp < j)
// 				tmp = j;
// 			j++;
// 		}
// 		i++;
// 	}
// 	*col = tmp + 2;
// 	*row = i;
// 	j = 0;
// 	i--;
// 			printf("6\n");

// 	while (map[i][j])
// 	{
// 		if (map[i][j] != '1' && map[i][j] != ' ' && map[i][j] != '\n')
// 			return (ERROR);
// 		j++;
// 	}
// 			printf("7\n");

// 	// printf("c = %c\n", player->direction);
// 	// printf("x = %d\n", player->x);
// 	// printf("y = %d\n", player->y);
// 	// printf("col = %d\n", *col);
// 	// printf("row = %d\n", *row);
// 	return (0);
// }

int validwall(char **map, int x, int y, int height)
{
	int width;
	int up_width;
	int down_width;
	width = ft_strlen(map[y]);
	if (y == 0 || y == height - 1)
		return (1);
	if (x == 0 || x == width -1)
		return (1);
	up_width = ft_strlen(map[y - 1]);
	down_width = ft_strlen(map[y + 1]);
	if (x > up_width - 1 || x > down_width - 1)
		return (1);
	if (map[y - 1][x] == ' ')
		return (1);
	if (map[y + 1][x] == ' ')
		return (1);
	if (map[y][x - 1] == ' ')
		return (1);
	if (map[y][x + 1] == ' ')
		return (1);
	return (0);
}

int	check_valid(char **map, t_player *player, int *col, int *row)// 밑에 개행 없애고 가로 세로 체크
{
	int	i;
	int	j;
	int	tmp;
	int height;
	
	i = 0;
	tmp = 0;
	i = 0;
	height = strs_len(map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == player->direction)
			{	
					if (validwall(map, j, i, height))
					{
						printf("%d %d\n", j, i);
						return (ERROR);
					}
			}
			if (map[i][j] == player->direction)
			{
				player->x = j;
				player->y = i;
			}
			if (tmp < j)
				tmp = j;
			j++;
		}
		i++;
	}
	*col = tmp + 2;
	*row = i;
	return (0);
}

int	check_remove(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_is_space(line[i++]) != 0)
			return (0);
	}
	return (1);
}

void	remove_newline(char	**map)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (map[i])
		i++;
	i--;
	while (i > 0)
	{
		if (check_remove(map[i]))
		{
			free(map[i]);
			map[i] = NULL;
		}
		else
			break ;
		i--;
	}
}


int	save_map(char **backup, t_vars *vars, t_check *check)
{
	int i;
	int j;

	i = 0;
	j = 0;
	free(check->mapset);
	if (*backup)
	{
		vars->map = split_for_map(*backup, '\n');
		free(*backup);//free in split
		remove_newline(vars->map);
		if (check_valid(vars->map, &(vars->player), &(vars->col), &(vars->row)) == ERROR)
			return (0);
	}
	else
		return (0);
	return (1);
}

int	init_map(t_vars	*vars, int fd, t_check *check)
{
	char	*backup;
	char	*line;

	backup = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (backup == NULL)
			backup = ft_strdup("");
		if (check->path_count > 1 || parse_line(line, &backup, check, \
			&(vars->player.direction)) == ERROR)
			return (ERROR);
		if (set_map(line, vars, check) == ERROR)
			return (ERROR);
		free (line);
	}
	close(fd);
	if (check->path_count != 1 || !save_map(&backup, vars, check))
		return (ERROR);
	print(vars);
	return (0);
}