/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:58:38 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/23 16:57:00 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	int i;
	int j;

	i = 0;
	j = 0;
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


int ft_strchr(const char s[], int c)
{
	int i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char *ft_return_last(char *backup)
{
	char *tmp;

	if (backup == 0)
	{
		tmp = ft_strdup_line("", 1, 1);
		return (0);
	}
	tmp = ft_strdup_line(backup, 0, ft_strlen(backup) + 1);
	// free(backup);
	// backup = 0;
	return (tmp);
}

char *get_next_line(int fd)
{
	char buf[BUFFER_SIZE + 1];
	static char *backup;
	char *line;
	int line_size;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (0);

	backup = ft_strdup("");
	
}
