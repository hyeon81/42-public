/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:36:19 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/10/14 21:43:34 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "get_next_line.h"

int	read_line(char *limiter, int infile)
{
	char	*line;

	while (1)
	{
		line = get_next_line2(0);
		if (ft_strncmp(line, limiter, 7) == 0)
		{
			free(line);
			return (0);
		}
		write(infile, line, ft_strlen(line));
		free(line);
	}
}

int	make_here_doc(char *limiter)
{
	int		tmp_file;
	char	*tmp_name;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		ft_exit("fork_error", 1);
	tmp_name = ft_strjoin(limiter, "_here_doc.tmp", 0, 0);
	tmp_file = open(tmp_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pid == 0)
	{
		read_line(limiter, tmp_file);
		exit(0);
	}
	if (pid > 0)
	{
		wait(NULL);
		close(tmp_file);
		tmp_file = open(tmp_name, O_RDONLY);
		dup2(tmp_file, 0);
		close(tmp_file);
		unlink(tmp_name);
		free(tmp_name);
	}
	return (0);
}

void	exec_here_doc(int ac, char **av, char **envp)
{
	int	outfile;

	if (ac != 6)
	{
		write(2, "argument should be 5", 21);
		exit(1);
	}
	make_here_doc(av[2]);
	outfile = open(av[5], O_RDWR | O_CREAT | O_APPEND, 0644);
	dup2(outfile, 1);
	close(outfile);
	make_fork(av[3], envp);
	make_exec(av[4], envp);
	exit(0);
}
