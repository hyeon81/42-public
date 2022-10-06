#include <stdio.h>
#include "pipex.h"
// #include <errno.h>
// #include <string.h>

char **ft_search_cmd(char *av)
{
	char **cmd;

	cmd = ft_split(av, ' ');
	return (cmd);
}

char *ft_search_path(char **envp, char *first_cmd)
{
	int i = 0;
	char *origin_path;
	//path 찾기
	while (envp[i] != 0)
	{
		if (ft_strstr(envp[i], "PATH=") != 0)
		{
			origin_path = envp[i];
			break;
		}
		i++;
	}

	//path 나누기
	char **splited_path;
	splited_path = ft_split(origin_path, ':');

	//명령어 열기
	char *real_path; //진짜 path가 담김
	char *temp_path;

	real_path = 0;
	temp_path = ft_strjoin("/", first_cmd);
	i = 0;
	int path_count = ft_double_strlen(splited_path);
	while (i < path_count)
	{
		if (access(ft_strjoin(splited_path[i], temp_path), F_OK) == 0)
		{
			real_path = ft_strjoin(splited_path[i], temp_path);
			break;
		}
		i++;
	}
	return(real_path);
}

int make_fork(int *fd, char *real_path, char **cmd, char **envp, int outfile_fd)
{
	char *res;
	int stat;
	res = malloc(1000);
	ft_memset(res, 0, 1000);
	
	pid_t pid;
	pid = fork();

	// 에러 처리
	if (pid < 0)
	{
		write(2, "run error\n", 11);
		return (1);
	}
	if (pid == 0) //자식 프로세서가 처리
	{
		dup2(fd[1], 1);
		close(fd[0]);
		execve(real_path, cmd, envp);
	}
	wait(&stat);
	if (pid > 0)
	{
		//부모 프로세서가 처리
		dup2(outfile_fd, 0);
		close(fd[1]);
	}
	return (0);
}

int main(int ac, char **av, char **envp)
{
	char **cmd;
	char *real_path;
	char *res;
	int fd[2];
	int file1;
	int file2;	
	int i;

	//res 초기화
	res = malloc(1000);
	ft_memset(res, 0, 1000);

	//파일 오픈
	file1 = open(av[1], O_RDONLY);
	file2 = open(av[ac - 1], O_RDONLY);
	if (file1 < 0 || file2 < 0)
	{
		write(2, "fd error\n", 11);
		return (1);
	}

	//파이프 생성
	if (pipe(fd) == -1)
	{
		write(2, "run error\n", 11);
		return (1);
	}
	dup2(file1, 0);
	i = 0;
	/*while (i < ac - 3)
	{
		cmd = ft_search_cmd(av[i + 2]);
		real_path = ft_search_path(envp, cmd[0]);
		// printf("\ncmd: %s, real_path: %s\n\n", cmd[1], real_path);
		make_fork(fd, real_path, cmd, envp, file2);
		i++;
	}*/
	while (i < 2)
	{
		cmd = ft_search_cmd(av[i + 2]);
		real_path = ft_search_path(envp, cmd[0]);
		// printf("\ncmd: %s, real_path: %s\n\n", cmd[1], real_path);
		make_fork(fd, real_path, cmd, envp, file2);
		i++;
	}
	close(file1);
	close(file2);
	return (0);
}
