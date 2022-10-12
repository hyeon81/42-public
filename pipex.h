/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:48:30 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/10/12 17:54:38 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

size_t	ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_double_strlen(char **str);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_search_path(char **envp, char *first_cmd);
char	**ft_search_cmd(char *av);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_free(char **s1, char **s2);
int		ft_exit(char *str, int code);
void	exec_here_doc(int ac, char **av, char **envp);
int		make_fork(char *av, char **envp);
void	make_exec(char *av, char **envp);
void	ft_file_open(char *filename1, char *filename2, int *file1, int *file2);

#endif 