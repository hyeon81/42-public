#include <unistd.h>

// void ft_putchar (unsigned int n, char *str)
// {
//     write(1, &str[n], 1);
// }

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    int i = 0;
    while (s[i] != 0)
    {
        f(i, &s[i]);
        i++;
    }
}

// int main ()
// {
//     ft_striteri("abcdefg", ft_putchar);
// }
