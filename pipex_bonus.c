/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:43:39 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/10/11 22:04:20 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_exit(char *str, int code)
{
	perror(str);
	exit(code);
}

void	make_exec(char *av, char **envp)
{
	char	**cmd;
	char	*real_path;

	cmd = ft_search_cmd(av);
	real_path = ft_search_path(envp, cmd[0]);
	if (real_path == 0)
		ft_exit("command", 127);
	execve(real_path, cmd, envp);
}

int	make_fork(char *av, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_exit("pipe_error", 1);
	pid = fork();
	if (pid < 0)
		ft_exit("pipe_error", 1);
	if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[1]);
		close(fd[0]);
		make_exec(av, envp);
	}
	if (pid > 0)
	{
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid, NULL, WNOHANG);
	}
	return (0);
}

void	make_here_doc()
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_exit("pipe_error", 1);
	pid = fork();
	if (pid < 0)
		ft_exit("pipe_error", 1);
	if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[1]);
		close(fd[0]);
	}
	if (pid > 0)
	{
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid, NULL, WNOHANG);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	file1;
	int	file2;
	int	i;

	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		file2 = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
		make_here_doc();
		make_exec(av[ac - 2], envp);
		return (0);
	}
	check_argv(ac, av, &file1, &file2);
	file1 = open(av[1], O_RDONLY);
	file2 = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (file1 < 0 || file2 < 0)
	{
		perror("file");
		return (1);
	}
	dup2(file1, 0);
	dup2(file2, 1);
	close(file1);
	close(file2);
	i = 2;
	while (i <= ac - 3)
	{
		make_fork(av[i], envp);
		i++;
	}
	make_exec(av[ac - 2], envp);
	return (0);
}
