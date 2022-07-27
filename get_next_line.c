/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:56:30 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/27 21:08:32 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **s1, char **s2, int flag)
{
	free(*s1);
	if (flag == 1)
		*s1 = *s2;
	else
		*s1 = 0;
}

char	*ft_split_line(const char *s1, int start, int end)
{
	char	*arr;
	int		i;

	i = 0;
	arr = (char *)malloc(sizeof(char) * (end - start + 1));
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

char	*ft_return_last(char **backup)
{
	char	*temp;
	char	*line;
	int		newline_idx;

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

char	*ft_make_line(char **backup, char *buf)
{
	char	*temp;
	char	*line;
	int		newline_idx;

	temp = ft_strjoin(*backup, buf);
	ft_free(backup, &temp, 1);
	if (ft_strchr(*backup, '\n') >= 0)
	{	
		newline_idx = ft_strchr(*backup, '\n');
		line = ft_split_line(*backup, 0, newline_idx);
		temp = ft_split_line(*backup, newline_idx + 1, ft_strlen(*backup));
		ft_free(backup, &temp, 1);
		return (line);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*backup;
	int			line_idx;
	char		*line;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || (fd > 256))
		return (0);
	if (!backup)
		backup = ft_strdup("");
	line_idx = read(fd, buf, BUFFER_SIZE);
	while (line_idx > 0)
	{
		buf[line_idx] = '\0';
		line = ft_make_line(&backup, buf);
		if (!(line == 0))
			return (line);
		line_idx = read(fd, buf, BUFFER_SIZE);
	}
	return (ft_return_last(&backup));
}
