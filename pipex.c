#include <stdio.h>
#include "pipex.h"

size_t	ft_double_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int main(int ac, char **av, char **envp)
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

	//명령어 나누기 (2번째 인수만)
	char **av_cmd;
	av_cmd = ft_split(av[2], ' ');

	//명령어 열기
	char *real_path; //진짜 path가 담김
	char *temp_path;

	real_path = 0;
	temp_path = ft_strjoin("/", av_cmd[0]);
	printf("av_cmd[0]: %s\n", av_cmd[0]);
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

	//file1 오픈
	int infile;
	infile = open(av[1], O_RDONLY);
	//--어떻게 읽어서 보내지?

	//명령어를 가지고 다음 파이프로 이동(stdout을 stdin으로?)
	int fd1[2];
	if (pipe(fd1) == -1)
		// 에러 처리
	pid_t pid = fork();
	if (pid == -1)
		// 에러 처리
	if (pid == 0)
	{
		dup2(fd1[1], 1);
		close(fd1[0]);
		// int res = execve()?
	}
	dup2(fd1[0], 0);
	close(fd1[1]);
	// ...?

	//명령어가 맞다면? execve로 실행
	// printf("real_path = %s, av_cmd = %s\n", real_path, av_cmd[0]);
	execve(real_path, av_cmd, envp);
	printf("execve failed to run ls\n");

	// char *arg[] = {"bin/ls", (char *)0};
	// printf("Running ls with execve\n");
	// access(”bin/av[2]”, F_OK)
	// execve("/bin/ls", arg, envp);
	// printf("execve failed to run ls\n");
}
