#include <stdio.h>
#include <unistd.h>
char	*ft_strstr(const char *haystack, const char *needle);
size_t	ft_strlen(const char *str);

int main(int ac, char **av, char **envp)
{
	int i = 0;
	char *path;
	//path 찾기
	while (envp[i] != 0)
	{
		if (ft_strstr(envp[i], "PATH") != 0)
			path = envp[i];
		i++;
	}
	printf("path: %s", path);

	//명령어 나누기
	char *av_path;
	av_path = av[2];


	// char *arg[] = {"bin/ls", (char *)0};
	// printf("Running ls with execve\n");
	// access(”bin/av[2]”, F_OK)
	// execve("/bin/ls", arg, envp);
	// printf("execve failed to run ls\n");
}
