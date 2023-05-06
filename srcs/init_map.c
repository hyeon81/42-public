/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meliesf <meliesf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:49:07 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/06 04:21:15 by meliesf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

void	print_err(char	*str)
{
	write(1, str, ft_strlen(str)); // ㅇㅔ러를 내보내야하나
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

int cout_id(int num, int* check, int* count)
{
	int i;
	
	check[num]++; //해당 id에 +1; //주소..?
	if(check[num] > 1) //파싱이 한번을 초과 한 경우 에러로 거른다 
		return(ERROR);
	return(0);
}


int	parse_identifier(char *value, int id, t_vars *vars, int *f_id)
{	
	*f_id = id;
	if(!value)
		return(ERROR);
	if (id == NO)
		vars->north = value;
	else if (id == SO)
		vars->south = value;
	else if (id == WE)
		vars->west = value;
	else if (id == EA)
		vars->east = value;
	else if (id == F)
		vars->floor_color = value;
	else if (id == C)
		vars->ceiling_color = value;
}

int	is_identifier(char	*line, t_vars *vars, int *count, int* check)
{
	char	**identifier;
	int id;
	
	if(count > 6)
		return(ERROR);
	if(count == 6)
		return(0);
	identifier = ft_split(line, ' '); //탭 등등 추가 해야함...? 아마도..?
	if (strs_len(identifier) != 2)
		return (ERROR);
	if (ft_strncmp(identifier[0], "NO", 3) == 0)
		parse_identifier(identifier[1], NO, vars, &id);
	else if (ft_strncmp(identifier[0], "SO", 3) == 0)
		parse_identifier(identifier[1], SO, vars, &id);
	else if (ft_strncmp(identifier[0], "WE", 3) == 0)
		parse_identifier(identifier[1], WE, vars, &id);
	else if (ft_strncmp(identifier[0], "EA", 3) == 0)
		parse_identifier(identifier[1], EA, vars, &id);
	else if (ft_strncmp(identifier[0], "F", 2) == 0)
		parse_identifier(identifier[1], F, vars, &id);
	else if (ft_strncmp(identifier[0], "C", 2) == 0)
		parse_identifier(identifier[1], C, vars, &id);
	else
		return (ERROR);
	*count++;
	if (count_id(id, check, &count) == ERROR)//여기까지 왔다는건 파싱을 했다는 뜻
		return(ERROR);
	return (0);
}


int	parse_line(char *line) // map인경우 파싱
{
	int	i;
	int flag;
	
	i = 0;
	flag = 0;
	while (line[i])
	{
		if ((line[i] >= 9 && line[i] <= 13) || line[i] == ' ')
			i++;
		if (line[i] != '0' && line[i] != '1' && line[i] != '\n')
			flag = 1;
		else 
			return(ERROR);
		i++;
	}
	if(flag = 1)
		라인 조인으로 옮기기
}


//카운트, 하나당 하나

int	init_map(t_vars *vars, char *filename)
{
	int		fd;
	int	    i;
	char	*tmp;
	char	*backup;
	char	*line;
	int		count;
	int		*check;	

	i = 0;
	vars->cul = 0;
	count= 0; 
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		print_err("Failed to open file.\n");//exit..?
		return (ERROR);
	}

	backup = NULL;
	line = get_next_line(fd);
	check = ft_calloc(size_of(int) * 6, 0);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (ERROR);
		if (backup == NULL)
			backup = ft_strdup("");
		if (is_identifier(line, vars, &count, check) == ERROR || parse_line(line) == ERROR) //파스라인 한줄로 받고 스플릿 하자
			return (ERROR);
		// tmp = backup;
		// backup = ft_strjoin(backup, line);
		// free(tmp);
		free(line);
		i++;
	}	
	close(fd);
	return (0);
}