#include <string.h>
#include <stdio.h>

char *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i] != 0)
    {
        if (s[i] == c)
            return ((char *)&s[i]);
        i++;
    }
    //c가 null일때?
    if (s[i] == c)
        return ((char *)&s[i]);
    return (0);
}

// int main ()
// {
//     char s[] = "1234567";
//     printf("%s", strchr(s, '0'));
// }