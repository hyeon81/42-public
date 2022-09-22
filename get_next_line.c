/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 20:15:49 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/09/22 17:31:42 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int render_map(t_vars *vars);
void	ft_free(char **s1, char **s2, int flag)
{
	free(*s1);
	if (flag == 1)
		*s1 = *s2;
	else
		*s1 = 0;
}

char	*ft_split_line(char *s1, int start, int end)
{
	char	*arr;
	int		i;

	i = 0;
	arr = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!arr)
		return (0);
	while ((s1[start] != 0) && (start <= end))
	{
		arr[i] = s1[start];
		start++;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_return_last(char **backup, char **buf)
{
	char	*temp;
	char	*line;
	int		newline_idx;

	if (buf)
		ft_free(buf, 0, 0);		
	if (*backup[0] == '\0')
	{
		ft_free(backup, 0, 0);
		return (0);
	}
	if ((ft_strchr(*backup, '\n')) >= 0)
	{
		newline_idx = ft_strchr(*backup, '\n');
		line = ft_split_line(*backup, 0, newline_idx);
		temp = ft_split_line(*backup, newline_idx + 1, ft_strlen(*backup));
		ft_free(backup, &temp, 1);
		return (line);
	}
	temp = ft_strdup(*backup);
	ft_free(backup, 0, 0);
	return (temp);
}

char	*ft_make_line(char **backup, char **buf)
{
	char	*temp;
	char	*line;
	int		newline_idx;

	temp = ft_strjoin(*backup, *buf);
	ft_free(backup, &temp, 1);
	if (ft_strchr(*backup, '\n') >= 0)
	{	
		newline_idx = ft_strchr(*backup, '\n');
		line = ft_split_line(*backup, 0, newline_idx - 1);
		temp = ft_split_line(*backup, newline_idx + 1, ft_strlen(*backup));
		ft_free(backup, &temp, 1);
		return (line);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*backup;
	int			line_idx;
	char		*line;
	int			BUFFER_SIZE = 2;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!backup)
		backup = ft_strdup("");
	line_idx = read(fd, buf, BUFFER_SIZE);
	while (line_idx > 0)
	{
		buf[line_idx] = '\0';
		line = ft_make_line(&backup, &buf);
		if (line != 0)
		{
			ft_free(&buf, 0, 0);
			return (line);
		}
		line_idx = read(fd, buf, BUFFER_SIZE);
	}
	return (ft_return_last(&backup, &buf));
}

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void make_map(t_vars *vars, char *m_line)
{
	int i = 0;
	int	j = 0;
	int m = 0;

	vars->map = (char **)malloc(sizeof(char *) * (vars->h + 1));
	while (i < vars->h)
	{
		vars->map[i] = (char *)malloc(sizeof(char) * (vars->w + 1));
		i++;
	}
	i = 0;
	while (i < vars->h)
	{
		j = 0;
		while (j < vars->w)
		{
			vars->map[i][j] = m_line[m];
			m++;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < vars->h)
	{
		j = 0;
		while (j < vars->w)
		{
			printf("%c", vars->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int occur_error()
{
	printf("Error!\n");
	exit(0);
}

//지도 에러 체크
void check_valid(t_vars *vars)
{
	int j = 0;
	while (j < vars->h)
	{
		int i = 0;
		while (i < vars->w)
		{
			if (!(vars->map[j][i] == 'P' || vars->map[j][i] == 'E' || vars->map[j][i] == '1' || vars->map[j][i] == '0' || vars->map[j][i] == 'C'))
				occur_error();
			i++;
		}
		j++;
	}	
}

//지도 파싱
int main() 
{
	char*	line;
	int		fd;
	char*	m_line;
	char*	temp;
	t_vars vars;

	vars.h = 1;
    if (!(fd = open("testmap.ber", O_RDONLY)))
    {
    	printf("Error\n");
        return (0);
    }
	line = get_next_line(fd);
	printf("Gnl line : %s\n", line);
	m_line = ft_strdup(line);
	vars.w = ft_strlen(line);
	free(line);
	
    while (line)
    {
        line = get_next_line(fd);
    	printf("Gnl line : %s\n", line);
		if (line == 0)
			break;
		//라인이 유효한지 확인
		if (vars.w != ft_strlen(line))
		{
			printf("Error!\n");
			return (0);
		}
		//읽은 라인을 배열에 넣어줌
		temp = ft_strjoin(m_line, line);
		ft_free(&m_line, &temp, 1);
		(vars.h)++;
        free(line);
    }
	make_map(&vars, m_line);
	check_valid(&vars);
	render_map(&vars);
	// printf("map_line: %s, \n map_w: %d, map_h: %d", map_l, map_w, map_h);
	close(fd);
    // system("leaks a.out");
    return (0);
}