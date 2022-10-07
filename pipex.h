#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_strstr(const char *haystack, const char *needle);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_double_strlen(char **str);
void	*ft_memset(void *b, int c, size_t len);
int     make_fork(char *real_path, char **cmd, char **envp);
char    *ft_search_path(char **envp, char *first_cmd);
char    **ft_search_cmd(char *av);

#endif 