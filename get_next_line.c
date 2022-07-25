// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   get_next_line.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/07/23 12:58:38 by hyeokim2          #+#    #+#             */
// /*   Updated: 2022/07/23 16:57:00 by hyeokim2         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*arr;

	i = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	while (s1[i] != '\0')
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == 0)
		s1 = ft_strdup("");
	if (s2 == 0)
		s2 = ft_strdup("");
	str = (char *)malloc(sizeof(char) * 
	(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (!str)
		return (0);
	while (s1[i] != 0)
	{
		str[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i] != 0)
	{
		str[j] = s2[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_split_line(const char *s1, int start, int end)
{
	char	*arr;
	int	i = 0;

	arr = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!arr)
		return (0);
	while ((s1[start] != 0) && (start <= end))
	{
		arr[i] = s1[start]; //backup[1]은 아무것도 없음
		start++;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char *ft_return_last(char *backup, char* buf, int line_size)
{
	if (backup[0] == '\0')
		return (0);
	buf[line_size] = '\0';
	backup = ft_strjoin(backup, buf);
	return (backup);
}

#include <stdio.h>

char *get_next_line(int fd)
{
	char buf[BUFFER_SIZE + 1];
	static char *backup;
	char *line; 
	int line_size;
	int newline_idx;

	if (((fd < 0) || (fd > 256)) || (BUFFER_SIZE <= 0))
		return (0);
	if (!backup)
		backup = ft_strdup(""); 
	while ((line_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[line_size] = '\0';
		backup = ft_strjoin(backup, buf);
		if ((newline_idx = ft_strchr(backup, '\n')) >= 0)
		{
			line = ft_split_line(backup, 0, newline_idx);
			backup = ft_split_line(backup, newline_idx + 1, ft_strlen(backup));
			// printf("make line\n");
			return (line);
		}
	}
	if (line_size == 0)
	{
		line = ft_return_last(backup, buf, line_size);
		// printf("make last line\n");
		free(backup);
		backup = 0;
		return (line);
	}
	free(backup);
	// printf("make finish\n");
	backup = 0;
	return (0);
}
