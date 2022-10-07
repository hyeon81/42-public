#include <stdio.h>
#include "pipex.h"
# include <sys/wait.h>
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
	char *temp_path;
	char **splited_path;

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
	splited_path = ft_split(origin_path, ':');

	//명령어 열기
	temp_path = ft_strjoin("/", first_cmd);
	i = 0;
	int path_count = ft_double_strlen(splited_path);
	while (i < path_count)
	{
		if (access(ft_strjoin(splited_path[i], temp_path), F_OK) == 0)
			return (ft_strjoin(splited_path[i], temp_path));
		i++;
	}
	return(0);
}

int make_fork(char *real_path, char **cmd, char **envp)
{
	char *res;
	pid_t pid;
	int fd[2];


	if (pipe(fd) == -1)
	{
		write(2, "run error\n", 11);
		return (1);
	}

	res = malloc(1000);
	ft_memset(res, 0, 1000);
	//파이프 생성
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
		close(fd[1]);
		close(fd[0]);
		execve(real_path, cmd, envp);
	}
	if (pid > 0)
	{
		//부모 프로세서가 처리
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid, NULL, 0);

	}
	return (0);
}

int main(int ac, char **av, char **envp)
{
	char **cmd;
	char *real_path;
	int file1;
	int file2;	
	int i;

	//ac가 3개 이상이야 파일 생성 가능
	if (ac < 4)
	{
		write(2, "argument should be four", 24);
		return (1);
	}

	//파일이 존재하는지 확인
	if (access(av[1], R_OK) != 0)
	{
		write(2, "the file is wrong", 24);
		return (1);
	}

	//파일 오픈
	file1 = open(av[1], O_RDONLY);
	file2 = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (file1 < 0 || file2 < 0)
	{
		write(2, "fd error\n", 11);
		return (1);
	}

	dup2(file1, 0);
	dup2(file2, 1);
	i = 2;

	cmd = ft_search_cmd(av[2]);
	real_path = ft_search_path(envp, cmd[0]);
	//명령어가 없는 명령어일 경우(이건 exec에서?)
	if (real_path == 0)
	{
		write(2, "invalid cmd", 12);
		return (1);
	}
	make_fork(real_path, cmd, envp);
	}
	cmd = ft_search_cmd(av[3]);
	real_path = ft_search_path(envp, cmd[0]);
	if (real_path == 0)
	{
		write(2, "invalid cmd", 12);
		return (1);
	}
	execve(real_path, cmd, envp);
	close(file1);
	close(file2);
	return (0);
}
