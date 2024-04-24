/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:32:48 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/26 15:02:31 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_double(int num, int *check)
{
	int	flag;

	flag = 0;
	if (num == NO)
		flag = 0;
	else if (num == SO)
		flag = 1;
	else if (num == EA)
		flag = 2;
	else if (num == WE)
		flag = 3;
	else if (num == F)
		flag = 4;
	else if (num == C)
		flag = 5;
	check[flag]++;
	if (check[flag] > 1)
		exit_with_err("Invalid identifier\n");
	return (0);
}

int	init_color(char *value, t_vars *vars, int type)
{
	char	**tmp;
	int		res;
	int		num;
	int		i;
	int		bit;

	i = 0;
	res = 0;
	bit = 16;
	tmp = ft_split(value, ',');
	if (!tmp || strs_len(tmp) != 3)
		exit_with_err("Invalid identifier\n");
	while (tmp[i])
	{
		num = save_num(tmp[i]);
		res += num << bit;
		bit -= 8;
		i++;
	}
	if (type == C)
		vars->c.ceiling_color = res;
	if (type == F)
		vars->c.floor_color = res;
	free_all(tmp);
	return (0);
}

int	parse_color(char	**identifier, t_vars *vars, int *id)
{	
	if (ft_strncmp(identifier[0], "F", 2) == 0)
	{
		init_color(identifier[1], vars, F);
		*id = F;
	}
	else if (ft_strncmp(identifier[0], "C", 2) == 0)
	{
		init_color(identifier[1], vars, C);
		*id = C;
	}
	else
		return (1);
	free_all(identifier);
	return (0);
}

void	parse_direction(char **str, int identifier, t_vars *vars, int *id)
{	
	int	i;

	i = 0;
	*id = identifier;
	while (str[1][i])
	{
		if (str[1][i] == '\n')
			str[1][i] = '\0';
		i++;
	}
	if (*id == NO && vars->c.north == NULL)
		vars->c.north = str[1];
	else if (*id == SO && vars->c.south == NULL)
		vars->c.south = str[1];
	else if (*id == WE && vars->c.west == NULL)
		vars->c.west = str[1];
	else if (*id == EA && vars->c.east == NULL)
		vars->c.east = str[1];
	else
		free(str[1]);
	free(str[0]);
	free(str);
}

int	set_map(char *line, t_vars *vars, t_check *check)
{
	char	**identifier;
	int		id;

	identifier = white_split(line);
	if (strs_len(identifier) != 2 || identifier[1] == NULL)
	{
		if (ft_strncmp(line, "\n", 2) != 0)
			exit_with_err("Invalid map\n");
		free_all(identifier);
		return (0);
	}
	if (ft_strncmp(identifier[0], "NO", 3) == 0)
		parse_direction(identifier, NO, vars, &id);
	else if (ft_strncmp(identifier[0], "SO", 3) == 0)
		parse_direction(identifier, SO, vars, &id);
	else if (ft_strncmp(identifier[0], "WE", 3) == 0)
		parse_direction(identifier, WE, vars, &id);
	else if (ft_strncmp(identifier[0], "EA", 3) == 0)
		parse_direction(identifier, EA, vars, &id);
	else if (parse_color(identifier, vars, &id) == 1)
		exit_with_err("Invalid identifier\n");
	check->count++;
	check_double(id, check->mapset);
	return (0);
}
