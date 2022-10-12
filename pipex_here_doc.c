/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:36:19 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/10/12 21:16:24 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "get_next_line.h"

int	make_here_doc(char *LIMITER)
{
	int		file;
	char	*line;

	file = open("here_doc.tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		line = get_next_line2(0);
		if (ft_strncmp(line, LIMITER, 7) == 0)
		{
			free(line);
			close(file);
			return (1);
		}
		write(file, line, ft_strlen(line));
		free(line);
	}
}

void	exec_here_doc(int ac, char **av, char **envp)
{
	int	file1;
	int	file2;

	if (ac != 6)
	{
		write(2, "argument should be 5", 21);
		exit(1);
	}
	make_here_doc(av[2]);
	ft_file_open("here_doc.tmp", av[5], &file1, &file2);
	dup2(file1, 0);
	dup2(file2, 1);
	close(file2);
	close(file1);
	unlink("here_doc.tmp");
	make_fork(av[3], envp);
	make_exec(av[4], envp);
}
