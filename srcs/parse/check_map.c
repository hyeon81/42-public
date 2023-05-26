/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:33:21 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/26 15:32:17 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validwall(char **map, int x, int y, int height)
{
	int	width;
	int	up_width;
	int	down_width;

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

void	wall_and_player(char **map, int i, int j, t_player *player)
{
	int	height;

	height = strs_len(map);
	if (map[i][j] == '0' || map[i][j] == player->direction)
	{	
		if (validwall(map, j, i, height))
			exit_with_err("Invalid map\n");
	}
	if (map[i][j] == player->direction)
	{
		player->pos.x = (double)j + 0.5;
		player->pos.y = (double)i + 0.5;
	}
}

int	check_valid(char **map, t_player *player, int *col, int *row)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			wall_and_player(map, i, j, player);
			if (tmp < j)
				tmp = j;
			j++;
		}
		i++;
	}
	*col = tmp + 1;
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

	i = 0;
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
