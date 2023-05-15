/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:49:07 by eunjiko           #+#    #+#             */
/*   Updated: 2023/05/15 20:56:48 by eunjiko          ###   ########.fr       */
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
	if (check[num] > 1) //한번을 초과해 중복했을 경우 에러를 내보낸다
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

	res = 0;
	bit = 16;
	tmp = ft_split(value, ',');
	if (strs_len(tmp) != 3 || !tmp[0] || !tmp[1] || !tmp[2])
		return (ERROR);
	while (tmp[i])
	{
		num = ft_atoi(tmp[i++]);// 범위는 아토이에서 처리해줌
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
		return (ERROR);
	return (0);
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

int	set_map(char	*line, t_vars *vars, t_check *check)
{
	char	**identifier;
	int	id;

	// if(check->count > 6) 
	// 	return(ERROR);
	if (check->count == 4)//이렇게 처리 하면 이 이상은 증가 할 일이 없음 애매하다잉.. 마지막 옵션이 중복이라면..? // 
		return (0);
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
	else if (parse_color(identifier, vars, &id)== ERROR)
		return (ERROR);
	else
		return (ERROR);
	check->count++;
	if (count_id(id, check->mapsetting) == ERROR)
		return (ERROR);
	return (0);
}

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
	if (check->count != 4)
		return (0);
	if (check->mapflag == 1)
	{
		if (make_line(line, backup, check) == ERROR)
			return (ERROR);
		return (0);	
	}
	while (line[i])
	{
		// printf("line check = %c\n", line[i]);
		if (line[i++] == '1')
		{
			check->mapflag = 1;
			if (make_line(line, backup, check) == ERROR)
				return (ERROR);
		}
	}
	return (0);
}


int read_line(t_check *check)
{
	char	*line;

	backup = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL) // 그럼 에러일 경우엔? 다 읽었을때
			break ;
		if (backup == NULL)
			backup = ft_strdup("");
		if (parse_line(line , &backup, &check) == ERROR)
			return (ERROR);
		if (set_map(line, vars, &check) == ERROR) //파스라인 한줄로 받고 스플릿 하자
			return (ERROR);
		free(line);
	}
	return (0);
}

int	init_map(t_vars	*vars, char	*filename)
{
	int		fd;
	char	*backup;
	char	*line;
	t_check	check;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (print_err("Failed to open file.\n"));
	check.mapsetting = ft_calloc(sizeof(int), 6);
	ft_memset(vars, 0, sizeof(t_vars));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL) // 그럼 에러일 경우엔? 다 읽었을때
			break ;
		if (backup == NULL)
			backup = ft_strdup("");
		if (parse_line(line , &backup, &check) == ERROR)
			return (ERROR);
		if (set_map(line, vars, &check) == ERROR) //파스라인 한줄로 받고 스플릿 하자
			return (ERROR);
		free(line);
	}
	close (fd);
	if (backup)
	{
		vars->map = ft_map_split(backup, '\n');
		free(backup);
	}
	else
		return (print_err("map_error"));

	int i = 0;
	while(vars->map[i])
	{
		printf("%s\n", vars->map[i++]);
	}
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
