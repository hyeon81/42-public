/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:43:39 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/10/12 21:18:37 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_exit(char *str, int code)
{
	perror(str);
	exit(code);
}

void	ft_putstr_err(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return ;
	i = 0;
	while (s1[i] != 0)
	{
		write(2, &s1[i], 1);
		i++;
	}
	i = 0;
	while (s2[i] != 0)
	{
		write(2, &s2[i], 1);
		i++;
	}
}

void	make_exec(char *av, char **envp)
{
	char	**cmd;
	char	*real_path;

	cmd = ft_search_cmd(av);
	real_path = ft_search_path(envp, cmd[0]);
	if (real_path == 0)
	{
		ft_putstr_err(cmd[0], ": command not found\n");
		ft_free(cmd, 0);
		exit(127);
	}
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

int	main(int ac, char **av, char **envp)
{
	int	file1;
	int	file2;
	int	i;

	if (ac < 5)
	{
		write(2, "argument should be at least 4", 30);
		return (1);
	}
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		exec_here_doc(ac, av, envp);
		return (0);
	}
	ft_file_open(av[1], av[ac - 1], &file1, &file2);
	dup2(file1, 0);
	dup2(file2, 1);
	close(file1);
	close(file2);
	i = 1;
	while (++i <= ac - 3)
		make_fork(av[i], envp);
	make_exec(av[ac - 2], envp);
	return (0);
}
