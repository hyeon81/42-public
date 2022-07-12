#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
    int i;
    i = 0;

    if (fd < 0)
        return ;

    while (s[i] != 0)
    {
        write(fd, &s[i], 1);
        i++;
    }
    write(fd, "\n", 1);
}

// int main ()
// {
//     ft_putendl_fd("abcded", 1);
// }