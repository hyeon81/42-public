#include <stdio.h>
#include <pipex.h>

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
	printf("path: %s", path);

	//path 나누기
	char **splited_path;
	splited_path = ft_split(origin_path, ':');

	//명령어 나누기 (2번째 인수만)
	char **av_path;
	av_path = ft_split(av[2], ' ');

	//명령어 맞는지 확인
	char *real_path;
	real_path = ft_strjoin(av_path, "/")
	i = 0;
	int path_count = ft_strlen(splited_path);
	while (i < path_count)
	{
		if (ft_strjoin(av_path[0], splited_path[i])

	}


	// char *arg[] = {"bin/ls", (char *)0};
	// printf("Running ls with execve\n");
	// access(”bin/av[2]”, F_OK)
	// execve("/bin/ls", arg, envp);
	// printf("execve failed to run ls\n");
}
