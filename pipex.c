/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:43:39 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/10/14 21:21:55 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_exit(char *str, int code)
{
	perror(str);
	exit(code);
}

void	ft_file_open(char *filename1, char *filename2, int *file1, int *file2)
{
	*file1 = open(filename1, O_RDONLY);
	*file2 = open(filename2, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (*file1 < 0)
		ft_exit(filename1, 1);
	if (*file2 < 0)
		ft_exit(filename2, 1);
}

void	make_exec(char *av, char **envp)
{
	char	**cmd;
	char	*real_path;

	cmd = ft_search_cmd(av);
	real_path = 0;
	if (cmd)
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
		ft_exit("fork_error", 1);
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

	if (ac != 5)
	{
		write(2, "argument should be 4", 21);
		return (1);
	}
	ft_file_open(av[1], av[4], &file1, &file2);
	dup2(file1, 0);
	dup2(file2, 1);
	close(file1);
	close(file2);
	make_fork(av[2], envp);
	make_exec(av[3], envp);
	return (0);
}
