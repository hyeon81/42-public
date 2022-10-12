/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:46:27 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/10/12 21:46:54 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_search_cmd(char *av)
{
	char	**cmd;

	cmd = ft_split(av, ' ');
	return (cmd);
}

char	**search_origin_path(char **envp)
{
	int		i;
	char	*origin_path;

	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			origin_path = envp[i] + 5;
			return (ft_split(origin_path, ':'));
		}
		i++;
	}
	return (0);
}

char	*ft_search_path(char **envp, char *first_cmd)
{
	int		i;
	int		path_count;
	char	*temp_path;
	char	**splited_path;
	char	*cmd_path;

	if (access(first_cmd, F_OK) == 0)
		return (first_cmd);
	splited_path = search_origin_path(envp);
	path_count = ft_double_strlen(splited_path);
	temp_path = ft_strjoin("/", first_cmd);
	i = 0;
	while (i < path_count)
	{
		cmd_path = ft_strjoin(splited_path[i], temp_path);
		if (access(cmd_path, F_OK) == 0)
			break ;
		else
			ft_free(0, &cmd_path);
		i++;
	}
	ft_free(splited_path, 0);
	ft_free(0, &temp_path);
	return (cmd_path);
}

void	ft_file_open(char *filename1, char *filename2, int *file1, int *file2)
{
	*file1 = open(filename1, O_RDONLY);
	if (ft_strncmp(filename1, "here_doc.tmp", 12) == 0)
		*file2 = open(filename2, O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		*file2 = open(filename2, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (*file1 < 0)
		ft_exit(filename1, 1);
	if (*file2 < 0)
		ft_exit(filename2, 1);
}
