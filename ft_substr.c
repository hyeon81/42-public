#include "libft.h"

int	ft_strlen2(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i;
    char *str;

    // if (!s)
    //     return 0;
    if (start >= (unsigned int)ft_strlen2((char *)s))
    {
        str = (char *)malloc(1);
        str[0] = '\0';
        return (str);
    }
    str = (char *)malloc(len + 1);
    if (!str)
        return 0;
    i = 0;
    while ((s[start] != 0) && (i < len))
    {
        str[i] = s[start];
        i++;
        start++;
    }
    str[i] = '\0';
    return (str);
}


// int main ()
// {
//     printf("%s", ft_substr("abcdef", 8, 3));
// }