#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *str;
    int i;

    i = 0;
    while (s[i] != 0)
        i++;
    str = (char *)malloc(sizeof(char) * (i + 1));
    if (!str)
        return 0;
    i = 0;
    while (s[i] != 0)
    {
        str[i] = f(i, s[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}

// int main ()
// {
//     printf("%s", ft_strmapi("abcdefg", ft_add_one));
// }
