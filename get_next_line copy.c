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

// #include <stdlib.h>
// #include <unistd.h>
// #include <stdio.h>

// int	ft_strlen(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != 0)
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*str;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	str = (char *)malloc(sizeof(char) * 
// 	(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
// 	if (!str)
// 		return (0);
// 	while (s1[i] != 0)
// 	{
// 		str[j] = s1[i];
// 		j++;
// 		i++;
// 	}
// 	i = 0;
// 	while (s2[i] != 0)
// 	{
// 		str[j] = s2[i];
// 		j++;
// 		i++;
// 	}
// 	str[j] = '\0';
// 	return (str);
// }

// char	*ft_strdup_line(const char *s1, int start, int end)
// {
// 	char	*arr;
// 	int	i = 0;

// 	arr = (char *)malloc(sizeof(char) * (start - end + 1));
// 	if (!arr)
// 		return (0);
// 	while ((s1[start] != 0) && (start <= end))
// 	{
// 		arr[i] = s1[start];
// 		start++;
// 		i++;
// 	}
// 	arr[i] = '\0';
// 	return (arr);
// }

// int	ft_strchr(const char s[], int c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != 0)
// 	{
// 		if (s[i] == c)
// 			return (i);
// 		i++;
// 	}
// 	return (0);
// }

// char *ft_return_last(char *backup)
// {
// 	char *tmp;

// 	if (backup == 0)
// 	{
// 		tmp = ft_strdup_line("", 1, 1);
// 		return (0);
// 	}
// 	tmp = ft_strdup_line(backup, 0, ft_strlen(backup) + 1);
// 	// free(backup);
// 	// backup = 0;
// 	return (tmp);
// }

// char *get_next_line(int fd)
// {
// 	char buf[BUFFER_SIZE + 10];
// 	static char *backup;
// 	char *line; 
// 	int line_size;
// 	int line_idx;

// 	if ((fd < 0) || (BUFFER_SIZE <= 0))
// 	{
// 		puts("\nstep0\n");
// 		return (0);
// 	}
// 	backup = ft_strdup_line("", 0, 1);
// 	puts("\nstep1\n");
// 	if (read(fd, buf, BUFFER_SIZE) > 0)
// 	{
// 		puts("\nstep2\n");
// 		line_size = read(fd, buf, BUFFER_SIZE);
// 		printf("\nline_size: %d\n", line_size);
// 		buf[line_size] = 0;
// 		printf("\nbuf: %s\n", buf);
// 		backup = ft_strjoin(backup, buf);
// 		printf("\nbackup: %s\n", backup);
// 		if (!backup)
// 			return (0);
// 		line_idx = ft_strchr(backup, '\n');
// 		printf("\nline_idx: %d\n", line_idx);
// 		if (line_idx >= 0)
// 		{
// 			line = ft_strdup_line(backup, 0, line_idx);
// 			backup = ft_strdup_line(backup, line_idx, ft_strlen(backup));
// 			return (line);
// 		}
// 	}
// 	if (read(fd, buf, BUFFER_SIZE) < 0)
// 		return (0);
// 	if (read(fd, buf, BUFFER_SIZE) == 0)
// 	{
// 		puts("\nstep3\n");
// 		return(ft_return_last(backup));
// 	}

// 	return (0);
// }
