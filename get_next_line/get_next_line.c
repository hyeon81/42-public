/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:55:54 by eunjiko           #+#    #+#             */
/*   Updated: 2022/11/28 19:22:41 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(char *line)
{
	ssize_t	idx;	

	idx = 0;
	while (line[idx])
	{
		if (line[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

char	*get_line(char	**backup)
{
	ssize_t	backuplen;
	ssize_t	nlidx;
	char	*tmp;
	char	*line;

	backuplen = ft_strlen(*backup);
	nlidx = find_newline(*backup);
	if (nlidx >= 0)
	{
		line = ft_substr(*backup, 0, nlidx + 1);
		tmp = *backup;
		*backup = ft_substr(*backup, nlidx + 1, backuplen - (nlidx + 1));
		free(tmp);
		return (line);
	}
	else
	{
		line = ft_substr(*backup, 0, backuplen);
		free(*backup);
		*backup = NULL;
		return (line);
	}
	return (NULL);
}

ssize_t	read_file(ssize_t rsize, char *buf, char **backup, int fd)
{
	char	*tmp;
	ssize_t	nlidx;

	while (rsize > 0)
	{
		buf[rsize] = '\0';
		if (*backup == NULL)
			*backup = ft_strdup("");
		tmp = *backup;
		*backup = ft_strjoin(*backup, buf);
		free(tmp);
		nlidx = find_newline(buf);
		if (nlidx >= 0)
			break ;
		rsize = read(fd, buf, BUFFER_SIZE);
	}
	return (rsize);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf;
	ssize_t		rsize;

	if (BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	rsize = read(fd, buf, BUFFER_SIZE);
	rsize = read_file(rsize, buf, &backup, fd);
	free(buf);
	if (rsize < 0)
	{
		if (backup)
			free(backup);
		return (NULL);
	}
	if (!backup)
		return (NULL);
	return (get_line(&backup));
}
