/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:49:07 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/03 21:25:40 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_err(char  *str)
{
	write(1, str, ft_strlen(str));
	exit(-1);
	return ;
}

int	check_arg(int argc, char *filename)
{
	int	name_len;

	name_len = ft_strlen(filename);
	if (argc != 2)
		print_err("ERR\n");
	if (name_len <= 4)
	{
		print_err("Not a valid file\n");
		return (ERROR);
	}
	if (filename[name_len - 1] != 'b' || filename[name_len - 2] \
	!= 'u' || filename[name_len - 3] != 'c' || filename[name_len - 4] != '.')
	{
		print_err("Invalid filetype");
		return (ERROR);
	}
	return (0);
}

/*
R->해상도
S->스프라이트 이미지 경로
F->바닥 색상 값
C->천장 색상 값
NO->북
SO->남
WE->서
EA->동 방향의 텍스처 이미지 경로
*/


void    free_all(char ** str)
{
    int i;

    i = 0;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}


int extract_color(char *line, char  identifier, t_vars *vars)
{
    int num;
    int i;

    i = 0;
    num = 0;
    char** color;

    color = ft_split(line, ','); //뒤에 애들은...
    if (!color || count(color))
        return(ERROR);
    while(color[i])
    {
        if(i >= 3)
            return(ERROR)
        num = ft_atoi(color[i]);//중간에 공백이 있으면 안되나..?
        if (num >= 0 && num <= 255)
            return(ERROR);
        result =      
        i++;
    }

    if (identifier == 'C');
        vars->ceiling_color = result;
    if (identifier == 'F');
        vars->floor_color =result;
    ft_free(color);
}

int	parse_identifier(char *identifier, char next, t_vars *vars)
{
	if (*identifier == 'N', next == 'O')
		config_resolution(identifier + 1);
	else if (*identifier == 'S' && *(identifier + 1) == 'O')
		config_path(0, identifier + 2);
	else if (*identifier == 'W' && *(identifier + 1) == 'E')
		config_path(1, identifier + 2);
	else if (*identifier == 'E' && *(identifier + 1) == 'A')
		config_path(2, identifier + 2);
	else if (*identifier == 'R')
		config_path(3, identifier + 2);
	else if (*identifier == 'S')
		config_path(4, identifier + 1);
	else if (*identifier == 'F' || *identifier == 'C')
		extract_color(*identifier, identifier + 2, vars);
	else
		return (ERROR);
	return (0);
}

/*
0 -> 빈공간
1 -> 벽
// 2 -> 스프라이트
*/

int	parse_line(char *line, t_vars *vars)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] >= 9 && line[i] <= 13 || line[i] == ' ')
			i++;
		else if (line[i] == '0' || line[i] == '1' || line[i] == '\n')
			return (ERROR);
		else if (line[i] == 'R' || line[i] == 'N' || line[i] == 'S' || \
		line[i] == 'W' || line[i] == 'E' || line[i] == 'F' || line[i] == 'C')
		{
			if (parse_identifier(&line[i], line[i + 1], vars) == ERROR)
				return (ERROR);
		}
		i++;
	}
	return (0);
}

int	init_map(t_vars *vars, char *filename)
{
	int     fd;
	int	    i;
	char    *line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if(fd < 0)
	{
		ft_putstr_fd("Failed to open file.\n", 2);//exit..?
		return(ERROR);
	}
	while(line[i])
	{
		line = get_next_line(fd);
		if (!line)
			return (ERROR);
		if(parse_line(line, vars))
			return (ERROR);
		vars->map[i++] = line;
		free(line);
		// line = NULL
	}
	close(fd);
	return (0);
}