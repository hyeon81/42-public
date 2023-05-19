/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:32:48 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/19 21:33:38 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdio.h>

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
		return (ERROR);
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
		exit_with_err("colorpasing_error\n");
	while (tmp[i])
	{
		num = ft_atoi(tmp[i++]);//중간에 이상한게 들어와서 0일경우는...?  0~9 로 이루어져있는지 체크/공백이 들온다면 에러?
		if (num < 0)
			return (ERROR);
		res += num << bit;
		bit -= 8;
	}
	if (type == C)
		vars->ceiling_color = res;
	if (type == F)
		vars->floor_color = res;
	free_all(tmp);
	return (0);
}

void	parse_direction(char **str, int identifier, t_vars *vars, int *id)
{	
	// int	i;

	// i = 0;
	*id = identifier;
	// while (str[1][i])
	// {
	// 	if (str[1][i] == '\n')
	// 		str[1][i] = '\0' ;
	// 	i++;
	// }
	if (*id == NO)
		vars->north = str[1];
	else if (*id == SO)
		vars->south = str[1];
	else if (*id == WE)
		vars->west = str[1];
	else if (*id == EA)
		vars->east = str[1];
	free(str[0]);
	free(str);
}

//만약 방향과 컬러 중간에 이상한 문자열이 들어온다면 에러일까

int	parse_color(char	**identifier, t_vars *vars, int *id)
{	
	if (ft_strncmp(identifier[0], "F", 2) == 0)
	{
		if (init_color(identifier[1], vars, F) == ERROR)
			return (ERROR);
		*id = F;
	}
	else if (ft_strncmp(identifier[0], "C", 2) == 0)
	{
		if (init_color(identifier[1], vars, C) == ERROR)
			return (ERROR);
		*id = C;
	}
	else 
		return (1);
	free_all(identifier);
	return (0);
}


int set_map(char    *line, t_vars *vars, t_check *check)
{
	char	**identifier;
	int	id;

	// if(check->count > 6) 
	// 	return(ERROR);
	if (check->count == 6)//이렇게 처리 하면 이 이상은 증가 할 일이 없음 애매하다잉.. 마지막 옵션이 중복이라면..? // 
		return (0);
	identifier = white_split(line); //탭 등등 추가 해야함...? 아마도..?
	// identifier = ft_split(line, ' '); //탭 등등 추가 해야함...? 아마도..?

	if (strs_len(identifier) != 2 || identifier[1] == NULL)
	{
		if (ft_strncmp(line, "\n", 2) != 0)
			exit_with_err("parsingnono\n");
		free_all(identifier);
		return (0);
	}
	if (ft_strncmp(identifier[0], "NO", 3) == 0)//들어온 인자와  identifier가 일치 하다면 밑에서 쓰일 id(flag check 용도)와 함께 파싱함수로 들어감
		parse_direction(identifier, NO, vars, &id);
	else if (ft_strncmp(identifier[0], "SO", 3) == 0)
		parse_direction(identifier, SO, vars, &id);
	else if (ft_strncmp(identifier[0], "WE", 3) == 0)
		parse_direction(identifier, WE, vars, &id);
	else if (ft_strncmp(identifier[0], "EA", 3) == 0)
		parse_direction(identifier, EA, vars, &id);
	else if (parse_color(identifier, vars, &id) == 1) //1이라는건 해당이 안된다는것임으로 그냥 끝
		exit_with_err("parse??\n");
	check->count++;
	if (check_double(id, check->mapset) == ERROR)
		return(ERROR);
	return (0);
}
