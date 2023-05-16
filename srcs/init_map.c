/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:49:07 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/16 17:20:21 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int ft_is_space(char c) //space만 허용하게 하는건 어떨까
{
	if((c >= 9 && c <= 13) || c == ' ')
		return(0);
	return (1);
}

int	make_line(char *line, char **backup, t_check *check)
{
	int		i;
	char	*tmp;
	
	i = 0;
	while (line[i])
	{
		if (ft_is_space(line[i]) != 0 && line[i] != '0' && line[i] != '1' && \
			line[i] != '\n' && line[i] != 'N' && line[i] != 'S' && line[i] != \
			'W' && line[i] != 'E')
			return (ERROR);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
			check->path_count++;
		i++;
	}
	tmp = *backup;
	*backup = ft_strjoin(*backup, line);
	free(tmp);
	return (0);
}

int	parse_line(char *line, char **backup, t_check *check)
{
	int	i;

	i = 0;
	if (check->count != 6)
		return (0);
	if (check->mapflag == 1)
	{
		if (make_line(line, backup, check) == ERROR)
			return (ERROR);
		return (0);	
	}
	while (line[i])
	{
		if (line[i++] == '1')
		{
			check->mapflag = 1;
			if (make_line(line, backup, check) == ERROR)
				return (ERROR);
		}
	}
	return (0);
}

void	print(t_vars *vars)
{
	int	i = 0;
	while (vars->map[i])
		printf("%s\n", vars->map[i++]);
	printf("north = %s\n", vars->north);
	printf("south = %s\n", vars->south);
	printf("west = %s\n", vars->west);
	printf("east = %s\n", vars->east);
	printf("floorcolor = %d\n", vars->floor_color);
	printf("ceiling_color = %d\n", vars->ceiling_color);
}

int	init_map(t_vars	*vars, int fd, t_check *check)
{
	char	*backup;
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		//printf("line = %s", line);
		if (line == NULL)
			break ;
		if (backup == NULL)
			backup = ft_strdup("");
		if (parse_line(line, &backup, check) == ERROR)
			return (ERROR);
		printf("count = %d\n", check->count);
		if (set_map(line, vars, check) == ERROR) //파스라인 한줄로 받고 스플릿 하자
		{
			printf("error\n");
			return (ERROR);
		}
		free (line);
	}
	close(fd);
	free(check->mapset);
	if (backup)
	{
		vars->map = split_for_map(backup, '\n');
		free(backup);
	}
	else
		return (print_err("map_error"));
	print(vars);
	return (0);
}

// int	init_map(t_vars	*vars, char	*filename)
// {
// 	int		fd;
// 	char	*backup;
// 	char	*line;
// 	t_check	check;

// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 		return (print_err("Failed to open file.\n"));
// 	backup = NULL;
// 	check.mapsetting = ft_calloc(sizeof(int), 6);
// 	ft_memset(vars, 0, sizeof(t_vars));
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL) // 그럼 에러일 경우엔? 다 읽었을때
// 			break ;
// 		if (backup == NULL)
// 			backup = ft_strdup("");
// 		if (parse_line(line , &backup, &check) == ERROR)
// 			return (ERROR);
// 		if (set_map(line, vars, &check) == ERROR) //파스라인 한줄로 받고 스플릿 하자
// 			return (ERROR);
// 		free(line);
// 	}
// 	close (fd);
// 	if (backup)
// 	{
// 		vars->map = ft_map_split(backup, '\n');
// 		free(backup);
// 	}
// 	else
// 		return (print_err("map_error"));

// 	int i = 0;
// 	while(vars->map[i])
// 	{
// 		printf("%s\n", vars->map[i++]);
// 	}
// 	return (0);
// }


// 0 : 빈 공간
// 1 : 벽
// 공백 : 존재하지 않는 공간
// N, S, W or E : 플레이어의 초기 위치 및 시점
// 위 4가지 요소 이외의 정보가 있다면 유효하지 않은 map이다.
// map은 벽으로 둘러쌓여 있어야 한다.
// map 정보는 파일의 가장 마지막에 있어야 한다.
// 플레이어의 위치 정보(N, S, W or E)는 하나만 존재해야 한다.
// 플레이어의 위치 기준 동서남북엔 0 또는 1만 올 수 있다.
// 공백 기준 동서남북엔 공백 또는 1만 올 수 있다.
// -> 공백은 오직 1하고만 맞닿을 수 있다.


// Map : 한 줄 단위로 유효한 map인지 확인한다.
// 테두리가 벽(1)으로 둘러 쌓여있는지
// 0, 1, 공백, pos(플레이어의 초기 위치 및 시선)로만 이루어져 있는지
// pos정보는 하나만 있는지
// 나머지 정보는 배열에 옮겨 담고 확인
// map의 가로 최댓값, 세로 최댓값 구하기
// map의 정보를 linked list에 저장
