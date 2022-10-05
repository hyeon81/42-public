#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>

char	*ft_strstr(const char *haystack, const char *needle);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

#endif 