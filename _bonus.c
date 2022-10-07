

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
	while (i < ac - 2)
	{
		cmd = ft_search_cmd(av[i]);
		real_path = ft_search_path(envp, cmd[0]);
		//명령어가 없는 명령어일 경우(이건 exec에서?)
		if (real_path == 0)
		{
			write(2, "invalid cmd", 12);
			return (1);
		}
		// printf("\ncmd: %s, real_path: %s\n\n", cmd[1], real_path);
		make_fork(real_path, cmd, envp);
		i++;
	}
	cmd = ft_search_cmd(av[i]);
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
