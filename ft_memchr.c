#include <stdio.h>
#include <string.h>

void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    unsigned char* uc;

    uc = (unsigned char*)s;
    i = 0;
    while (i < n)
    {
        if (uc[i] == (unsigned char)c)
            return (&uc[i]);
        i++;
        
    }
    return (0);
}

// int main()
// {
//     char *str = "12345678";
//     printf("%s : %s\n", memchr(str, '2', 4), ft_memchr(str, '2', 4));
//     printf("%s : %s\n", memchr(str, 'a', 4), ft_memchr(str, 'a', 4));
//     printf("%s : %s\n", memchr(str, '8', 4), ft_memchr(str, '8', 4));
//     printf("%s : %s\n", memchr(str, '8', 12), ft_memchr(str, '8', 12));
// }