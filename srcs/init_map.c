/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meliesf <meliesf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:49:07 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/13 02:25:37 by meliesf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

int	check_arg(int argc, char *filename)
{
	int	name_len;

	name_len = ft_strlen(filename);
	if (name_len <= 4)
		return (ERROR);
	if (filename[name_len - 1] != 'b' || filename[name_len - 2] != 'u' \
	|| filename[name_len - 3] != 'c' || filename[name_len - 4] != '.')
		return (ERROR);
	return (0);
}

int	count_id(int num, int *check)
{
	int	i;

	check[num]++;
	while (check[num])
		num++;
	if (check[num] > 1) //파싱이 한번을 초과 한 경우 에러로 거른다 
		return (ERROR);
	return (0);
}

int	init_color(char *value, t_vars *vars, int type, int *id)
{
	char	**tmp;
	int		res;

	tmp = ft_split(value, ',');
	res = 0;
	if(strs_len(tmp) != 3)
		return(ERROR);
	while(tmp[i])
	{
		// 아토이인데 부호가 안되는...핳
	}
	if(type == C)
		vars->ceiling_color = res;
	if(type == F)
		vars->floor_color = res;
	*id = type;
	return (0);
}

static int	color_parse(char *line)
{
	char	**str;
	int		rgb_r;
	int		rgb_g;
	int		rgb_b;
	int		color;

	str = ft_split(line, ',');
	if (!str || !str[0] || !str[1] || !str[2] || get_strnum(str) != 3)
	{
		free_str(str);
		print_err("Wrong color value\n");
	}
	color = 0;
	rgb_r = change_str_to_int(str[0]); -> 8 -> 0000 0000 0000 1000 0000 0000 0000 0000 
	rgb_g = change_str_to_int(str[1]);
	rgb_b = change_str_to_int(str[2]);
	color = (rgb_r << 16) + (rgb_g << 8) + rgb_b;
	free_str(str);
	return (color);
}

/*
	int color => 0000 0000 r0000 0000 g0000 0000 b0000 0000
	r g b
	r <<< 8 
	char 1byte 0 255 rgb -> 0-255 -> 0000 0000 0 ~ 255 1111 1111
*/

int	parse_color( char* color, char *value, t_vars *vars, int *id)
{	
	if (ft_strncmp(color, "F", 2) == 0)
	{
		if(init_color(value, vars, F, id) == ERROR)
			return(ERROR);
	}
	else if (ft_strncmp(color, "C", 2) == 0)
	{
		if(init_color(value, vars, C, id) == ERROR)
			return(ERROR);
	}
	else
		return (ERROR);
	return(0);
}

void	parse_direction(char *value, int identifier, t_vars *vars, int *id)
{	
	*id = identifier;

	if (*id == NO)
		vars->north = value;
	else if (*id == SO)
		vars->south = value;
	else if (*id == WE)
		vars->west = value;
	else if (*id == EA)
		vars->east = value;
}

int	is_identifier(char	*line, t_vars *vars, int *count, int *check)
{
	char	**identifier;
	int id;

	// if(*count > 6) 
	// 	return(ERROR);
	if(*count == 4) //이렇게 처리 하면 이 이상은 증가 할 일이 없음 애매하다잉.. 마지막 옵션이 중복이라면..? 
		return(0);
	identifier = ft_split(line, ' '); //탭 등등 추가 해야함...? 아마도..?
	if (strs_len(identifier) != 2 || identifier[1] == NULL)
		return (ERROR);
	if (ft_strncmp(identifier[0], "NO", 3) == 0)//들어온 인자와  identifier가 일치 하다면 밑에서 쓰일 id(flag check 용도)와 함께 파싱함수로 들어감
		parse_direction(identifier[1], NO, vars, &id);
	else if (ft_strncmp(identifier[0], "SO", 3) == 0)
		parse_direction(identifier[1], SO, vars, &id);
	else if (ft_strncmp(identifier[0], "WE", 3) == 0)
		parse_direction(identifier[1], WE, vars, &id);
	else if (ft_strncmp(identifier[0], "EA", 3) == 0)
		parse_direction(identifier[1], EA, vars, &id);
	else
		if (parse_color(identifier[0], identifier[1] ,vars, &id)== ERROR)
			return(ERROR);
	(*count)++; // identifier가 들어왔다는건 어쨋든 파싱을 한다는것이기에 하나씩 올려줌
	if (count_id(id, check) == ERROR) //id당 하나만 들어왔는지 체크 아니면 에러
		return(ERROR);
	return (0);
}

int ft_is_space(char c) //space만 허용하게 하는건 어떨까
{
	if((c >= 9 && c <= 13) || c == ' ')
		return(0);
	return (1);
}


int	check_line(char* line)
{
	int i = 0;
	while(line[i])
	{
		if (ft_is_space(line[i]) != 0 && line[i] != '0' && line[i] != '1' && \
			line[i] != '\n' && line[i] != 'N' && line[i] != 'S' && line[i] != 'W' &&line[i] != 'E') 
			return(ERROR);
		if(line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
			// count++:
		i++
	}
}

int	parse_line(char *line, char **backup, int* mapflag, int count) // map인경우 파싱
{
	int		i;
	char	*tmp;

	i = 0;
	if(count != 4)
		return(0);
	//위치카운트가 1이 아니라면 에러
	if (*mapflag == 1)
	{
		check_line();
		tmp = *backup;
		*backup = ft_strjoin(*backup, line);
		free(tmp);
		return (0);
	}
	while (line[i])//처음에 맵을 만났을 경우 맵이 시작됐다는 플래그를 주기 위해 //맵의 첫줄을 만나기 위한 와일문인데 맵의 첫줄은 무조건 1이여야함
	{
		printf("line check = %c\n", line[i]);
		// if (ft_is_space(line[i]) != 0 && line[i] != '0' && line[i] != '1' && \
		// line[i] != '\n' && line[i] != 'N' && line[i] != 'S' && line[i] != 'W' &&line[i] != 'E') 
		// 	return (ERROR); //위치 또한 한개가 아니라면 리턴
		if (line[i] == '1') //1과 공백으로만 이루어져있다면 첫줄은 유효한 맵의 시작
				*mapflag = 1;
		i++;
	}
	if (!*mapflag)
		return (0);
	tmp = *backup;
	*backup = ft_strjoin(*backup, line);
	free(tmp);
	return(0);
}

int	init_map(t_vars *vars, char *filename)
{
	int		fd;
	int	    i;
	char	*backup;
	char	*line;
	int		mapflag;

	int		count;
	int		*check;	

	i = 0;
	count = 0;
	mapflag = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (print_err("Failed to open file.\n"));
	backup = NULL;
	check = ft_calloc(sizeof(int), 6);	
	while (1)
	{
		line = get_next_line(fd);
		printf("line = %s \n" , line);
		if (line == NULL) // 그럼 에러일 경우엔? 다 읽었을때
			break ;
		if (backup == NULL)
			backup = ft_strdup("");
		if (parse_line(line , &backup, &mapflag, count) == ERROR)
			return (ERROR);
		if (is_identifier(line, vars, &count, check) == ERROR) //파스라인 한줄로 받고 스플릿 하자
			return (ERROR);
		free(line);
		i++;
	}
	printf("map = \n%s\n", backup);
	close(fd);
	if(backup)
	{
		vars->map = ft_map_split(backup, '\n');
		free(backup);
	}
	else
		return(print_err("map_error"));
	i = 0;
	while(vars->map[i])
	{
		printf("%s\n", vars->map[i++]);
	}
	return (0);
}
