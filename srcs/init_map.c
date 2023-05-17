/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:49:07 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/17 21:59:46 by eunjiko          ###   ########.fr       */
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

// int	check_valid(char **map, t_player *player, int *col, int *row)// 밑에 개행 없애고 가로 세로 체크
// {
// 	int	i;
// 	int	j;
// 	int tmp;
// 	// player 위치
// 	// col, row	
// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == player->direction)
// 			{
// 				player->x = i;
// 				player->y = j;
// 			}
// 			if (tmp < j)
// 				tmp = j;
// 			j++;
// 		}
// 		tmp = j;
// 		i++;
// 	}
// 	return (0);
// }

int	check_remove(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_is_space(line[i++]) != 0)
			return (0);
	}
	return (1); // 다 공백
}

void	remove_newline(char	**map, int	*direction)
{
	int	i;
	int	j;
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


int	save_map(char **backup, t_vars *vars, t_check *check, int *direction)
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
		remove_newline(vars->map, direction);
		// check_valid(vars->map, &(vars->player), &(vars->col), &(vars->row));
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
	if (check->path_count != 1 || !save_map(&backup, vars, check, \
		&(vars->player.direction)))
		return (ERROR);
	print(vars);
	return (0);
}